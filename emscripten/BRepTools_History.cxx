// Created on: 2017-04-21
// Created by: Alexander Bobkov
// Copyright (c) 2017 OPEN CASCADE SAS
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

#include <BRepTools_History.hxx>

// Implement the OCCT RTTI for the type.


//==============================================================================
//function : AddGenerated
//purpose  :
//==============================================================================
void BRepTools_History::AddGenerated(
  const TopoDS_Shape& theInitial, const TopoDS_Shape& theGenerated)
{
  if (!prepareGenerated(theInitial, theGenerated))
  {
    return;
  }

}

//==============================================================================
//function : AddModified
//purpose  :
//==============================================================================
void BRepTools_History::AddModified(
  const TopoDS_Shape& theInitial, const TopoDS_Shape& theModified)
{
  if (!prepareModified(theInitial, theModified))
  {
    return;
  }

}

//==============================================================================
//function : Remove
//purpose  :
//==============================================================================
void BRepTools_History::Remove(const TopoDS_Shape& theRemoved)
{
}

//==============================================================================
//function : ReplaceGenerated
//purpose  :
//==============================================================================
void BRepTools_History::ReplaceGenerated(
  const TopoDS_Shape& theInitial, const TopoDS_Shape& theGenerated)
{
  if (!prepareGenerated(theInitial, theGenerated))
  {
    return;
  }
}

//==============================================================================
//function : ReplaceModified
//purpose  :
//==============================================================================
void BRepTools_History::ReplaceModified(
  const TopoDS_Shape& theInitial, const TopoDS_Shape& theModified)
{
  if (!prepareModified(theInitial, theModified))
  {
    return;
  }
}

//==============================================================================
//function : Merge
//purpose  :
//==============================================================================
void BRepTools_History::Merge(const Handle(BRepTools_History)& theHistory23)
{
  if (!theHistory23.IsNull())
    Merge(*theHistory23.get());
}
//==============================================================================
//function : Merge
//purpose  :
//==============================================================================
void BRepTools_History::Merge(const BRepTools_History& theHistory23)
{
}

//==============================================================================
//function : prepareGenerated
//purpose  :
//==============================================================================
Standard_Boolean BRepTools_History::prepareGenerated(
  const TopoDS_Shape& theInitial, const TopoDS_Shape& theGenerated)
{
  return Standard_True;
}

//==============================================================================
//function : prepareModified
//purpose  :
//==============================================================================
Standard_Boolean BRepTools_History::prepareModified(
  const TopoDS_Shape& theInitial, const TopoDS_Shape& theModified)
{
  return Standard_True;
}

//==============================================================================
//data : myEmptyList
//purpose  :
//==============================================================================
const TopTools_ListOfShape BRepTools_History::myEmptyList;

//==============================================================================
//function : emptyList
//purpose  :
//==============================================================================
const TopTools_ListOfShape& BRepTools_History::emptyList()
{
  return myEmptyList;
}
