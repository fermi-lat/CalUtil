/** 
* @file CalUtil_load.cpp
* @brief This is needed for forcing the linker to load all components
* of the library.
*
*  $Header: /nfs/slac/g/glast/ground/cvs/CalUtil/src/Dll/CalUtil_load.cxx,v 1.3 2004/08/24 04:54:50 fewtrell Exp $
*/

#include "GaudiKernel/DeclareFactoryEntries.h"
#include "GaudiKernel/IToolFactory.h"

#define DLL_DECL_TOOL(x)       extern const IToolFactory& x##Factory; x##Factory.addRef();

#define DLL_DECL_TOOL(x)       extern const IToolFactory& x##Factory; x##Factory.addRef();


DECLARE_FACTORY_ENTRIES(CalUtil) {
    DECLARE_SERVICE( CalFailureModeSvc );
    DLL_DECL_TOOL( LinearConvertAdc   );

    DECLARE_SERVICE( CalCalibSvc );
    DLL_DECL_TOOL( TestEnergyTool );
    DLL_DECL_TOOL( TestAdcTool );
    DLL_DECL_TOOL( TestPosTool );
} 
