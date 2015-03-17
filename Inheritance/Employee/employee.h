// Header file for the class Employee

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
using std::string;

namespace Employees{

class Employee {
 public:
  Employee();
  Employee(string newName, string newSsn);
  string getName() const;
  string getSsn() const;
  void setName(string newName);
  void setSsn(string newSsn);
  void printPayroll() const;
 public:
  string name;
  string ssn; // Social security number
};

} // Employees

#endif // EMPLOYEE_H
