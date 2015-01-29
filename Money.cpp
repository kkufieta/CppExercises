#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

class Money{
 public:
  Money();
  Money(double amount);
  Money(int dollarsAmount);
  Money(int dollarsAmount, int centsAmount);
  
  double getAmount() const;
  int getDollars() const;
  int getCents() const;
  friend const Money operator +(const Money &value1, const Money &value2);
  friend const Money operator -(const Money &value1, const Money &value2);
  friend bool operator ==(const Money &value1, const Money &value2);
  friend bool operator <(const Money &value1, const Money &value2);
  friend bool operator >(const Money &value1, const Money &value2);
  friend bool operator <=(const Money &value1, const Money &value2);
  friend bool operator >=(const Money &value1, const Money &value2);
  friend const Money operator -(const Money &value);
  friend ostream &operator <<(ostream &outputStream, const Money &value);
  friend istream &operator >>(istream &inputStream, Money &value);
 private:
  // A negative amount is represented as negative dollars and negative
  // cents. Negative $4.50 is represented as -4 and -50.
  int dollars;
  int cents;

  int dollarsPart(double amount) const;
  int centsPart(double amount) const;
  int round(double number) const;
};

// const Money operator +(const Money &value1, const Money &value2);
// const Money operator -(const Money &value1, const Money &value2);
// bool operator ==(const Money &value1, const Money &value2);
// const Money operator -(const Money &value);

int main() {
  Money m1(1.23);
  Money m2(4, 5);
  Money m3 = -m2;
  Money m4(-4.05);
  cout << "m1: " << m1 << endl;
  cout << "m2: " << m2 << endl;
  cout << "m3 = -m2: " << m3 << endl;
  cout << "m4: " << m4 << endl;
  cout << "m1 == m2: " << (m1 == m2) << endl;
  cout << "m2 == m3: " << (m2 == m3) << endl;
  cout << "m3 == m4: " << (m3 == m4) << endl;

  Money m5;
  cout << "Enter an amount for m5: ";
  cin >> m5;
  cout << m5 << endl;

  cout << "m1 > m2: " << (m1 > m2) << endl;
  cout << "m1 >= m2: " << (m1 >= m2) << endl;
  cout << "m1 < m2: " << (m1 < m2) << endl;
  cout << "m1 <= m2: " << (m1 <= m2) << endl;
  return 0;
}

double Money::getAmount() const {
  return (dollars + cents / 100.0);
}

int Money::getDollars() const {
  return dollars;
}

int Money::getCents() const {
  return cents;
}

int Money::dollarsPart(double amount) const {
  return static_cast<int>(amount);
}

int Money::centsPart(double amount) const {
  int centsPart = static_cast<int>(round((fabs(amount) * 100)) % 100);
  if (amount < 0) {
    centsPart = - centsPart;
  }
  return centsPart;
}
  
int Money::round(double number) const {
  return static_cast<int>(floor(number + 0.5));
}

Money::Money() : dollars(0), cents(0) {};
Money::Money(double amount) : dollars(dollarsPart(amount)), 
                              cents(centsPart(amount)) {};
Money::Money(int dollarsAmount) : dollars(dollarsAmount), cents(0) {};
Money::Money(int dollarsAmount, int centsAmount) {
  if ((dollarsAmount > 0 && centsAmount < 0) || 
        (dollarsAmount < 0 && centsAmount > 0)) {
    cerr << "Inconsistent money data.\n";
    exit(1);
  }
  dollars = dollarsAmount;
  cents = centsAmount;
}

const Money operator +(const Money &value1, const Money &value2) {
  int sumCents = value1.dollars * 100 + value1.cents
                  + value2.dollars * 100 + value2.cents;
  int finalDollars = abs(sumCents) / 100;
  int finalCents = abs(sumCents) % 100;
  if (sumCents < 0) {
    finalDollars = - finalDollars;
    finalCents = - finalCents;
  }
  return Money(finalDollars, finalCents);
}
  
const Money operator -(const Money &value1, const Money &value2) {
  int differenceCents = value1.dollars * 100 + value2.cents
                        - value2.dollars * 100 - value2.cents;
  int finalDollars = abs(differenceCents) / 100;
  int finalCents = abs(differenceCents) % 100;
  if (differenceCents < 0) {
    finalDollars = - finalDollars;
    finalCents = - finalCents;
  }
  return Money(finalDollars, finalCents);
}

bool operator ==(const Money &value1, const Money &value2) {
  return ((value1.dollars == value2.dollars) 
            && (value1.cents == value2.cents));
}

const Money operator -(const Money &value) {
  return Money(-value.dollars, -value.cents);
}

ostream &operator <<(ostream &outStream, const Money &value) {
  if (value.dollars < 0 || value.cents < 0) {
    outStream << "$-";
  } else {
    outStream << "$";
  }
  outStream << abs(value.dollars) << ".";
  if (abs(value.cents) >= 10) {
    outStream << abs(value.cents);
  } else {
    outStream << "0" << abs(value.cents);
  }
  return outStream;
}

istream &operator >>(istream &inputStream, Money &value) {
  double amount;
  inputStream >> amount;
  value.dollars = value.dollarsPart(amount);
  value.cents = value.centsPart(amount);
  return inputStream;
}

bool operator <(const Money &value1, const Money &value2) {
  return ((value1.dollars < value2.dollars) || 
            ((value1.dollars == value2.dollars) 
                && (value1.cents < value2.cents)));
}

bool operator >(const Money &value1, const Money &value2) {
  return ((value1.dollars > value2.dollars) || 
            ((value1.dollars == value2.dollars) 
                && (value1.cents > value2.cents)));
}

bool operator <=(const Money &value1, const Money &value2) {
  return ((value1.dollars <= value2.dollars) || 
            ((value1.dollars == value2.dollars) 
                && (value1.cents <= value2.cents)));
}

bool operator >=(const Money &value1, const Money &value2) {
  return ((value1.dollars >= value2.dollars) || 
            ((value1.dollars == value2.dollars) 
                && (value1.cents >= value2.cents)));
}

