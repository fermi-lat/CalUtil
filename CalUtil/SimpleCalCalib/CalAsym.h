#ifndef CalAsym_h
#define CalAsym_h
// $Header: /nfs/slac/g/glast/ground/cvs/CalUtil/CalUtil/SimpleCalCalib/CalAsym.h,v 1.1 2008/01/22 20:12:07 fewtrell Exp $

/** @file
    @author Zachary Fewtrell
*/

// LOCAL INCLUDES


// GLAST INCLUDES
#include "CalUtil/CalDefs.h"
#include "CalUtil/CalVec.h"

// EXTLIB INCLUDES
#include "TSpline.h"

// STD INCLUDES

namespace {
  /// length of cal CsI crystal (hardcoded)
  static const float CSI_LEN=326.0;
}

namespace CalUtil {

  /** \brief Reresents GLAST Cal crystal light asymmetry calibration constants.

      contains read & write methods to various file formats

      @author Zachary Fewtrell
  */
  class CalAsym {
  public:
    /// start with zero values
    CalAsym(const unsigned short nSlicesPerXtal=10);

    /// write asymmetry tables out to text file.
    void writeTXT(const std::string &filename) const;

    /// read asymmetry tables in from text file(s)
    void readTXT(const std::string &filename);

    /// # of points per xtal for asymmetry type data.
    /// 1 point for the center of each orthogonal xtal
    /// excluding the two outermost xtals
    const unsigned short nSlicesPerXtal;

    /// creates & populates Asymmetry splines from m_asym
    void genSplines();

    /// uses asym2pos splines to convert asymmetry value to xtal position for
    /// energy centroid
    /// \note uses CalUtil internal xtal-pitch units w/ origin at negative
    /// face.
    /// \return INVALID_ASYM on error
    /// \warning you _must_ call genSplines method before using.
    float asym2pos(const CalUtil::XtalIdx xtalIdx,
                   const CalUtil::DiodeNum diode,
                   const float asym) const {
      if (!m_a2pSplines[diode][xtalIdx])
        return INVALID_ASYM;

      return m_a2pSplines[diode][xtalIdx]->Eval(asym);
    }

    /// uses pos2asym splines to convert xtal position to light asymmetry
    /// \note uses CalUtil internal xtal-pitch units w/ origin at negative
    /// face.
    /// \return INVALID_ASYM on error
    /// \warning you _must_ call genSplines method before using.
    float pos2asym(const CalUtil::XtalIdx xtalIdx,
                   const CalUtil::DiodeNum diode,
                   const float pos) const {
      TSpline3 *splinePtr = m_p2aSplines[diode][xtalIdx];


      if (!splinePtr)
        return INVALID_ASYM;

      return splinePtr->Eval(pos);
    }

    /// represent invalid value in dat arrays
    static const short INVALID_ASYM = -5000;

    /// \brief return the center position of a given segment along
    /// a crystal in mm from center of xtal.
    ///
    /// \note xtals are divided along length into 12 equal segments
    /// these segments can be though of as matching the widths of the
    /// 12 orthogonal crystals.
    static float xtalSegmentPos(const unsigned short col) {
      return (CSI_LEN/CalUtil::ColNum::N_VALS)*
        ((float)col + 0.5)        // calc for middle of segment
        - 0.5*CSI_LEN; // put 0 in middle of xtal
    }

    /// \brief return xtal segment # from longitudinal position
    /// along xtal in mm from center
    ///
    /// \note see note on xtaSegmentPos() method for definition
    /// of segment numbering
    static unsigned short pos2xtalSegment(const float mmFromCtr) {
      float mmFromEnd = mmFromCtr + CSI_LEN/2;


      return (unsigned short)(mmFromEnd*12/CSI_LEN);
    }

    const std::vector<float> & getPtsErr(const CalUtil::XtalIdx xtalIdx,
                                         const CalUtil::AsymType asymType) const
    {
      return m_asymErr[asymType][xtalIdx];
    }

    const std::vector<float> & getPtsAsym(const CalUtil::XtalIdx xtalIdx,
                                          const CalUtil::AsymType asymType) const
    {
      return m_asym[asymType][xtalIdx];
    }

    std::vector<float> & getPtsErr(const CalUtil::XtalIdx xtalIdx,
                                   const CalUtil::AsymType asymType)
    {
      return m_asymErr[asymType][xtalIdx];
    }

    std::vector<float> & getPtsAsym(const CalUtil::XtalIdx xtalIdx,
                                    const CalUtil::AsymType asymType)
    {
      return m_asym[asymType][xtalIdx];
    }

  private:

    /// collection of spline functions based on LEX8 vs LEX8 light asymmetry
    CalUtil::CalVec<CalUtil::DiodeNum, CalUtil::CalVec<CalUtil::XtalIdx,
                                                       TSpline3 *> >
    m_a2pSplines;

    /// collection of spline functions based on LEX8 vs LEX8 asymmetry
    /// vs xtal position
    CalUtil::CalVec<CalUtil::DiodeNum, CalUtil::CalVec<CalUtil::XtalIdx,
                                                       TSpline3 *> >
    m_p2aSplines;

    /// 2d vector nSlicesPerXtal lograt asymvals per xtal/asymType
    CalUtil::CalVec<CalUtil::AsymType, CalUtil::CalVec<CalUtil::XtalIdx, std::vector<float> > > m_asym;
    /// corresponding error value
    CalUtil::CalVec<CalUtil::AsymType, CalUtil::CalVec<CalUtil::XtalIdx,
                                                       std::vector<float> > > m_asymErr;
  };

}; // namespace CalUtil
#endif
