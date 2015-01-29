#include <iostream>
#include <cstdlib>
using namespace std;

class Rational{
 public:
  Rational() : nominator(0), denominator(1) {}; 
  Rational(int wholeNumber) : nominator(wholeNumber), denominator(1) {}; 
  Rational(int nominatorValue, int denominatorValue); 
  friend ostream &operator <<(ostream &outputStream, const Rational &value); 
  friend istream &operator >>(istream &inputStream, Rational &value);  
  friend bool operator ==(const Rational &value1, const Rational &value2); 
  friend bool operator <(const Rational &value1, const Rational &value2); 
  friend bool operator >(const Rational &value1, const Rational &value2);
  friend bool operator <=(const Rational &value1, const Rational &value2);
  friend bool operator >=(const Rational &value1, const Rational &value2);
  friend const Rational operator +(const Rational &value1, 
                                   const Rational &value2); 
  friend const Rational operator -(const Rational &value1, 
                                   const Rational &value2); 
  friend const Rational operator *(const Rational &value1, 
                                   const Rational &value2); 
  friend const Rational operator /(const Rational &value1, 
                                   const Rational &value2); 
 private:
  int nominator;
  int denominator;
  void normalize();
};

int main() {
  Rational r1, r2(3), r3(6,4), r4(3,2);
  cout << r1 << ", " << r2 << ", " << r3 << ", " << r4 << endl;
  cout << "r1 == r2: " << (r1 == r2) << endl;
  cout << "r3 == r4: " << (r3 == r4) << endl;
  cout << "r2 < r3: " << (r2 < r3) << endl;
  cout << "r3 < r2: " << (r3 < r2) << endl;
  cout << "r2 > r3: " << (r2 > r3) << endl;
  cout << "r3 > r2: " << (r3 > r2) << endl;
  cout << "r2 <= r3: " << (r2 <= r3) << endl;
  cout << "r3 <= r2: " << (r3 <= r2) << endl;
  cout << "r2 >= r3: " << (r2 >= r3) << endl;
  cout << "r3 >= r2: " << (r3 >= r2) << endl;

  Rational r11(6,2), r22(15,27), r33(-4,-8);
  cout << r11 << ", " << r22 << ", " << r33 << endl;

  cout << "r11 + r22 = " << (r11 + r22) << endl;
  cout << "r22 * r33 = " << (r22 * r33) << endl;
  cout << "r33 / r11 = " << (r33 / r11) << endl;
  
  return 0;
}


Rational::Rational(int nominatorValue, int denominatorValue) {
  nominator = nominatorValue;
  denominator = denominatorValue;
  normalize();
}

void Rational::normalize() {
  if (denominator == 0) {
    cerr << "Division by zero.\n";
    exit(1);
  }
  if ((nominator < 0 && denominator < 0)
      || (nominator > 0 && denominator < 0)) {
    nominator = -nominator;
    denominator = -denominator;
  } 
  for(int i = 2; i <= nominator; i++) {
    if (((nominator % i) == 0) && ((denominator % i) == 0)) {
      nominator = nominator / i;
      denominator = denominator / i;
      i--;
    }
  }
}

ostream &operator <<(ostream &outputStream, const Rational &value) {
  outputStream << value.nominator << "/" << value.denominator;
  return outputStream;
}

istream &operator >>(istream &inputStream, Rational &value) {
  char ignoreMe;
  inputStream >> value.nominator >> ignoreMe >> value.denominator;
  value.normalize();
  return inputStream;
}

bool operator ==(const Rational &value1, const Rational &value2) {
  return ((value1.nominator == value2.nominator) 
            && (value1.denominator == value2.denominator));
}

bool operator <(const Rational &value1, const Rational &value2) {
  return ((value1.nominator * value2.denominator)
            < (value1.denominator * value2.nominator));
}


bool operator >(const Rational &value1, const Rational &value2) {
  return ((value1.nominator * value2.denominator)
            > (value1.denominator * value2.nominator));
}

bool operator <=(const Rational &value1, const Rational &value2) {
  return ((value1.nominator * value2.denominator)
            <= (value1.denominator * value2.nominator));
}


bool operator >=(const Rational &value1, const Rational &value2) {
  return ((value1.nominator * value2.denominator)
            >= (value1.denominator * value2.nominator));
}

const Rational operator +(const Rational &value1, const Rational &value2) {
  int newNominator = value1.nominator * value2.denominator 
                      + value2.nominator * value1.denominator;
  int newDenominator = value1.denominator * value2.denominator;
  Rational newRational(newNominator, newDenominator);
  newRational.normalize();
  return newRational;
}

const Rational operator -(const Rational &value1, const Rational &value2) {
  int newNominator = value1.nominator * value2.denominator 
                      - value2.nominator * value1.denominator;
  int newDenominator = value1.denominator * value2.denominator;
  Rational newRational(newNominator, newDenominator);
  newRational.normalize();
  return newRational;
}

const Rational operator *(const Rational &value1, const Rational &value2) {
  int newNominator = value1.nominator * value2.nominator;
  int newDenominator = value1.denominator * value2.denominator;
  Rational newRational(newNominator, newDenominator);
  newRational.normalize();
  return newRational;
}

const Rational operator /(const Rational &value1, const Rational &value2) {
  int newNominator = value1.nominator * value2.denominator;
  int newDenominator = value1.denominator * value2.nominator;
  Rational newRational(newNominator, newDenominator);
  newRational.normalize();
  return newRational;
}
