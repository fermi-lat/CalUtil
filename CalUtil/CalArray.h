// $Header: /nfs/slac/g/glast/ground/cvs/CalUtil/src/test/test_CalUtil.cxx,v 1.13 2007/05/25 21:08:14 fewtrell Exp $
#ifndef CalArray_h
#define CalArray_h

// LOCAL INLUDES
#include "CalDefs.h"

// GLAST INCLUDES

// EXTLIB INCLUDES

// STD INCLUDES

namespace CalUtil {
  /** \brief Standard C array wrapper restricts array indexing to specified type.

  \author Zachary Fewtrell
      
  - intended for use w/ index classes from CalDefs.h.
  - allows for some STL algorithm operations


  \note initial size of array is idx_type::N_VALS
  \note initial array values are unitialized.

  

  \param idx_type array index type.
  \param val_type array value type.
  */
  template <typename idx_type, typename val_type >
  class CalArray {
  public:
    val_type& operator[](const idx_type &idx) {
      return m_dat[idx.val()];}

    const val_type& operator[](const idx_type &idx) const {
      return m_dat[idx.val()];
    }

    /// element wise += operation with all values on rhs
    CalArray<idx_type,val_type> operator+=(const CalArray<idx_type,val_type> &rhs) {
      val_type *lh(begin());
      const val_type *rh(rhs.begin());
      while (lh != end()) {
        *lh += *rh;
        lh++; rh++;
      }
      
      return *this;
    }
      
    /// return size of array
    size_t size() const {return idx_type::N_VALS;}

    /// return pointer to 1st val in array.  good for use w/ STL algs
    val_type *begin() {return m_dat;}
    /// return const pointer to 1st val in array.  good for use w/ STL algs
    const val_type *begin() const {return m_dat;}

    /// return pointer to 1 val past end of array.  god for use w/ STL algs
    val_type *end() {return m_dat + size();}
    /// return const pointer to 1 val past end of array.  god for use w/ STL algs
    const val_type *end() const {return m_dat + size();}

  private:
    /// internal array data
    val_type m_dat[idx_type::N_VALS];
      
  }; 

};

#endif
