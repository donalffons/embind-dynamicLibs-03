#ifndef _Standard_DefineAlloc_HeaderFile
#define _Standard_DefineAlloc_HeaderFile

#  define DEFINE_STANDARD_ALLOC_ARRAY                                  \
   void* operator new[] (size_t theSize)                               \
   {                                                                   \
     return Standard::Allocate (theSize);                              \
   }                                                                   \
   void  operator delete[] (void* theAddress)                          \
   {                                                                   \
     Standard::Free (theAddress);                                      \
   }

#  define DEFINE_STANDARD_ALLOC_PLACEMENT                              \
   void* operator new (size_t, void* theAddress)                       \
   {                                                                   \
     return theAddress;                                                \
   }                                                                   \
   void operator delete (void*, void*)                                 \
   {                                                                   \
   }

// Macro to override operators new and delete to use OCC memory manager
# define DEFINE_STANDARD_ALLOC                                         \
  void* operator new (size_t theSize)                                  \
  {                                                                    \
    return Standard::Allocate (theSize);                               \
  }                                                                    \
  void  operator delete (void* theAddress)                             \
  {                                                                    \
    Standard::Free (theAddress);                                       \
  }                                                                    \
  DEFINE_STANDARD_ALLOC_ARRAY                                          \
  DEFINE_STANDARD_ALLOC_PLACEMENT

#endif // _Standard_DefineAlloc_HeaderFile
