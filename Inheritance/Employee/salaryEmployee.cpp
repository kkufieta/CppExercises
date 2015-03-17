// Implementation file for the class SalaryEmployee
// Derived from the class Employee

#include <string>
#include <iostream>
#include "salaryEmployee.h"
using std::string;
using std::cout;
using std::endl;

namespace Employees{

SalaryEmployee::SalaryEmployee() : Employee(), monthlySalary(0) {}

SalaryEmployee::SalaryEmployee(string newName, 
                  string newSsn, double newSalary) : Employee(newName, newSsn),
                                                     monthlySalary(newSalary) {}

double SalaryEmployee::getMonthlySalary() const {
  return monthlySalary;
}

void SalaryEmployee::setMonthlySalary(double newSalary) {
  monthlySalary = newSalary;
}

void SalaryEmployee::printPayroll() const {
  cout << endl;
  cout << name << ", gets paid $" << monthlySalary
       << " this month.\n";
  cout << endl;
}

} // Employees
