// $Header: /nfs/slac/g/glast/ground/cvs/CalUtil/src/test/test_CalUtil_load.cxx,v 1.1.1.1 2002/10/30 18:13:51 richard Exp $
//====================================================================
//
//  Description: Implementation of <Package>_load routine.
//               This routine is needed for forcing the linker
//               to load all the components of the library. 
//
//====================================================================

#include "GaudiKernel/IAlgFactory.h"
#define DLL_DECL_ALGORITHM(x)  extern const IAlgFactory& x##Factory; x##Factory.addRef();
#define DLL_DECL_OBJECT(x)     extern const IFactory& x##Factory; x##Factory.addRef();
//! Load all  services: 
void test_CalUtil_load() {
    DLL_DECL_ALGORITHM( test_CalUtil );
} 

extern "C" void test_CalUtil_loadRef()    {
    test_CalUtil_load();
}

