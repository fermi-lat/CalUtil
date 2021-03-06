// $Header: /nfs/slac/g/glast/ground/cvs/CalUtil/src/SimpleCalCalib/ADC2NRG.cxx,v 1.1 2008/04/21 20:11:15 fewtrell Exp $

/** @file ADC2NRG.cxx
    @author Zachary Fewtrell
*/

// LOCAL INCLUDES
#include "CalUtil/SimpleCalCalib/ADC2NRG.h"

// GLAST INCLUDES

// EXTLIB INCLUDES

// STD INCLUDES
#include <fstream>
#include <sstream>

//using namespace CalUtil;
using namespace std;


namespace CalUtil {

  const float ADC2NRG::INVALID_ADC2NRG = -5000;

  ADC2NRG::ADC2NRG() :
    m_adc2nrg(RngIdx::N_VALS, INVALID_ADC2NRG)
  {
  }

  void ADC2NRG::writeTXT(const std::string &filename) const {
    ofstream outfile(filename.c_str());

    // output header info as comment
    outfile << ";twr lyr col face rng adc2nrg" << endl;

    if (!outfile.is_open())
      throw runtime_error(string("Unable to open " + filename));

    for (RngIdx rngIdx; rngIdx.isValid(); rngIdx++)
      outfile << rngIdx.getTwr().val()
              << " " << rngIdx.getLyr().val()
              << " " << rngIdx.getCol().val()
              << " " << rngIdx.getFace().val()
              << " " << rngIdx.getRng().val()
              << " " << m_adc2nrg[rngIdx]
              << endl;
  }

  void ADC2NRG::readTXT(const std::string &filename) {
    ifstream infile(filename.c_str());

    if (!infile.is_open())
      throw runtime_error(string("Unable to open " + filename));

    string line;
    while (infile.good()) {
      float adc2nrg;
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
            >> adc2nrg;

      const RngIdx rngIdx(twr,
                          LyrNum(lyr),
                          col,
                          FaceNum((idents::CalXtalId::XtalFace)face),
                          rng);

      m_adc2nrg[rngIdx] = adc2nrg;
    }
  }

}; // namespace CalUtil
