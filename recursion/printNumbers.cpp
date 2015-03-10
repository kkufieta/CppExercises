// Print the numbers from 1 to n, where n is given as a parameter
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

void printNumbers(int n);

int main() {
  int n;
  cout << "Enter a number (integer): ";
  cin >> n;
  printNumbers(n);
  
  return 0;
}

void printNumbers(int n) {
  if (n == 1) {
    cout << n << endl;
  } else {
    printNumbers(n-1);
    cout << n << endl;
  }
}
