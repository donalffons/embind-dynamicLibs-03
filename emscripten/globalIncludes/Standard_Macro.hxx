#ifndef _Standard_Macro_HeaderFile
# define _Standard_Macro_HeaderFile

  #define Standard_OVERRIDE override
  #define Standard_FALLTHROUGH

  #define Standard_UNUSED __attribute__((unused))
    #define Standard_THREADLOCAL thread_local
  #define Standard_DEPRECATED(theMsg) __attribute__((deprecated(theMsg)))

  // available since at least gcc 4.2 (maybe earlier), however only gcc 4.6+ supports this pragma inside the function body
  // CLang also supports this gcc syntax (in addition to "clang diagnostic ignored")
  #define Standard_DISABLE_DEPRECATION_WARNINGS _Pragma("GCC diagnostic ignored \"-Wdeprecated-declarations\"")
  #define Standard_ENABLE_DEPRECATION_WARNINGS  _Pragma("GCC diagnostic warning \"-Wdeprecated-declarations\"")

#  ifndef Standard_EXPORT
#   define Standard_EXPORT
// For global variables :
#   define Standard_EXPORTEXTERN extern
#   define Standard_EXPORTEXTERNC extern "C"
#  endif  /* Standard_EXPORT */

#  ifndef Standard_IMPORT
#   define Standard_IMPORT extern
#   define Standard_IMPORTC extern "C"
#  endif  /* Standard_IMPORT */


#endif
