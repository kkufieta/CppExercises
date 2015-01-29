#include <cstdlib>
#include <iostream>
using namespace std;

// TwoD: 2-dimensional dynamic array of doubles
class TwoD {
 public:
  TwoD();
  TwoD(int maxNumberRows, int maxNumberCols);
  TwoD(const TwoD& source); // copy constructor
  ~TwoD();
  TwoD& operator=(const TwoD& source);
  void setEntry(int row, int column, int value);
  double getEntry(int row, int column) const;
  friend const TwoD operator+(const TwoD& matrix1, const TwoD& matrix2);
  void print() const;
 private:
  double** dynArray;
  int maxRows;
  int maxCols;
};

int main() {
  TwoD m1(4,5);
  TwoD m2(4,5);
  TwoD m3(2,2);
  m3.setEntry(0,0,1);
  m3.setEntry(0,1,2);
  m3.setEntry(1,0,3);
  m3.setEntry(1,1,4);
  cout << "Enter the entries for the first 4x5 matrix: \n";
  double entry;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 5; j++) {
      cin >> entry;
      m1.setEntry(i, j, entry);
    }
  }
  cout << "Enter the entries for the second 4x5 matrix: \n";
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 5; j++) {
      cin >> entry;
      m2.setEntry(i, j, entry);
    }
  }
  cout << "Matrix 1: " << endl;
  m1.print();
  cout << "Matrix 2: " << endl;
  m2.print();
  cout << "Matrix 3: " << endl;
  m3.print();

  cout << "m1 + m2 = " << endl;
  TwoD m4(m1 + m2);
  m4.print();

  cout << "m3 = m1 " << endl;
  m3 = m1;
  m3.print();
  return 0;
}

void TwoD::print() const {
  for (int i = 0; i < maxRows; i++) {
    for (int j = 0; j < maxCols; j++) {
      cout << dynArray[i][j] << " ";
    }
    cout << endl;
  }
}

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

// copy constructor
TwoD::TwoD(const TwoD& source) {
  maxRows = source.maxRows;
  maxCols = source.maxCols;
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
  if ((maxRows != source.maxRows) || (maxCols != source.maxCols)) {
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

const TwoD operator+(const TwoD& matrix1, const TwoD& matrix2) {
  if ((matrix1.maxRows != matrix2.maxRows) || 
        (matrix1.maxCols != matrix2.maxCols)) {
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
      

