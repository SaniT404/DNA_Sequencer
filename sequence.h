#ifndef __SEQUENCE_H__
#define __SEQUENCE_H__

#include <vector>
#include "strand.h"

std::vector<Strand> sequence(std::vector<Strand> strands, const size_t minimum_overlap_size);

#endif
