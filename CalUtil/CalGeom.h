//    $Header: /nfs/slac/g/glast/ground/cvs/CalUtil/CalUtil/CalGeom.h,v 1.1 2007/10/09 18:56:23 fewtrell Exp $
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
