//    $Header: /nfs/slac/g/glast/ground/cvs/GlastRelease-scons/CalUtil/CalUtil/CalGeom.h,v 1.3 2008/01/22 19:58:38 fewtrell Exp $
#ifndef CalGeom_h
#define CalGeom_h

// LOCAL INCLUDES
#include "CalDefs.h"

// GLAST INCLUDES

// EXTLIB INCLUDES

// STD INCLUDES
#include <vector>

class IGlastDetSvc;

/** @file
    Geometry related utilities 
    @author Zach Fewtrell
*/

namespace CalUtil {
  typedef std::vector<CalUtil::TwrNum> TwrList;
  /** generate list of active TEM modules in LAT */
  TwrList findActiveTowers(IGlastDetSvc &detSvc);
};

#endif // CalGeom_h
