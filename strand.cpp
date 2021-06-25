#include <iostream>
#include <cstdlib>
#include <string.h>
#include "strand.h"

//CONSTRUCTORS and DESTRUCTORS-------------------------------------------------

Strand::Strand()
    : m_Strand(0), m_Size(0)
{
    //empty
}
Strand::Strand(const char *src)
    : m_Strand(0), m_Size(0)
{
    this->setStrand(src);
}
Strand::Strand(const Strand &obj)
    : m_Strand(0), m_Size(0)
{
    *this = obj;
}

Strand::~Strand()
{
    if(m_Strand)
    {
        delete [] m_Strand;
        m_Strand = 0;
    }
}


//OPERATOR OVERLOADING---------------------------------------------------------

Strand& Strand::operator=(const Strand &rhs)
{
    this->setStrand(rhs.getStrand());
    return *this;
}

Strand Strand::operator+(const Strand &rhs)
{
    *this += rhs;
    return *this;
}
/*
Strand Strand::operator-(const Strand &rhs)
{
    *this -= rhs;
    return *this;
}
*/
Strand Strand::operator+=(const Strand rhs)
{
    char *temp = new char [this->m_Size + rhs.m_Size + 1];
    strcpy(temp, this->m_Strand);
    strcat(temp, rhs.getStrand());
    this->setStrand(temp);
    delete [] temp;
    return *this;
}
/*
Strand Strand::operator-=(const Strand rhs)
{
    char *temp = new char [rhs.getSize() + 1];
    strcpy(temp, rhs.getStrand());
    //char *temp = new char []
    for (int i=0; i<rhs.getSize(); i++)
    {
        for (int j=0; j<this->m_Size; j++)
        {
            if (temp[i] == this->getStrand()[j])
        }
    }
    delete [] temp;
    return *this;
}
*/

bool Strand::operator==(const Strand& rhs) const
{
    if(strcmp(this->getStrand(), rhs.getStrand()) != 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool Strand::operator<(const Strand& rhs) const
{
    if(strcmp(this->getStrand(), rhs.getStrand()) < 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}


//STRAND METHODS---------------------------------------------------------------

size_t Strand::size() const
{
    return strlen(this->m_Strand);
}

Strand Strand::substrand(size_t i, size_t j) const
{
    Strand newstrand;
    int sz = (j - i);
    char ij[sz + 1];
    int z=0;
    while(z < sz)
    {
        ij[z] = this->m_Strand[i];
        i++;
        z++;
    }
    ij[z] = 0;
    newstrand.setStrand(ij);
    return newstrand;
}

Strand Strand::merge(size_t i, const Strand &right) const
{
    char *temp = new char [i + right.getSize() + 1];
    strcpy(temp, this->substrand(0, i).getStrand());
    strcat(temp, right.getStrand());
    Strand s(temp);
    delete [] temp;
    return s;
}

size_t Strand::overlap(const Strand &right) const
{
    size_t overlap = 0;
    char *l = new char[this->getSize() + 1];
    strcpy(l, this->getStrand());

    char *r = new char[right.getSize() + 1];
    strcpy(r, right.getStrand());

    int ri = 0;
    for(int li=0; li<this->getSize(); li++)
    {
        if(l[li] == r[ri] && ri == 0)
        {
            ri++;
            overlap = li;
        }
        else if(l[li] == r[ri])
        {
            ri++;
        }
        else
        {
            ri = 0;
        }
    }
    if(ri == 0)
    {
        overlap = this->getSize();
    }
    delete l;
    delete r;
    return overlap;
}


//GETTER METHODS---------------------------------------------------------------

char *Strand::getStrand() const
{
    return this->m_Strand;
}

size_t Strand::getSize() const
{
    return this->m_Size;
}


//SETTER METHODS---------------------------------------------------------------

void Strand::setStrand(const char *src)
{
    if(m_Strand)
    {
        delete [] this->m_Strand;
    }
    this->m_Strand = new char [strlen(src) + 1];
    strcpy(this->m_Strand, src);
    this->m_Size = strlen(this->m_Strand);
}
