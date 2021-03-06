#ifndef CalUtil_CalDiagnostic_h
#define CalUtil_CalDiagnostic_h

/** @file
$Header: /nfs/slac/g/glast/ground/cvs/CalUtil/CalUtil/CalDiagnosticWord.h,v 1.1 2008/02/27 20:11:47 fewtrell Exp $
@author Z. Fewtrell
 */

// LOCAL INCLUDES
#include "CalVec.h"
#include "CalDefs.h"

namespace CalUtil {
  /** class to represent data stored Cal Diagnostic entry, converts from
      CalUtil::CalDefs indeces to packed TEM Cal Diagnostic word.
   */
  class CalDiagnosticWord {
  public:
    /// 2-D array for storing all LAC bits,  index by [face][col]
    typedef CalVec<FaceNum, CalVec<ColNum, bool> > CalDiagLACBits;

    /// 2-D array for storing all trigger bits, index by [face][diode]
    typedef CalVec<FaceNum, CalVec<DiodeNum, bool> > CalDiagTrigBits;

    CalDiagnosticWord(const CalDiagTrigBits &trigBits,
                      const CalDiagLACBits &lacBits) :
      m_lacBits(lacBits),
      m_trigBits(trigBits)
    {
      
    }

    /// construct from packed 32 bit word
    CalDiagnosticWord(const unsigned dataWord);

    /// return 32 bit Cal diagnostic word with all LAC & trigger bits
    /// set 
    unsigned getDatum() const;

  private:
    /// lac bits for current layer (24 total)
    CalDiagLACBits m_lacBits;

    /// trigger bits for current layer (4 total)
    CalDiagTrigBits m_trigBits;
    
  };
}



#endif  // CalUtil_CalDiagnostic_h
