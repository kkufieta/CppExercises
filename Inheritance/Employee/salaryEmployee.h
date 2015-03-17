// Header file for the class SalaryEmployee
// Derived from the class Employee

#ifndef SALARYEMPLOYEE_H
#define SALARYEMPLOYEE_H

#include <string>
#include "employee.h"
using std::string;

namespace Employees{

class SalaryEmployee : public Employee {
 public:
  SalaryEmployee();
  SalaryEmployee(string newName, string newSsn, double newSalary);
  // string getName() const;
  // string getSsn() const;
  // void setName(string newName);
  // void setSsn(string newSsn);
  double getMonthlySalary() const;
  void setMonthlySalary(double newSalary);
  void printPayroll() const;
 private:
  // string name;
  // string ssn; // Social security number
  double monthlySalary;
};

} // Employees

#endif // SALARYEMPLOYEE_H

