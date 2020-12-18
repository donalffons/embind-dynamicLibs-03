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

  TopTools_ListOfShape* aGenerations =
    myShapeToGenerated.ChangeSeek(theInitial);
  if (aGenerations == NULL)
  {
    aGenerations = myShapeToGenerated.Bound(theInitial, TopTools_ListOfShape());
  }

  aGenerations->Append(theGenerated);
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

  TopTools_ListOfShape* aModifications =
    myShapeToModified.ChangeSeek(theInitial);
  if (aModifications == NULL)
  {
    aModifications =
      myShapeToModified.Bound(theInitial, TopTools_ListOfShape());
  }

  aModifications->Append(theModified);
}

//==============================================================================
//function : Remove
//purpose  :
//==============================================================================
void BRepTools_History::Remove(const TopoDS_Shape& theRemoved)
{
  // Apply the limitations.
  if (myShapeToModified.UnBind(theRemoved))
  {
  }
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

  TopTools_ListOfShape* aGenerations =
    myShapeToGenerated.Bound(theInitial, TopTools_ListOfShape());
  aGenerations->Append(theGenerated);
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

  TopTools_ListOfShape* aModifications =
    myShapeToModified.Bound(theInitial, TopTools_ListOfShape());
  aModifications->Append(theModified);
}

//==============================================================================
//function : Generated
//purpose  :
//==============================================================================
const TopTools_ListOfShape& BRepTools_History::Generated(
  const TopoDS_Shape& theInitial) const
{
  //
  const TopTools_ListOfShape* aGenerations =
    myShapeToGenerated.Seek(theInitial);
  return (aGenerations != NULL) ? *aGenerations : emptyList();
}

//==============================================================================
//function : Modified
//purpose  :
//==============================================================================
const TopTools_ListOfShape& BRepTools_History::Modified(
  const TopoDS_Shape& theInitial) const
{
  //
  const TopTools_ListOfShape* aModifications =
    myShapeToModified.Seek(theInitial);
  return (aModifications != NULL) ? *aModifications : emptyList();
}

//==============================================================================
//function : IsRemoved
//purpose  :
//==============================================================================
Standard_Boolean BRepTools_History::IsRemoved(
  const TopoDS_Shape& theInitial) const
{
  //
  return myRemoved.Contains(theInitial);
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
  if (!(theHistory23.HasModified() ||
        theHistory23.HasGenerated() ||
        theHistory23.HasRemoved()))
    // nothing to merge
    return;

  // Propagate R23 directly and M23 and G23 fully to M12 and G12.
  // Remember the propagated shapes.
  TopTools_DataMapOfShapeListOfShape* aS1ToGAndM[] =
    {&myShapeToGenerated, &myShapeToModified};
  TopTools_MapOfShape aRPropagated;
  {
    // Propagate R23, M23 and G23 to M12 and G12 directly.
    // Remember the propagated shapes.
    TopTools_MapOfShape aMAndGPropagated;
    for (Standard_Integer aI = 0; aI < 2; ++aI)
    {
      for (TopTools_DataMapOfShapeListOfShape::Iterator aMIt1(*aS1ToGAndM[aI]);
        aMIt1.More(); aMIt1.Next())
      {
        TopTools_ListOfShape& aL12 = aMIt1.ChangeValue();
        TopTools_MapOfShape aAdditions[2]; // The G and M additions.
        for (TopTools_ListOfShape::Iterator aSIt2(aL12); aSIt2.More();)
        {
          const TopoDS_Shape& aS2 = aSIt2.Value();
          if (theHistory23.IsRemoved(aS2))
          {
            aRPropagated.Add(aS2);
            aL12.Remove(aSIt2);
          }
          else
          {
            if (theHistory23.myShapeToGenerated.IsBound(aS2))
            {
              aMAndGPropagated.Add(aS2);
            }

            if (theHistory23.myShapeToModified.IsBound(aS2))
            {
              aMAndGPropagated.Add(aS2);

              aL12.Remove(aSIt2);
            }
            else
            {
              aSIt2.Next();
            }
          }
        }

        if (aI != 0 && !aAdditions[0].IsEmpty())
        {
          const TopoDS_Shape& aS1 = aMIt1.Key();
          TopTools_ListOfShape* aGAndM = aS1ToGAndM[0]->ChangeSeek(aS1);
          if (aGAndM == NULL)
          {
            aGAndM = aS1ToGAndM[0]->Bound(aS1, TopTools_ListOfShape());
          }
        }
      }
    }

    // Propagate M23 and G23 to M12 and G12 sequentially.
    const TopTools_DataMapOfShapeListOfShape* aS2ToGAndM[] =
      {&theHistory23.myShapeToGenerated, &theHistory23.myShapeToModified};
    for (Standard_Integer aI = 0; aI < 2; ++aI)
    {
      for (TopTools_DataMapOfShapeListOfShape::Iterator aMIt2(*aS2ToGAndM[aI]);
        aMIt2.More(); aMIt2.Next())
      {
        const TopoDS_Shape& aS2 = aMIt2.Key();
        if (!aMAndGPropagated.Contains(aS2))
        {
          if (!aS1ToGAndM[aI]->IsBound(aS2))
          {
            aS1ToGAndM[aI]->Bind(aS2, TopTools_ListOfShape());
          }

          TopTools_ListOfShape aM2 = aMIt2.Value();
          ((*aS1ToGAndM[aI])(aS2)).Append(aM2);
          myRemoved.Remove(aS2);
        }
      }
    }
  }

  // Unbound the empty M12 and G12.
  for (Standard_Integer aI = 0; aI < 2; ++aI)
  {
    for (TopTools_DataMapOfShapeListOfShape::Iterator aMIt1(*aS1ToGAndM[aI]);
      aMIt1.More();)
    {
      const TopoDS_Shape& aS1 = aMIt1.Key();
      const TopTools_ListOfShape& aL12 = aMIt1.Value();
      aMIt1.Next();
      if (aL12.IsEmpty())
      {
        myRemoved.Add(aS1);
        aS1ToGAndM[aI]->UnBind(aS1);
      }
    }
  }

  // Propagate R23 to R12 sequentially.
  for (TopTools_MapOfShape::Iterator aRIt23(theHistory23.myRemoved);
    aRIt23.More(); aRIt23.Next())
  {
    const TopoDS_Shape& aS2 = aRIt23.Value();
    if (!aRPropagated.Contains(aS2) &&
      !myShapeToModified.IsBound(aS2) &&
      !myShapeToGenerated.IsBound(aS2))
    {
      myRemoved.Add(aS2);
    }
  }
}

//==============================================================================
//function : prepareGenerated
//purpose  :
//==============================================================================
Standard_Boolean BRepTools_History::prepareGenerated(
  const TopoDS_Shape& theInitial, const TopoDS_Shape& theGenerated)
{
  if (myShapeToModified.IsBound(theInitial) &&
    myShapeToModified(theInitial).Remove(theGenerated))
  {
  }

  return Standard_True;
}

//==============================================================================
//function : prepareModified
//purpose  :
//==============================================================================
Standard_Boolean BRepTools_History::prepareModified(
  const TopoDS_Shape& theInitial, const TopoDS_Shape& theModified)
{
  if (myRemoved.Remove(theInitial))
  {
  }

  if (myShapeToGenerated.IsBound(theInitial) &&
    myShapeToGenerated(theInitial).Remove(theModified))
  {
  }

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

//==============================================================================
//data : myMsgUnsupportedType
//purpose  :
//==============================================================================
const char* BRepTools_History::myMsgUnsupportedType =
  "Error: unsupported shape type.";

//==============================================================================
//data : myMsgGeneratedAndRemoved
//purpose  :
//==============================================================================
const char* BRepTools_History::myMsgGeneratedAndRemoved =
  "Error: a shape is generated and removed simultaneously.";

//==============================================================================
//data : myMsgModifiedAndRemoved
//purpose  :
//==============================================================================
const char* BRepTools_History::myMsgModifiedAndRemoved =
  "Error: a shape is modified and removed simultaneously.";

//==============================================================================
//data : myMsgGeneratedAndModified
//purpose  :
//==============================================================================
const char* BRepTools_History::myMsgGeneratedAndModified =
  "Error: a shape is generated and modified "
    "from the same shape simultaneously.";
