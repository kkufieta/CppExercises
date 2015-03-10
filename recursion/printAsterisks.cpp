// Write out a number of asterisks (*) as given by the parameter
#include <iostream>
#include <cstdlib>
using std::cout;
using std::cin;
using std::endl;

void printAsteriskRecursive(int asterisks);
void printAsteriskIterative(int asterisks);

int main() {
  int asterisks;
  cout << "How many asterisks should we print out? ";
  cin >> asterisks;
  cout << "Recursively: \n";
  printAsteriskRecursive(asterisks);
  cout << endl;
  cout << "Iteratively: \n";
  printAsteriskIterative(asterisks);
  cout << endl;
  
  return 0;
}

void printAsteriskRecursive(int asterisks) {
  if (asterisks  < 1) {
    cout << "Enter a positive number of asterisks.\n";
    exit(1);
  } else if (asterisks == 1) {
    cout << "*";
  } else {
    cout << "*";
    printAsteriskRecursive(asterisks - 1);
  }
}

void printAsteriskIterative(int asterisks) {
  if (asterisks  < 1) {
    cout << "Enter a positive number of asterisks.\n";
    exit(1);
  } else {
    for (int i = 0; i < asterisks; i++) {
      cout << "*";
    }
  }
}
