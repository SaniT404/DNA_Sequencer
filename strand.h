#ifndef __STRAND_H__
#define __STRAND_H__

#include <cstdlib>

class Strand
{
public:
    Strand();
    Strand(const char *src);
    Strand(const Strand &obj);
    virtual ~Strand();
    Strand& operator=(const Strand &rhs);
    Strand operator+=(const Strand rhs);
    Strand operator+(const Strand &rhs);
    bool operator==(const Strand& rhs) const;
    bool operator<(const Strand& rhs) const;

    size_t size() const;
    Strand substrand(size_t i, size_t j) const;
    Strand merge(size_t i, const Strand &right) const;
    size_t overlap(const Strand &right) const;

    //getter methods
    char *getStrand() const;
    size_t getSize() const;

    //setter methods
    void setStrand(const char *src);
protected:
    char *m_Strand;
    size_t m_Size;
};

#endif
