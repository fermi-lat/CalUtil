// $Header: /nfs/slac/g/glast/ground/cvs/CalUtil/src/SimpleCalCalib/CalPed.cxx,v 1.1 2008/01/22 20:06:35 fewtrell Exp $

/** @file
    @author Zachary Fewtrell
*/

// LOCAL INCLUDES
#include "CalUtil/SimpleCalCalib/CalPed.h"

// GLAST INCLUDES

// EXTLIB INCLUDES

// STD INCLUDES
#include <fstream>
#include <sstream>

using namespace CalUtil;
using namespace std;

namespace CalUtil {

  const short CalPed::INVALID_PED = -5000;

  CalPed::CalPed() :
    m_peds(RngIdx::N_VALS, INVALID_PED)
  {
  }

  void CalPed::writeTXT(const string &filename) const {
    ofstream outfile(filename.c_str());

    // output header info as comment
    outfile << ";twr lyr col face rng ped sigma" << endl;

    if (!outfile.is_open())
      throw runtime_error(string("Unable to open " + filename));

    for (RngIdx rngIdx; rngIdx.isValid(); rngIdx++)
      if (m_peds[rngIdx] != INVALID_PED)
        outfile << rngIdx.getTwr().val()
                << " " << rngIdx.getLyr().val()
                << " " << rngIdx.getCol().val()
                << " " << rngIdx.getFace().val()
                << " " << rngIdx.getRng().val()
                << " " << m_peds[rngIdx]
                << " " << m_pedSig[rngIdx]
                << endl;
  }

  void CalPed::readTXT(const string &filename) {
    ifstream infile(filename.c_str());

    if (!infile.is_open())
      throw runtime_error(string("Unable to open " + filename));

    string line;
    while (infile.good()) {
      float ped, sig;
      unsigned short twr;
      unsigned short lyr;
      unsigned short col;
      unsigned short face;
      unsigned short rng;

      getline(infile, line);
      if (infile.fail()) break; // bad get

      // check for comments
      if (line[0] == ';')
        continue;

      istringstream istrm(line);

      istrm >> twr
            >> lyr
            >> col
            >> face
            >> rng
            >> ped
            >> sig;

      const RngIdx rngIdx(twr,
                    LyrNum(lyr),
                    col,
                    FaceNum((idents::CalXtalId::XtalFace)face),
                    RngNum(rng));

      m_peds[rngIdx]   = ped;
      m_pedSig[rngIdx] = sig;
    }
  }

}; // namespace CalUtil