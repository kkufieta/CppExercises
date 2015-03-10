#include <iostream>
using std::cout;
using std::endl;

void writeVertical(int n);
// Precondition: n >= 0.
// Postcondition: The number n is written to the screen vertically, 
// with each digit on a separate line.
void writeVerticalIterative(int n);

int main() {
  int n1(1), n2(12), n3(123), n4(1234);
  cout << "Recursive: \n";
  writeVertical(n1);
  cout << endl;
  writeVertical(n2);
  cout << endl;
  writeVertical(n3);
  cout << endl;
  writeVertical(n4);
  
  cout << "Iterative: \n";
  writeVerticalIterative(n1);
  cout << endl;
  writeVerticalIterative(n2);
  cout << endl;
  writeVerticalIterative(n3);
  cout << endl;
  writeVerticalIterative(n4);
  
  return 0;
}

void writeVertical(int n) {
  if (n < 10) {
    cout << n << endl;
  } else {  // n is two or more digits long
    writeVertical(n/10);
    cout << (n%10) << endl;
  }
}
  
void writeVerticalIterative(int n) {
  if (n < 10) {
    cout << n << endl;
  } else {
    int tens = 1;
    int leftEndPiece = n;
    while (leftEndPiece > 9) {
      tens = tens*10;
      leftEndPiece = leftEndPiece / 10;
    }
    for (int i = tens; i > 0; i = i/10) {
      cout << n / i << endl;
      n = n % i;
    }
  }
}
