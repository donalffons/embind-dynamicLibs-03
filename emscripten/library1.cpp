// class Standard_MMgrRoot {};

// class Standard_MMgrFactory
// {
// public:
//   static Standard_MMgrRoot* GetMMgr();
//   ~Standard_MMgrFactory(){}

// private:
//   Standard_MMgrRoot* myFMMgr;
// };


// // BELOW IS THE ORIGINAL COMMENT FROM THE OPENCASCADE PROJECT, WHICH MIGHT
// // HELP TO EXPLAIN THE PURPOSE OF THE ORIGINAL FUNCTION. THIS IS JUST A DUMMY
// // TO REPRODUCE THE PROBLEM.
// // See here for the original source code:
// //   https://git.dev.opencascade.org/gitweb/?p=occt.git;a=blob;f=src/Standard/Standard.cxx;h=78b25e1cb771e8916585cfed94288123a5314753;hb=HEAD#l227
// // 
// //
// //=======================================================================
// // function: GetMMgr
// //
// // This static function has a purpose to wrap static holder for memory 
// // manager instance. 
// //
// // Wrapping holder inside a function is needed to ensure that it will
// // be initialized not later than the first call to memory manager (that
// // would be impossible to guarantee if holder was static variable on 
// // global or file scope, because memory manager may be called from 
// // constructors of other static objects).
// //
// // Note that at the same time we could not guarantee that the holder 
// // object is destroyed after last call to memory manager, since that 
// // last call may be from static Handle() object which has been initialized
// // dynamically during program execution rather than in its constructor.
// //
// // Therefore holder currently does not call destructor of the memory manager 
// // but only its method Purge() with Standard_True.
// //
// // To free the memory completely, we probably could use compiler-specific 
// // pragmas (such as '#pragma fini' on SUN Solaris and '#pragma init_seg' on 
// // WNT MSVC++) to put destructing function in code segment that is called
// // after destructors of other (even static) objects. However, this is not 
// // done by the moment since it is compiler-dependent and there is no guarantee 
// // thatsome other object calling memory manager is not placed also in that segment...
// //
// // Note that C runtime function atexit() could not help in this problem 
// // since its behaviour is the same as for destructors of static objects 
// // (see ISO 14882:1998 "Programming languages -- C++" 3.6.3)
// //
// // The correct approach to deal with the problem would be to have memory manager 
// // to properly control its memory allocation and caching free blocks so 
// // as to release all memory as soon as it is returned to it, and probably
// // even delete itself if all memory it manages has been released and 
// // last call to method Purge() was with True.
// //
// // Note that one possible method to control memory allocations could
// // be counting calls to Allocate() and Free()...
// //
// //=======================================================================
// Standard_MMgrRoot* Standard_MMgrFactory::GetMMgr()
// {
//   static Standard_MMgrFactory aFactory;
//   return aFactory.myFMMgr;
// }

int i = 1;
