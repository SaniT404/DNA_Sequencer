#include "strand.h"
#include <vector>
#include "sequence.h"
#include <iostream>


std::vector<Strand> sequence(std::vector<Strand> strands, const size_t minimum_overlap_size)
{
    while (strands.size() > 1)
    {
        bool change = true;
        int s;
        while (change)
        {
            change = false;
            for (s=0;s<strands.size()-1;s++)
            {
                if (strands[s+1] < strands[s])
                {
                    auto temp = strands[s];
                    strands[s] = strands[s+1];
                    strands[s+1] = temp;
                    change = true;
                }
            }
        }

        size_t biggest_overlap = 0;
        size_t big_i = 0;
        size_t big_j = 0;
        size_t current_overlap = 0;

        int i,j;
        for (i=0;i<strands.size();i++)
        {
            for (j=0;j<strands.size();j++)
            {
                if (i != j)
                {
                    current_overlap = strands[i].size() - strands[i].overlap(strands[j]);
                    if (current_overlap > biggest_overlap)
                    {
                        big_i = i;
                        big_j = j;
                        biggest_overlap = current_overlap;
                    }
                }
            }
        }
        //MERGE STRANDS
        if (biggest_overlap >= minimum_overlap_size)
        {
            Strand newstrand;
            newstrand = strands[big_i].merge(strands[big_i].overlap(strands[big_j]), strands[big_j]);

            if (big_i < big_j)
            {
                strands.erase(strands.begin() + big_j);
                strands.erase(strands.begin() + big_i);
            }
            else
            {
                strands.erase(strands.begin() + big_i);
                strands.erase(strands.begin() + big_j);
            }
            strands.push_back(newstrand);
        }
    }
    //compare all strands.  Look for largest overlap
            //if multiple strand combinations have the same largest overlap
            //then take the one with the earliest left strand.

            //if earliest left strand overlap is same as other strand overlap
            //use the one with the earliest right strand.
    //If largest overlap is >= minimum_overlap_size, then remove the two strands
    //from collection and add in the merged strand of those two strands.

    //SORT
    
    return strands;
}
