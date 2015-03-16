/* Savings account:
 * Initial deposit, plus interest rate per year.
 * Calculate the accumulated deposit over the years.
 * Verify: Amount should be equal to P(1+i)^n, where P: amound initially saved,
 * i: interest rate per year, n: number of years.
*/


// This program uses floats to represent the money (does not represent
// real-world money correctly). 

#include <iostream>
#include <assert.h>
#include <cmath>
using std::cout;
using std::endl;

double savings(double P, double i, int n);
void assertP(double newP, double P, double i, int n);

int main() {
  double P(1000), i(0.1), newP(0);
  cout << "The initial amount is $" << P << ", and the interest is "
       << i << "%.\n";
  for (int n = 0; n < 20; n++) {
    newP = savings(P, i, n);
    assertP(newP, P, i, n);
    cout << "The amount is " << newP << " after " << n << " years.\n";
  }
  return 0;
}

double savings(double P, double i, int n) {
  if (n == 0) {
    return P;
  } else {
    return savings(P*(1+i), i, n-1);
  }
}

void assertP(double newP, double P, double i, int n) {
    double knownP = P * pow(1 + i,n);
    newP = newP * 1000;
    knownP = knownP * 1000;
    int pNew = static_cast<int>(newP);
    int pKnown = static_cast<int>(knownP);
    assert(pNew == pKnown);
}
