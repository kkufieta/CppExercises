// Header file for the class Administrator
// Derived from the class SalaryEmployee

#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include <string>
#include "salaryEmployee.h"
using std::string;

namespace Employees{

class Administrator : public SalaryEmployee {
 public:
  Administrator();
  Administrator(string newName, string newSsn, double newSalary,
                string newTitle, string newCompanyArea, string newSupervisor);
  void setSupervisor(string newSupervisor);
  void print() const;
  void printPayroll() const;
  // SalaryEmployee();
  // SalaryEmployee(string newName, string newSsn, double newSalary);
  // string getName() const;
  // string getSsn() const;
  // void setName(string newName);
  // void setSsn(string newSsn);
  // double getMonthlySalary() const;
  // void setMonthlySalary(double newSalary);
 protected:
  string title;
  string companyArea;
  string supervisor;
  double annualSalary;
  // string name;
  // string ssn; // Social security number
  // double monthlySalary;
};

} // Employees

#endif // ADMINISTRATOR_H


