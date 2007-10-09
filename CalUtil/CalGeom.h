//    $Header: /nfs/slac/g/glast/ground/cvs/CalXtalResponse/src/XtalDigi/XtalDigiTool.cxx,v 1.16 2007/08/24 16:26:21 heather Exp $
#ifndef CalGeom_h
#define CalGeom_h

// LOCAL INCLUDES
#include "CalDefs.h"

// GLAST INCLUDES

// EXTLIB INCLUDES

// STD INCLUDES
#include <vector>

/** @file
    Geometry related utilities 
    @author Zach Fewtrell
*/

namespace CalUtil {
  /** generate list of active TEM modules in LAT */
  std::vector<CalUtil::TwrNum> findActiveTowers(IGlastDetSvc &detSvc);
};

#endif // CalGeom_h
