/* Recursive function that has one parameter n of type int and that returns
 * the nth Fibonacci number:
 * F0 = 1, F1 = 1, F2 = 2, F3 = 3, F4 = 5
 * F(i+2) = F(i) + F(i+1) for i = 0, 1, 2, ...
 */


/* Timing fibonacci recursive vs. iterative (real, user):
 *                  Iterative (real, user)  Recursive (real, user)
 * 1st Fibonacci:   0m0.011s, 0m0.001s             
 * 3rd Fibonacci:   0m0.004s, 0m0.001s
 * 5th Fibonacci:   0m0.004s, 0m0.001s
 * 7th Fibonacci:   0m0.004s, 0m0.001s
 * 9th Fibonacci:   0m0.004s, 0m0.001s
 * 11th Fibonacci:  0m0.004s, 0m0.001s
 * 13th Fibonacci:  0m0.004s, 0m0.001s
 * 15th Fibonacci:  0m0.003s, 0m0.001s
 */

#include <iostream>
#include <cstdlib>
#include <assert.h>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

long long fibonacciRecursive(long long n);
long long fibonacciIterative(long long n);
long long fibonacciRecursiveImproved(long long n);
long long calcFibonacci(long long n, long long fib[]);
void checkFibonacci();


int main(int argc, char* argv[]) {
  if (argc != 3) {
    cout << "usage: fibonacci iterative|recursive|recursive_improved number\n";
    exit(1);
  }
  string method = argv[1];
  string number = argv[2];
  int n = atoi(number.c_str()); 
  if (method == "iterative") {
    cout << fibonacciIterative(n) << endl;
  } else if (method == "recursive") {
    cout << fibonacciRecursive(n) << endl;
  } else if (method == "recursive_improved") {
    cout << fibonacciRecursiveImproved(n) << endl;
  } else {
    cout << "usage: fibonacci iterative|recursive number\n";
    exit(1);
  }
    
  return 0;
}

long long fibonacciRecursive(long long n) {
  if (n < 0) {
    cout << "Invalid parameter for the fibonacci function.\n";
    exit(1);
  } else if (n == 0 || n == 1) {
    return 1;
  } else {
    return (fibonacciRecursive(n-2) + fibonacciRecursive(n-1));
  }
}

long long fibonacciRecursiveImproved(long long n) {
  if (n < 0) {
    cout << "Invalid parameter for the fibonacci function.\n";
    exit(1);
  }
  long long fib[n + 1];
  return calcFibonacci(n, fib);
}

long long calcFibonacci(long long n, long long fib[]) {
  if (n == 0) {
    fib[0] = 1;
    return fib[n];
  } else if (n == 1) {
    fib[0] = 1;
    fib[1] = 1;
    return fib[n];
  } else {
    fib[n-1] = calcFibonacci(n-1, fib);
    fib[n] = fib[n-2] + fib[n-1];
    return fib[n];
  }
}

    
long long fibonacciIterative(long long n) {
  if (n < 0) {
    cout << "Invalid parameter for the fibonacci function.\n";
    exit(1);
  } else if (n == 0 || n == 1) {
    return 1;
  } else {
    long long previous = 1;
    long long current = 1;
    long long next = 0;
    for (long long i = 2; i <= n; i++) {
      next = previous + current;
      previous = current;
      current = next;
    }
    return next;
  }
}
    
