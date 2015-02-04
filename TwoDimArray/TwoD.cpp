#include <iostream>
#include <cstdlib>
using std::cout;
using std::cerr;
using std::endl;
#include "TwoD.h"

namespace twodimarray{

TwoD::TwoD() : maxRows(50), maxCols(50) {
  dynArray = new double*[maxRows];
  for (int i = 0; i < maxRows; i++) {
    dynArray[i] = new double[maxCols];
  }
}

TwoD::TwoD(int maxNumberRows, int maxNumberCols) :
            maxRows(maxNumberRows), maxCols(maxNumberCols) {
  dynArray = new double*[maxRows];
  for (int i = 0; i < maxRows; i++) {
    dynArray[i] = new double[maxCols];
  }
}

TwoD::TwoD(const TwoD& source) : 
            maxRows(source.maxRows), maxCols(source.maxCols) {
  dynArray = new double*[maxRows];
  for (int i = 0; i < maxRows; i++) {
    dynArray[i] = new double[maxCols];
  }
  for (int i = 0; i < maxRows; i++) {
    for (int j = 0; j < maxCols; j++) {
      dynArray[i][j] = source.dynArray[i][j];
    }
  }
}

TwoD::~TwoD() {
  for (int i = 0; i < maxRows; i++) {
    delete [] dynArray[i];
  }
  delete [] dynArray;
}

TwoD& TwoD::operator=(const TwoD& source) {
  if (maxRows != source.maxRows || maxCols != source.maxCols) {
    for (int i = 0; i < maxRows; i++) {
      delete [] dynArray[i];
    }
    delete [] dynArray;
    maxRows = source.maxRows;
    maxCols = source.maxCols;
    dynArray = new double*[maxRows];
    for (int i = 0; i < maxRows; i++) {
      dynArray[i] = new double[maxCols];
    }
  }
  for (int i = 0; i < maxRows; i++) {
    for (int j = 0; j < maxCols; j++) {
      dynArray[i][j] = source.dynArray[i][j];
    }
  }
  return *this;
}

void TwoD::setEntry(int row, int column, int value) {
  dynArray[row][column] = value;
}

double TwoD::getEntry(int row, int column) const {
  return dynArray[row][column];
}


  //friend const TwoD operator+(const TwoD& matrix1, const TwoD& matrix2);
const TwoD operator+(const TwoD& matrix1, const TwoD& matrix2) {
  if (matrix1.maxRows != matrix2.maxRows || 
        matrix1.maxCols != matrix2.maxCols) {
    cerr << "Both arrays must have the same dimensions "
         << "prior to their addition.\n";
    exit(0);
  }
  TwoD sum(matrix1.maxRows, matrix1.maxCols);
  for (int i = 0; i < sum.maxRows; i++) {
    for (int j = 0; j < sum.maxCols; j++) {
      sum.dynArray[i][j] = matrix1.dynArray[i][j] + matrix2.dynArray[i][j];
    }
  }
  return sum;
}

void TwoD::print() const {
  for (int i = 0; i < maxRows; i++) {
    for (int j = 0; j < maxCols; j++) {
      cout << dynArray[i][j] << " ";
    }
    cout << endl;
  }
}

} // namespace twodimarray
