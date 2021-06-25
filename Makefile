# These flags are to be used for all complitations and linkings
# -Wall : show all warnings
# -Werror : treat warnings as errors
# -g : include debugging symbols
CXXFLAGS := -std=c++11 -Wall -Werror -g
CXX := g++

all: tester

unittest: tester
	-valgrind -v --leak-check=full --track-fds=yes --log-file=valgrind.log ./tester
	cat valgrind.log

#
# $@ : the target
# $^ : all dependencies
# $< : first dependency
#
tester: tester.o strand.o sequence.o
	$(CXX) $(CXXFLAGS) -o $@ $^

tester.o: tester.cpp strand.h sequence.h
	$(CXX) $(CXXFLAGS) -c $<

strand.o: strand.cpp strand.h
	$(CXX) $(CXXFLAGS) -c $<

sequence.o: sequence.cpp sequence.h
	$(CXX) $(CXXFLAGS) -c $<



clean:
	-rm -f *.o tester *~ valgrind.log
