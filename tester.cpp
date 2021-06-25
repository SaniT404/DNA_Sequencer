#include <iostream>
#include <cstring>
#include <vector>
#include "strand.h"
#include "sequence.h"

void test_default_constructor()
{
    Strand teststrand;
    char *strand = teststrand.getStrand();
    std::cout << "-------------------------------------------------------------" << std::endl;
    std::cout << "Testing default constructor: " << std::endl;
    if(strand != 0)
    {
        std::cout << "Default constructor failed.  Strand[0] is " << std::endl;
        std::cout << "-------------------------------------------------------------" << std::endl;
    }
    else
    {
        std::cout << "Default constructor passed.  Strand[0] is _" << "_" << std::endl;
        std::cout << "-------------------------------------------------------------" << std::endl;
    }
}

void test_nondefault_constructor()
{


    char str[4] = {'B', 'o', 'b', 0};
    Strand teststrand(str);
    char *strand = teststrand.getStrand();
    std::cout << "Testing non-default constructor: " << std::endl;
    std::cout << strand[0] << strand[1] << strand[2] << strand[3] << std::endl;
    std::cout << "Non-Default constructor passed.  Strand is " << strand << std::endl;
    std::cout << "-------------------------------------------------------------" << std::endl;
}
void test_copy_constructor()
{
    char str[4] = {'B', 'o', 'b', 0};
    Strand newstrand(str);
    Strand teststrand = newstrand;
    char *strand = teststrand.getStrand();
    std::cout << "Testing copy constructor: " << std::endl;
    std::cout << strand[0] << strand[1] << strand[2] << strand[3] << std::endl;
    std::cout << "Copy constructor passed.  Strand is " << strand << std::endl;
    std::cout << "-------------------------------------------------------------" << std::endl;
}

void test_size()
{
    char str[4] = {'B', 'o', 'b', 0};
    Strand teststrand(str);
    std::cout << "Strand length: " << teststrand.size() << std::endl;
    std::cout << "-------------------------------------------------------------" << std::endl;
}

void test_substrand()
{
    char str[9] = {'B', 'o', 'b', 'b', 'y', ' ', 'k', '.', 0};
    Strand teststrand(str);
    Strand copystrand = teststrand.substrand(1, 3);
    std::cout << "If strand = 'Bob', then substrand() passed." << std::endl;
    std::cout << copystrand.getStrand() << std::endl;
    std::cout << "-------------------------------------------------------------" << std::endl;
}

void test_merge()
{
    std::cout << "Testing Merge:" << std::endl;
    char str[] = "Hello world!";
    char strr[] = "ld";
    Strand testone(str);
    Strand testtwo(strr);
    Strand result = testone.merge(7, testtwo);
    std::cout << result.getStrand() << std::endl;
    std::cout << "-------------------------------------------------------------" << std::endl;

}

void test_overlap()
{
    std::cout << "Testing Overlap: abcdefghijklmnop and hijklmnopqrstuvwx" << std::endl;
    char str[] = "abcdefghijklmnop";
    char strr[] = "hijklmnopqrstuvwx";
    Strand testone(str);
    Strand testtwo(strr);
    size_t overlap = testone.overlap(testtwo);
    std::cout << overlap << std::endl;
    std::cout << "Testing Overlap: abcdefghijklmnop and xyz" << std::endl;
    char strrr[] = "abcdefghijklmnop";
    char strrrr[] = "xyz";
    Strand testthree(strrr);
    Strand testfour(strrrr);
    overlap = testthree.overlap(testfour);
    std::cout << overlap << std::endl;
    std::cout << "-------------------------------------------------------------" << std::endl;
}

void test_operator_plus()
{
    std::cout << "Testing plus operator: " << std::endl;
    char str[4] = {'B', 'o', 'b', 0};
    char strr[4] = {'D', 'i', 'l', 0};
    Strand testone(str);
    Strand testtwo(strr);
    Strand result = testone + testtwo;
    std::cout << result.getStrand() << std::endl;
    std::cout << "-------------------------------------------------------------" << std::endl;
}
void test_operator_plusequals()
{
    std::cout << "Testing plus equals operator: " << std::endl;
    char str[4] = {'B', 'o', 'b', 0};
    char strr[4] = {'D', 'i', 'l', 0};
    Strand testone(str);
    Strand testtwo(strr);
    testone += testtwo;
    std::cout << testone.getStrand() << std::endl;
    std::cout << "-------------------------------------------------------------" << std::endl;
}

void test_operator_isequal()
{
    char str[4] = {'B', 'o', 'b', 0};
    Strand testone(str);
    Strand testtwo(str);
    if(testone == testtwo)
    {
        std::cout << "IsEqual operator passed." << std::endl;
        std::cout << "-------------------------------------------------------------" << std::endl;
    }
    else
    {
        std::cout << "IsEqual operator failed." << std::endl;
        std::cout << "-------------------------------------------------------------" << std::endl;
    }
}
void test_operator_islessthan()
{
    char str[4] = {'B', 'o', 'b', 0};
    char strr[4] = {'B', 'a', 'b', 0};
    Strand testone(str);
    Strand testtwo(strr);
    if(testone < testtwo)
    {
        std::cout << "IsLessThan operator passed." << std::endl;
        std::cout << "-------------------------------------------------------------" << std::endl;
    }
    else
    {
        std::cout << "IsLessThan operator failed." << std::endl;
        std::cout << "-------------------------------------------------------------" << std::endl;
    }
}

void test_sequence()
{
    std::cout << "Testing sequencer: " << std::endl;
    char strandone[] = "testi";  Strand strndone(strandone);
    char strandtwo[] = "sting one tw";  Strand strndtwo(strandtwo);
    char strandthree[] = "esting on";  Strand strndthree(strandthree);
    char strandfour[] = "e two th";  Strand strndfour(strandfour);
    char strandfive[] = " three four";  Strand strndfive(strandfive);
    char strandsix[] = "ree four five six";  Strand strndsix(strandsix);
    std::vector<Strand> mystrands;
    mystrands.push_back(strndone);
    mystrands.push_back(strndtwo);
    mystrands.push_back(strndthree);
    mystrands.push_back(strndfour);
    mystrands.push_back(strndfive);
    mystrands.push_back(strndsix);
    mystrands = sequence(mystrands, 2);

    std::cout << mystrands[0].getStrand() << std::endl;
    std::cout << "-------------------------------------------------------------" << std::endl;
}


int main()
{
    test_default_constructor();
    test_nondefault_constructor();
    test_copy_constructor();
    test_size();
    test_substrand();
    test_merge();
    test_overlap();
    test_operator_plus();
    test_operator_plusequals();
    test_operator_isequal();
    test_operator_islessthan();
    test_sequence();
    return 0;
}
