#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include "PartFilledArrays.h"
using namespace pfa;

void testA();

int main() {
  cout << "This program tests the class A.\n";
  char ans;
  do {
    testA();
    cout << "Test again? (y/n) ";
    cin >> ans;
  } while (ans == 'Y' || ans == 'y');

  return 0;
}

void testA() {
  int cap;
  cout << "Enter capacity of this array: ";
  cin >> cap;
  A temp(cap);
  
  cout << "Enter up to " << cap << " nonnegative numbers.\n";
  cout << "Place a negative number at the end.\n";

  double next;
  cin >> next;
  while ((next >= 0 && (!temp.full()))) {
    temp.addElement(next);
    cin >> next;
  }
  cout << "You entered the following " << temp.getNumberUsed() 
       << " numbers: \n";
  int count = temp.getNumberUsed();
  for (int i = 0; i < count; i++) {
    cout << temp[i] << " ";
  }
  cout << endl;
}
