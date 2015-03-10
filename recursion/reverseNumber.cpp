// Write the argument (positive integer) to the screen backward.
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

void printReversed(int number);
void printReversedIteratively(int number);

int main() {
  int number;
  cout << "Enter a number (integer): ";
  cin >> number;
  printReversed(number);
  cout << endl;
  printReversedIteratively(number);
  cout << endl;
  return 0;
}

void printReversed(int number) {
  if (number < 10) {
    cout << number;
  } else {
    cout << number%10;
    printReversed(number/10);
  }
}

void printReversedIteratively(int number) {
  if (number < 10) {
    cout << number;
  } else {
    while (number != 0) {
      cout << number % 10;
      number = number / 10;
    }
  }
}
