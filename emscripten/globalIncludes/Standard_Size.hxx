// Created on: 2006-08-22
// Created by: Alexander GRIGORIEV
// Copyright (c) 2006-2014 OPEN CASCADE SAS
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

#ifndef _size_t_HeaderFile
#define _size_t_HeaderFile

#include <int.hxx>

// msv 26.05.2009: add HashCode and IsEqual functions

//! Computes a hash code for the given value of the size_t type, in the range [1, theUpperBound]
//! @tparam TheSize the type of the given value (it is size_t,
//! and must not be the same as "unsigned int", because the overload of the HashCode function
//! for "unsigned int" type is already presented in int.hxx)
//! @param theValue the value of the size_t type which hash code is to be computed
//! @param theUpperBound the upper bound of the range a computing hash code must be within
//! @return a computed hash code, in the range [1, theUpperBound]
template <typename TheSize>
typename opencascade::std::enable_if<!opencascade::std::is_same<size_t, unsigned int>::value
                                       && opencascade::std::is_same<TheSize, size_t>::value,
                                     int>::type
HashCode (const TheSize theValue, const int theUpperBound)
{
  size_t aKey = ~theValue + (theValue << 18);
  aKey ^= (aKey >> 31);
  aKey *= 21;
  aKey ^= (aKey >> 11);
  aKey += (aKey << 6);
  aKey ^= (aKey >> 22);
  return IntegerHashCode(aKey, IntegerLast(), theUpperBound);
}

// ------------------------------------------------------------------
// IsEqual : Returns true if two values are equal
// ------------------------------------------------------------------
inline bool IsEqual(const size_t One,
                                const size_t Two)
{
  return One == Two;
}

#endif
