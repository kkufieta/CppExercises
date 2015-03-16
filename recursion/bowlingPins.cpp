/* Consider a frame of bowling pins, where the 1st row has 1 pin,
 * the 2nd row has 2 pins, the 3rd row has 3 pins, and so on.
 * Write a recursive function that takes as input the number of rows, n
 * and outputs the total number of pins that would exist in a pyramid with
 * n rows.
 */
#include <iostream>
#include <cstdlib>
using std::cout;
using std::cin;
using std::endl;

int pins(int n);

int main() {
  for (int n = 1; n <= 10; n++) {
    cout << "A pyramid with " << n
         << " rows has " << pins(n) << " pins.\n";
  }

  return 0;
}

int pins(int n) {
  if (n < 1) {
    cout << "The number of rows must be >= 1.\n";
    exit(1);
  } else if (n == 1) {
    return 1;
  } else {
    return n + pins(n-1);
  }
}
