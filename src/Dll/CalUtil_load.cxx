/** 
 * @file CalUtil_load.cpp
 * @brief This is needed for forcing the linker to load all components
 * of the library.
 *
 *  $Header: /nfs/slac/g/glast/ground/cvs/CalUtil/src/Dll/CalUtil_load.cxx,v 1.5 2005/02/05 09:26:48 fewtrell Exp $
 */

#include "GaudiKernel/DeclareFactoryEntries.h"
#include "GaudiKernel/IToolFactory.h"

#define DLL_DECL_TOOL(x)       extern const IToolFactory& x##Factory; x##Factory.addRef();

#define DLL_DECL_TOOL(x)       extern const IToolFactory& x##Factory; x##Factory.addRef();


DECLARE_FACTORY_ENTRIES(CalUtil) {
  DECLARE_SERVICE( CalFailureModeSvc );
} 
