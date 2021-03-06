// $Header: /nfs/slac/g/glast/ground/cvs/CalUtil/src/SimpleCalCalib/CalMPD.cxx,v 1.2 2008/02/05 22:32:23 makeev Exp $

/** @file
    @author Zachary Fewtrell
*/

// LOCAL INCLUDES
#include "CalUtil/SimpleCalCalib/CalMPD.h"

// GLAST INCLUDES

// EXTLIB INCLUDES

// STD INCLUDES
#include <fstream>
#include <sstream>

namespace CalUtil {

  using namespace std;
  using namespace CalUtil;

  const short CalMPD::INVALID_MPD = -5000;

  CalMPD::CalMPD() 
  {
    for (DiodeNum diode; diode.isValid(); diode++)
      fill(m_mpd[diode].begin(), m_mpd[diode].end(), INVALID_MPD);
  }

  void CalMPD::writeTXT(const std::string &filename) const {
    ofstream outfile(filename.c_str());

    if (!outfile.is_open())
      throw runtime_error(string("Unable to open " + filename));

    // output header info as comment
    outfile << ";twr lyr col diode mpd error" << endl;

    // PER XTAL LOOP
    for (XtalIdx xtalIdx; xtalIdx.isValid(); xtalIdx++)
      for (DiodeNum diode; diode.isValid(); diode++) {
        const TwrNum twr ( xtalIdx.getTwr());
        const LyrNum lyr ( xtalIdx.getLyr());
        const ColNum col ( xtalIdx.getCol());
        if (m_mpd[diode][xtalIdx] == INVALID_MPD)
          continue;

        // per point along curve
        outfile << twr.val()
                << " " << lyr.val()
                << " " << col.val()
                << " " << diode.val()
                << " " << m_mpd[diode][xtalIdx]
                << " " << m_mpdErr[diode][xtalIdx]
                << endl;
      }
  }

  void CalMPD::readTXT(const std::string &filename) {
    unsigned short twr, lyr, col, diode;
    float mpd, sig;


    // open file
    ifstream infile(filename.c_str());

    if (!infile.is_open())
      throw runtime_error(string("Unable to open " + filename));

    // loop through each line in file
    string line;
    while (infile.good()) {
      getline(infile, line);
      if (infile.fail()) break; // bad get

      // check for comments
      if (line[0] == ';')
        continue;

      istringstream istrm(line);

      // get lyr, col (xtalId)
      istrm >> twr >> lyr >> col >> diode >> mpd >> sig;

      const XtalIdx xtalIdx(twr,
                            LyrNum(lyr),
                            col);

      m_mpd[DiodeNum(diode)][xtalIdx]    = mpd;
      m_mpdErr[DiodeNum(diode)][xtalIdx] = sig;
    }
  }

}; // namespace CalUtil
