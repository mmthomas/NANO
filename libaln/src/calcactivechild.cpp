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

// calcactivechild.cpp

#ifdef ALNDLL
#define ALNIMP __declspec(dllexport)
#endif

#include <aln.h>
#include "alnpriv.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


int ALNAPI CalcActiveChild(float& fltRespActive, float& fltDistance, 
                           float flt0, float flt1, const ALNNODE* pNode)                          

{
  int nActive = -1;

  // MAX node handling
	if (MINMAX_ISMAX(pNode)) 
	{
		if(flt1 > flt0)	//  this puts child 1 100% active
		{
		  nActive = 1;
		  fltRespActive = 1.0;
		  fltDistance = flt1;
		}
		else	// child 0 is 100% active
		{
			nActive = 0;
		  fltRespActive = 1.0;
		  fltDistance = flt0;
		}	
	}
	else // this is a MIN node
	{    
  		if(flt1 < flt0) //  this puts child 1 100% active
		{
			nActive = 1;
			fltRespActive = 1.0;
			fltDistance = flt1;
  		}
		else	 // child 0 is 100% active
		{
			nActive = 0;
			fltRespActive = 1.0;
			fltDistance = flt0;
		}
	}

  ASSERT(nActive != -1);
  return nActive;
}
