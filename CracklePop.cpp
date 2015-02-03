#include <iostream>
using namespace std;

void print(const int number);

int main() {
  for (int i = 1; i <= 100; i++) {
    print(i);
  }
  return 0;
}

void print(const int number) {
  if (((number % 3) == 0) && ((number % 5) == 0)) {
    cout << "CracklePop\n";
  } else if ((number % 3) == 0) {
    cout << "Crackle\n";
  } else if ((number % 5) == 0) {
    cout << "Pop\n";
  } else {
    cout << number << endl;
  }
}

