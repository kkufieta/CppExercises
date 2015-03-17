// Implementation file for the class Employee
#include <string>
#include <iostream>
#include <cstdlib>
#include "Employee.h"
using std::string;
using std::cout;

namespace Employees{

Employee::Employee() : name("no name yet"), 
                       ssn("no social security number yet") {}

Employee::Employee(string newName, string newSsn) : name(newName),
                                                    ssn(newSsn) {}

string Employee::getName() const {
  return name;
}

string Employee::getSsn() const {
  return ssn;
}

void Employee::setName(string newName) {
  name = newName;
}

void Employee::setSsn(string newSsn) {
  ssn = newSsn;
}

void Employee::printPayroll() const {
  cout << "Error: printPayroll called for an unidentified employee.\n";
  exit(1);
}

} // Employees

