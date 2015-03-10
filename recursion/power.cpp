// Program to demonstrate the recursive function power.
#include <iostream>
#include <cstdlib>
using std::cout;
using std::endl;

double power(int x, int n);
// Precondition: n >= 0.
// Returns x to the power of n.
double powerIteratively(int x, int n);

int main() {
  for (int n = -6; n < 6; n++) {
    cout << "3 to the power " << n
         << " is " << power(3, n) << ", " 
         << " is " << powerIteratively(3, n) << endl;
  }
  return 0;
}

double power(int x, int n) {
  if (n < 0) {
    double result = power(x, -n);
    return 1/result;
  } else if (n == 0) {
    return 1;
  } else {
    return x*power(x,n-1);
  }
}

double powerIteratively(int x, int n) {
  if (n < 0) {
    double result = x;
    for (int i = 1; i < -n; i++) {
      result = result * x;
    }
    return 1/result;
  } else if (n == 0) {
    return 1;
  } else {
    double result = x;
    for (int i = 1; i < n; i++) {
      result = result * x;
    }
    return result;
  }
}
      
