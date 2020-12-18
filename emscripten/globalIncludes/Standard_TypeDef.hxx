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

#ifndef _Standard_TypeDef_HeaderFile
#define _Standard_TypeDef_HeaderFile

#include <cstddef>
#include <ctime>

#include <stdint.h>

    #define __STDC_FORMAT_MACROS
  #include <inttypes.h>

#define Standard_False false
#define Standard_True  true

#include <Standard_Macro.hxx>

typedef int           Standard_Integer;
typedef double        Standard_Real;
typedef bool          Standard_Boolean;
typedef float         Standard_ShortReal;
typedef char          Standard_Character;
typedef unsigned char Standard_Byte;
typedef void*         Standard_Address;
typedef size_t        Standard_Size;
typedef std::time_t   Standard_Time;

// Unicode primitives, char16_t, char32_t
typedef char          Standard_Utf8Char;     //!< signed   UTF-8 char
typedef unsigned char Standard_Utf8UChar;    //!< unsigned UTF-8 char

typedef char16_t      Standard_ExtCharacter;
typedef char16_t      Standard_Utf16Char;    //!< UTF-16 char (always unsigned)
typedef char32_t      Standard_Utf32Char;    //!< UTF-32 char (always unsigned)
typedef wchar_t       Standard_WideChar;     //!< wide char (unsigned UTF-16 on Windows platform and signed UTF-32 on Linux)

//
typedef const Standard_Character*    Standard_CString;
typedef const Standard_ExtCharacter* Standard_ExtString;

#endif // _Standard_TypeDef_HeaderFile
