#include <iostream>
#include <cstdlib>
using namespace std;

class IntPair {
 public:
  IntPair() : first(0), second(0) {};
  IntPair(int firstValue, int secondValue);
  IntPair operator ++(); // Prefix version
  IntPair operator ++(int); // Postfix version
  void setFirst(int newValue);
  void setSecond(int newValue);
  int getFirst() const;
  int getSecond() const;
  friend ostream &operator <<(ostream &outputStream, const IntPair pair);
  friend istream &operator >>(istream &inputStream, IntPair pair);
 private:
  int first;
  int second;
};

int main() {
  IntPair a(1,2);
  cout << "Postfix a++: Start value of object a: " << a << endl;
  IntPair b = a++;
  cout << "Value returned: " << b << endl;
  cout << "Changed object: " << a << endl;

  a = IntPair(1,2);
  cout << "Prefix ++a: Start value of object a: " << a << endl;
  IntPair c = ++a;
  cout << "Value returned: " << c << endl;
  cout << "Changed object: " << a << endl;
  
  return 0;
}

IntPair::IntPair(int firstValue, int secondValue)
                  : first(firstValue), second(secondValue) {};

IntPair IntPair::operator ++() {
  first++;
  second++;
  return IntPair(first, second);
}

IntPair IntPair::operator ++(int ignoreMe) {
  int temp1 = first;
  int temp2 = second;
  first++;
  second++;
  return IntPair(temp1, temp2);
}

void IntPair::setFirst(int newValue) {
  first = newValue;
}

void IntPair::setSecond(int newValue) {
  second = newValue;
}

int IntPair::getFirst() const {
  return first;
}

int IntPair::getSecond() const {
  return second;
}

ostream &operator <<(ostream &outputStream, const IntPair pair) {
  outputStream << "(" << pair.first << "," << pair.second << ")";
  return outputStream;
}

istream &operator >>(istream &inputStream, IntPair pair) {
  char ignoreMe;
  inputStream >> ignoreMe >> pair.first >> ignoreMe
              >> pair.second >> ignoreMe;
  return inputStream;
}
