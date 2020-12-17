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
#include <Standard_MMgrRaw.hxx>
#include <Standard_MMgrTBBalloc.hxx>
#include <Standard_Assert.hxx>

#include <stdlib.h>

#include <mm_malloc.h>

#ifndef OCCT_MMGT_OPT_DEFAULT
#define OCCT_MMGT_OPT_DEFAULT 0
#endif

//=======================================================================
//class    : Standard_MMgrFactory 
//purpose  : Container for pointer to memory manager;
//           used to construct appropriate memory manager according
//           to environment settings, and to ensure destruction upon exit
//=======================================================================
class Standard_MMgrFactory
{
public:
  static Standard_MMgrRaw* GetMMgr();
  ~Standard_MMgrFactory();

private:
  Standard_MMgrFactory();
  Standard_MMgrFactory (const Standard_MMgrFactory&);
  Standard_MMgrFactory& operator= (const Standard_MMgrFactory&);

private:
  Standard_MMgrRaw* myFMMgr;
};

//=======================================================================
//function : Standard_MMgrFactory
//purpose  : Check environment variables and create appropriate memory manager
//=======================================================================

Standard_MMgrFactory::Standard_MMgrFactory()
: myFMMgr (NULL)
{
  char* aVar;
  aVar = getenv ("MMGT_OPT");
  Standard_Integer anAllocId   = (aVar ?  atoi (aVar): OCCT_MMGT_OPT_DEFAULT);

  aVar = getenv ("MMGT_CLEAR");
  Standard_Boolean toClear     = (aVar ? (atoi (aVar) != 0) : Standard_True);

  switch (anAllocId)
  {
    case 1:  // OCCT optimized memory allocator
    {
      aVar = getenv ("MMGT_MMAP");
      Standard_Boolean bMMap       = (aVar ? (atoi (aVar) != 0) : Standard_True);
      aVar = getenv ("MMGT_CELLSIZE");
      Standard_Integer aCellSize   = (aVar ?  atoi (aVar) : 200);
      aVar = getenv ("MMGT_NBPAGES");
      Standard_Integer aNbPages    = (aVar ?  atoi (aVar) : 1000);
      aVar = getenv ("MMGT_THRESHOLD");
      Standard_Integer aThreshold  = (aVar ?  atoi (aVar) : 40000);
      myFMMgr = nullptr;
      break;
    }
    case 2:  // TBB memory allocator
      break;
    case 0:
    default: // system default memory allocator
      myFMMgr = new Standard_MMgrRaw (toClear);
  }
}

//=======================================================================
//function : ~Standard_MMgrFactory
//purpose  : 
//=======================================================================

Standard_MMgrFactory::~Standard_MMgrFactory()
{
  if (  myFMMgr )
    myFMMgr->Purge(Standard_True);
}

Standard_MMgrRaw* Standard_MMgrFactory::GetMMgr()
{
  static Standard_MMgrFactory aFactory;
  return aFactory.myFMMgr;
}

//=======================================================================
//function : Allocate
//purpose  : 
//=======================================================================

Standard_Address Standard::Allocate(const Standard_Size size)
{
  return Standard_MMgrFactory::GetMMgr()->Allocate(size);
}

//=======================================================================
//function : Free
//purpose  : 
//=======================================================================

void Standard::Free (Standard_Address theStorage)
{
  Standard_MMgrFactory::GetMMgr()->Free(theStorage);
}

//=======================================================================
//function : Purge
//purpose  : 
//=======================================================================

Standard_Integer Standard::Purge()
{
  return Standard_MMgrFactory::GetMMgr()->Purge();
}

//=======================================================================
//function : AllocateAligned
//purpose  :
//=======================================================================

Standard_Address Standard::AllocateAligned (const Standard_Size theSize,
                                            const Standard_Size theAlign)
{
  return _mm_malloc (theSize, theAlign);
}

//=======================================================================
//function : FreeAligned
//purpose  :
//=======================================================================

void Standard::FreeAligned (Standard_Address thePtrAligned)
{
  _mm_free (thePtrAligned);
}
