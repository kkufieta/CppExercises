// Header file for the class HourlyEmployee
// Derived from the class Employee

#ifndef HOURLYEMPLOYEE_H
#define HOURLYEMPLOYEE_H

#include <string>
#include "employee.h"
using std::string;

namespace Employees{

class HourlyEmployee : public Employee {
 public:
  HourlyEmployee();
  HourlyEmployee(string newName, string newSsn, 
                  double newPayRate, double newHours);
  // string getName() const;
  // string getSsn() const;
  // void setName(string newName);
  // void setSsn(string newSsn);
  double getHourlyPayRate() const;
  double getHours() const;
  void setHourlyPayRate(double newHourlyPayRate);
  void setHours(double newHours);
  void printPayroll() const;
 private:
  // string name;
  // string ssn; // Social security number
  double hourlyPayRate;
  double hours;
};

} // Employees

#endif // HOURLYEMPLOYEE_H

