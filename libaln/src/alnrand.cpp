// ALN Library

/* MIT License

Copyright (c) 2020 William Ward Armstrong

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE. */

// alnrand.cpp


#ifdef ALNDLL
#define ALNIMP __declspec(dllexport)
#endif

#include <aln.h>
#include "alnpriv.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
/*
///////////////////////////////////////////////////////////////////////////////
// faster rand()

//static int g_nFastRandSeed = 0x38549391;		// initial value

inline unsigned long DoFastRand()
{
  // Using the current seed, generate a new random value and seed and
	// return it.
  
  // This algorithm is similar to one proposed in Numerical Recipes in C,
  // which is in turn based on a Donald Knuth algorithm.
  
  return (g_nFastRandSeed = 1664525L * g_nFastRandSeed + 1013904223L);
}

// seeding for ALN internal pseudo-random number generator
ALNIMP void ALNAPI ALNSRand(unsigned int nSeed)
{
  g_nFastRandSeed = nSeed;
}

ALNIMP unsigned long ALNAPI ALNRand()
{
	return DoFastRand();
}

ALNIMP float ALNAPI ALNRandFloat() 
{
  
}
*/

#include <random>

unsigned long DoFastRand();
ALNIMP unsigned long ALNAPI ALNRand();
ALNIMP float ALNAPI ALNRandFloat();
ALNIMP void ALNAPI ALNSRand(unsigned int nSeed);

std::mt19937_64 generator;
std::uniform_int_distribution<int> distribution1(0, 1474836UL);
std::uniform_real_distribution<float> distribution2(0.0,1.0);


unsigned long DoFastRand()
{
    return distribution1(generator);
}
  
ALNIMP unsigned long ALNAPI ALNRand()
{
	return DoFastRand(); // this does a random int
}

ALNIMP float ALNAPI ALNRandFloat() 
{
   return distribution2(generator);
}


ALNIMP void ALNAPI ALNSRand(unsigned int nSeed)
{
	return; // not used here
}
