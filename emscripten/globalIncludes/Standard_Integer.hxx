// Copyright (c) 1998-1999 Matra Datavision
// Copyright (c) 1999-2013 OPEN CASCADE SAS
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

#ifndef _Standard_Integer_HeaderFile
#define _Standard_Integer_HeaderFile

#include <Standard_Std.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_values.h>

// ------------------------------------------------------------------
// Square : Returns the square of an integer
// ------------------------------------------------------------------
inline Standard_Integer Square(const Standard_Integer Value)
{ return Value * Value; }

// ------------------------------------------------------------------
// IntegerFirst : Returns the minimum value of an integer
// ------------------------------------------------------------------
inline Standard_Integer  IntegerFirst()
{ return INT_MIN; }

// ------------------------------------------------------------------
// IntegerLast : Returns the maximum value of an integer
// ------------------------------------------------------------------
inline Standard_Integer  IntegerLast()
{ return INT_MAX; }

// ------------------------------------------------------------------
// IntegerSize : Returns the size in digits of an integer
// ------------------------------------------------------------------
inline Standard_Integer  IntegerSize()
{ return BITS(Standard_Integer); }


//! Computes a hash code for the given value of some integer type, in range [1, theUpperBound]
//! @tparam TheInteger the type of the integer which hash code is to be computed
//! @param theValue the value of the TheInteger type which hash code is to be computed
//! @param theMask the mask for the last bits of the value that are used in the computation of a hash code
//! @param theUpperBound the upper bound of the range a computing hash code must be within
//! @return a computed hash code, in range [1, theUpperBound]
template <typename TheInteger>
typename opencascade::std::enable_if<opencascade::is_integer<TheInteger>::value, Standard_Integer>::type
IntegerHashCode (const TheInteger                                                theValue,
                 const typename opencascade::disable_deduction<TheInteger>::type theMask,
                 const Standard_Integer                                          theUpperBound)
{
  return static_cast<Standard_Integer> ((theValue & theMask) % theUpperBound + 1);
}

//! Computes a hash code for the given value of the Standard_Integer type, in range [1, theUpperBound]
//! @param theValue the value of the Standard_Integer type which hash code is to be computed
//! @param theUpperBound the upper bound of the range a computing hash code must be within
//! @return a computed hash code, in range [1, theUpperBound]
inline Standard_Integer HashCode (const Standard_Integer theValue,
                                  const Standard_Integer theUpperBound)
{
  // return (Abs (theMe) % theUpper) + 1;
  return IntegerHashCode(theValue, IntegerLast(), theUpperBound);
}


#endif
