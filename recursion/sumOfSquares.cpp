#include <iostream>
using std::cout;
using std::endl;

int sumOfSquares(int n);
// Precondition: n >= 1
// Returns the sum of the squares of the numbers 1 through n.

int main() {
  for (int n = 1; n <= 5; n++) {
    cout << "The sum of squares from 1 to " << n
         << " is: " << sumOfSquares(n) << endl;
  }
  return 0;
}

int sumOfSquares(int n) {
  if (n == 1) {
    return 1;
  } else {
    return (sumOfSquares(n-1) + n*n);
  }
}


