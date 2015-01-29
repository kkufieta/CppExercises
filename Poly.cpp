#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;
// Dynamic arrays: polynomial class with polynomial addition, subtraction, multiplication

// coefficient and corresponding exponent. 
// Array of doubles that stores the coefficient, the index of the array is the exponent of the corresponding term
// (Represent polynomials of high degree with many missing terms: Sparse matrix techniques)

// polynomial = p, constant = c:
// Provide these operatoins:
// p + p, c + p, p + c, p - p, c - p, p - c, p * p, c * p, p * c

// Supply functions to assign and extract coefficients, indexed by exponent.
// Function to evaluate the polynomial at a value of type double.
// Decide whether to implement these functions as members, friends or standalone functions.

class Poly {
 public:
  Poly();
  Poly(double c);
  Poly(double a[], int size);
  Poly(const Poly& source);
  ~Poly();
  Poly& operator=(const Poly& source);
  friend const Poly operator+(const Poly& p1, const Poly& p2);
  friend const Poly operator-(const Poly& p1, const Poly& p2);
  friend const Poly operator*(const Poly& p1, const Poly& p2);
  friend ostream& operator<<(ostream& output, const Poly& p);
  void setCoefficient(double coefficient, int exponent);
  double getCoefficient(const int& exponent) const;
  double evaluate(double x) const;
  void print() const;
 private:
  double* coefficients;
  int numberCoeff;
};

int main() {
  Poly p1;
  Poly p2(3);
  double a[] = {1, -2, 3, 4};
  double b[] = {50, 0, 1};
  Poly p3(a, 4);
  Poly p4(b, 3);
  cout << "p1: " << p1 << endl;
  cout << "p2: " << p2 << endl;
  cout << "p3: " << p3 << endl;
  cout << "p4: " << p4 << endl;
  cout << "------------------------------" << endl;

  Poly p5 = p1 + p2 + p3;
  cout << "p5 = p1 + p2 + p3: \n" << "p5: " << p5 << endl;
  
  Poly p6 = p1 - p2;
  cout << "p1 - p2\n" << p6 << endl;
  p6 = p2 - p2;
  cout << "p2 - p2\n" << p6 << endl;
  p6 = p2 - p1;
  cout << "p2 - p1\n" << p6 << endl;
  cout << "p4 - p3: " << (p4 - p3) << endl;
  cout << "p1 * p3: " << (p1 * p3) << endl;
  cout << "p2 * p3: " << (p2 * p3) << endl;
  cout << "p4 * p3: " << (p4 * p3) << endl;
  return 0;
}

ostream& operator<<(ostream& output, const Poly& p) {
  p.print();
  return output;
}

// numberCoeff = n + 1:
// p_n = a_n x^n + a_(n-1) x^(n-1) + ... + a_2 x^2 + a_1 x^1 + a_0
// p_0 = c --> a_0 = c, numberCoeff = 1

void Poly::print() const {
  bool firstNonZero = false;
  for (int i = 0; i < numberCoeff; i++) {
    if (coefficients[numberCoeff - i - 1] != 0) {
      firstNonZero = true;
      cout << coefficients[numberCoeff - i - 1];
      if ((numberCoeff - i - 1) != 0)  {
        cout << "x^" << numberCoeff - i - 1 ;
      }
    }
    if (firstNonZero && (i < (numberCoeff - 1))) {
      cout << " + ";
    }
  }
  if (firstNonZero == false) {
    cout << "0";
  }
}

Poly::Poly() : numberCoeff(1) {
  coefficients = new double[numberCoeff];
  coefficients[0] = 0;
}

Poly::Poly(double c) : numberCoeff(1) {
  coefficients = new double[numberCoeff];
  coefficients[0] = c;
}

Poly::Poly(double a[], int size) : numberCoeff(size) {
  coefficients = new double[numberCoeff];
  for (int i = 0; i < numberCoeff; i++) {
    coefficients[i] = a[i];
  }
}

Poly::Poly(const Poly& source) {
  if (numberCoeff != source.numberCoeff) {
    delete [] coefficients;
    numberCoeff = source.numberCoeff;
    coefficients = new double[numberCoeff];
  }
  for (int i = 0; i < numberCoeff; i++) {
    coefficients[i] = source.coefficients[i];
  }
}
    
Poly::~Poly() {
  delete [] coefficients;
}

Poly& Poly::operator=(const Poly& source) {
  if (numberCoeff != source.numberCoeff) {
    delete [] coefficients;
    numberCoeff = source.numberCoeff;
    coefficients = new double[numberCoeff];
  }
  for (int i = 0; i < numberCoeff; i++) {
    coefficients[i] = source.coefficients[i];
  }
  return *this;
}

const Poly operator+(const Poly& p1, const Poly& p2) {
  Poly sum;
  if (p1.numberCoeff >= p2.numberCoeff) {
    sum.numberCoeff = p1.numberCoeff;
  } else {
    sum.numberCoeff = p2.numberCoeff;
  }
  delete [] sum.coefficients;
  sum.coefficients = new double[sum.numberCoeff];
  for (int i = 0; i < sum.numberCoeff; i++) {
    sum.coefficients[i] = 0;
    if (i < p1.numberCoeff) {
      sum.coefficients[i] += p1.coefficients[i];
    }
    if (i < p2.numberCoeff) {
      sum.coefficients[i] += p2.coefficients[i];
    }
  }
  return sum;
}

const Poly operator-(const Poly& p1, const Poly& p2) {
  Poly diff;
  if (p1.numberCoeff >= p2.numberCoeff) {
    diff.numberCoeff = p1.numberCoeff;
  } else {
    diff.numberCoeff = p2.numberCoeff;
  }
  delete [] diff.coefficients;
  diff.coefficients = new double[diff.numberCoeff];
  for (int i = 0; i < diff.numberCoeff; i++) {
    diff.coefficients[i] = 0;
    if (i < p1.numberCoeff) {
      diff.coefficients[i] += p1.coefficients[i];
    }
    if (i < p2.numberCoeff) {
      diff.coefficients[i] -= p2.coefficients[i];
    }
  }
  return diff;
}

const Poly operator*(const Poly& p1, const Poly&p2) {
  Poly product;
  product.numberCoeff = p1.numberCoeff + p2.numberCoeff;
  delete [] product.coefficients;
  product.coefficients = new double[product.numberCoeff];
  for (int i = 0; i < product.numberCoeff; i++) {
    product.coefficients[i] = 0;
  }
  for (int i = 0; i < p1.numberCoeff; i++) {
    for (int j = 0; j < p2.numberCoeff; j++) {
      product.coefficients[i + j] += p1.coefficients[i] * p2.coefficients[j];
    }
  }
  return product;
}
      


void Poly::setCoefficient(double coefficient, int exponent) {
  if (exponent >= numberCoeff) {
    cerr << "This polynomnial does not have such a high exponent.";
    exit(0);
  } else {
    coefficients[exponent] = coefficient;
  }
}

double Poly::getCoefficient(const int& exponent) const {
  if (exponent >= numberCoeff) {
    cerr << "This polynomnial does not have such a high exponent.";
    exit(0);
  } else {
    return coefficients[exponent];
  }
}

double Poly::evaluate(double x) const {
  double result = 0;
  for (int i = 0; i < numberCoeff; i++) {
    result += coefficients[i] * pow(x,i);
  }
  return result;
}
