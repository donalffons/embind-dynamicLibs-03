// Created on: 2002-04-17
// Created by: Alexander Kartomin (akm)
// Copyright (c) 2002-2014 OPEN CASCADE SAS
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

// Purpose:     This is a base  class  for the  List, Set, Queue  and Stack
//              collections. It offers operations on abstract lists (of the
//              objects of class NCollection_ListNode).
//              Apart from this class being  brand new (in TCollection said
//              collections were independent, only using the same class for
//              node representation),  here is an  important new  feature - 
//              the  list  length is  continuously updated,  so the  method 
//              Extent is quite quick.

#ifndef NCollection_BaseList_HeaderFile
#define NCollection_BaseList_HeaderFile

#include <Standard_NoSuchObject.hxx>
#include <NCollection_DefineAlloc.hxx>
#include <NCollection_ListNode.hxx>

class NCollection_BaseList
{
public:
  virtual ~NCollection_BaseList (void)
  {}

protected:
  NCollection_BaseList (const Handle(NCollection_BaseAllocator)& theAllocator=0L)
  {
    myAllocator = (theAllocator.IsNull() ? NCollection_BaseAllocator::CommonBaseAllocator() : theAllocator);
  }

protected:
  Handle(NCollection_BaseAllocator) myAllocator;
};

#endif
