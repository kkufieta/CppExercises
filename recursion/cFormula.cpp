// Compute number of ways of choosing r different things from a set 
// of n things:
// C(n, r) = n! / (r!*(n-r)!) , where n! = n*(n-1)*(n-2)*...*1
#include <iostream>
#include <cstdlib>
using std::cout;
using std::endl;

int computeC(int n, int r);
int factorial(int n);

int main() {
  int n(2), r(1);
  cout << "For n = " << n << ", r = " << r
       << ", C(n, r) = " << computeC(n, r) << endl;
  n = 3;
  r = 1;
  cout << "For n = " << n << ", r = " << r
       << ", C(n, r) = " << computeC(n, r) << endl;
  n = 3;
  r = 2;
  cout << "For n = " << n << ", r = " << r
       << ", C(n, r) = " << computeC(n, r) << endl;
  n = 3;
  r = 3;
  cout << "For n = " << n << ", r = " << r
       << ", C(n, r) = " << computeC(n, r) << endl;
  
  return 0;
}

int computeC(int n, int r) {
  // C(n, r) = n! / (r! * (n-r)!)
  if ((n - r) < 0) {
    cout << "C(n,r) with n < r is not defined.\n";
    exit(1);
  }
  double nFactorial = static_cast<double>(factorial(n));
  double rFactorial = static_cast<double>(factorial(r));
  double nMinusRFactorial = static_cast<double>(factorial(n-r));
  return nFactorial / (rFactorial * nMinusRFactorial);
}

int factorial(int n) {
  if (n == 0 || n == 1) {
    return 1;
  } else {
    return factorial(n-1)*n;
  }
}
