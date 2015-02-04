#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include "TwoD.h"
using namespace twodimarray;

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
