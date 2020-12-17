// Created on: 2005-03-15
// Created by: Peter KURNEV
// Copyright (c) 1998-1999 Matra Datavision
// Copyright (c) 1999-2014 OPEN CASCADE SAS
//
// This file is part of Open CASCADE Technology software library.
//
// This library is free software; you can redistribute it and/or modify it under
// the terms of the GNU Lesser General Public License version 2.1 as published
// by the Free Software Foundation, with special exception defined in the file
// OCCT_LGPL_EXCEPTION.txt. Consult the file LICENSE_LGPL_21.txt included in OCCT
// distribution for complete text of the license and disclaimer of any warranty.
//
// Alternatively, this file may be used under the terms of Open CASCADE
// commercial license or contractual agreement.


#include <Standard.hxx>
#include <Standard_MMgrOpt.hxx>
#include <Standard_MMgrRaw.hxx>
#include <Standard_MMgrTBBalloc.hxx>
#include <Standard_Assert.hxx>

#include <stdlib.h>
#include <mm_malloc.h>

#ifndef OCCT_MMGT_OPT_DEFAULT
#define OCCT_MMGT_OPT_DEFAULT 0
#endif

//=======================================================================
//function : Allocate
//purpose  : 
//=======================================================================

Standard_Address Standard::Allocate(const Standard_Size size)
{
  return nullptr;
}

//=======================================================================
//function : Free
//purpose  : 
//=======================================================================

void Standard::Free (Standard_Address theStorage)
{
}

//=======================================================================
//function : Reallocate
//purpose  : 
//=======================================================================

Standard_Address Standard::Reallocate (Standard_Address theStorage,
				       const Standard_Size theSize)
{
  return nullptr;
}

//=======================================================================
//function : Purge
//purpose  : 
//=======================================================================

Standard_Integer Standard::Purge()
{
  return 0;
}

//=======================================================================
//function : AllocateAligned
//purpose  :
//=======================================================================

Standard_Address Standard::AllocateAligned (const Standard_Size theSize,
                                            const Standard_Size theAlign)
{
#if defined(_MSC_VER)
  return _aligned_malloc (theSize, theAlign);
#elif defined(__ANDROID__) || defined(__QNX__)
  return memalign (theAlign, theSize);
#elif (defined(__GNUC__) && (__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 1)) && (defined(__i386) || defined(__x86_64)))
  return _mm_malloc (theSize, theAlign);
#else
  void* aPtr;
  if (posix_memalign (&aPtr, theAlign, theSize))
  {
    return NULL;
  }
  return aPtr;
#endif
}

//=======================================================================
//function : FreeAligned
//purpose  :
//=======================================================================

void Standard::FreeAligned (Standard_Address thePtrAligned)
{
#if defined(_MSC_VER)
  _aligned_free (thePtrAligned);
#elif defined(__ANDROID__) || defined(__QNX__)
  free (thePtrAligned);
#elif (defined(__GNUC__) && (__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 1)) && (defined(__i386) || defined(__x86_64)))
  _mm_free (thePtrAligned);
#else
  free (thePtrAligned);
#endif
}
