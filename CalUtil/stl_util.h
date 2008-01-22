#ifndef CalUtil_stl_util_h
#define CalUtil_stl_util_h
// $Header: /nfs/slac/g/glast/ground/cvs/CalUtil/CalUtil/stl_util.h,v 1.1 2007/11/06 21:10:44 fewtrell Exp $

/** @file 
    Generic C++ STL based utilities.
    @author zachary.fewtrell@nrl.navy.mil
 */

// STD includes
#include <set>


namespace CalUtil {
  
  /// return true if container contains a match for val
  template <typename col_type>
  bool contains(const col_type &col, typename col_type::const_reference val) {
    return std::find(col.begin(), col.end(), val) != col.end();
  }

}


#endif //CalUtil_stl_util_h
