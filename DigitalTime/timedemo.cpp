#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include "dtime.h"
using namespace DTimeNS;

int main() {
  DigitalTime time1, time2;
  cout << "Enter the time in 24-hour notation: ";
  cin >> time1;
  
  time2 = time1;
  time2.advance(15);
  cout << "You entered " << time1
       << ", 15 minutes later the time will be " << time2 << endl;
  
  time2.advance(2, 15);
  cout << "2 hours and 15 minutes later after that the time will be "
       << time2 << endl;

  return 0;
}
