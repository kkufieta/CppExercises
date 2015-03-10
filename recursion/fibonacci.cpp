// Recursive function that has one parameter n of type int and that returns
// the nth Fibonacci number:
// F0 = 1, F1 = 1, F2 = 2, F3 = 3, F4 = 5
// F(i+2) = F(i) + F(i+1) for i = 0, 1, 2, ...

#include <iostream>
#include <cstdlib>
#include <assert.h>
using std::cout;
using std::cin;
using std::endl;

int fibonacci(int n);
void checkFibonacci();

int main() {
  checkFibonacci();
  for (int n = 0; n <= 11; n++) {
    cout << "The fibonacci of " << n << " is " << fibonacci(n)
         << endl;
  }
  
  return 0;
}

int fibonacci(int n) {
  if (n < 0) {
    cout << "Invalid parameter for the fibonacci function.\n";
    exit(1);
  } else if (n == 0 || n == 1) {
    return 1;
  } else {
    return (fibonacci(n-2) + fibonacci(n-1));
  }
}

void checkFibonacci() {
  // According to wikipedia:
  assert(fibonacci(0) == 1);
  assert(fibonacci(1) == 1);
  assert(fibonacci(2) == 2);
  assert(fibonacci(3) == 3);
  assert(fibonacci(4) == 5);
  assert(fibonacci(5) == 8);
  assert(fibonacci(6) == 13);
  assert(fibonacci(7) == 21);
  assert(fibonacci(8) == 34);
  assert(fibonacci(9) == 55);
  assert(fibonacci(10) == 89);
  assert(fibonacci(11) == 144);
}
