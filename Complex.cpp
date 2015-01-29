#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

class Complex{
 public:
  Complex() : real(0), imag(0) {};
  Complex(double realValue) : real(realValue), imag(0) {};
  Complex(double realValue, double imagValue);
  friend bool operator ==(const Complex &value1, const Complex &value2);
  friend const Complex operator +(const Complex &value1, 
                                  const Complex &value2);
  friend const Complex operator -(const Complex &value1, 
                                  const Complex &value2);
  friend const Complex operator *(const Complex &value1, 
                                  const Complex &value2);
  friend ostream &operator <<(ostream &outputStream, const Complex &value);
  friend istream &operator >>(istream &inputStream, Complex &value);
 private:
  double real;
  double imag;
};

const Complex i(0, 1);

int main() {
  Complex c1, c2(2), c3(3, 3);
  cout << "c1: " << c1 << endl;
  cout << "c2: " << c2 << endl;
  cout << "c3: " << c3 << endl;
  cout << "c1 * c2 = " << (c1 * c2) << endl;
  cout << "c2 * c3 = " << (c2 * c3) << endl;
  cout << "c1 - c2 = " << (c1 - c2) << endl;
  cout << "c2 - c3 = " << (c2 - c3) << endl;
  cout << "c1 + c2 = " << (c1 + c2) << endl;
  cout << "c2 + c3 = " << (c2 + c3) << endl;

  cout << "Enter an imaginary number: ";
  cin >> c1;
  cout << c1 << endl;
  return 0;
}

Complex::Complex(double realValue, double imagValue) 
                  : real(realValue), imag(imagValue) {};

bool operator ==(const Complex &value1, const Complex &value2) {
  return ((value1.real == value2.real) && (value1.imag && value2.imag));
}

const Complex operator -(const Complex &value1, const Complex &value2) {
  return  Complex((value1.real - value2.real), (value1.imag - value2.imag));
}

const Complex operator +(const Complex &value1, const Complex &value2) {
  return  Complex((value1.real + value2.real), (value1.imag + value2.imag));
}

const Complex operator *(const Complex &value1, const Complex &value2) {
  Complex product;
  // (a1 + b1*i) * (a2 + b2*i) = 
  //    a1*a2 - b1*b2 + (a1*b2 + b1*a2)*i
  product.real = value1.real * value2.real - value1.imag * value2.imag;
  product.imag = value1.real * value2.imag + value1.imag * value2.real;
  return product;
}

ostream &operator <<(ostream &outputStream, const Complex &value) {
  outputStream << value.real;
  if(value.imag >= 0) {
    cout << " + ";
  } else if (value.imag < 0) {
    cout << " - ";
  }
  cout << fabs(value.imag) << "*i";
  return outputStream;
}

istream &operator >>(istream &inputStream, Complex &value) {
  char sign, ignoreMe;
  inputStream >> value.real >> sign >> value.imag >> ignoreMe;
  if (sign == '-') {
    value.imag = - value.imag;
  } else if (sign == '+') {
  } else {
    cerr << "Invalid sign in input.";
    exit(1);
  }
  return inputStream;
}
