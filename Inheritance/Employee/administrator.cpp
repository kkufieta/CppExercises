// Implementation file for the class Administrator

#include <string>
#include <iostream>
#include "administrator.h"
using std::string;
using std::cout;
using std::endl;

namespace Employees{

Administrator::Administrator() : SalaryEmployee(), title("No title yet"), 
                                companyArea("No company area yet"),
                                supervisor("No supervisor yet"), 
                                annualSalary(0) {}

Administrator::Administrator(string newName, string newSsn, double newSalary,
                string newTitle, string newCompanyArea, string newSupervisor) :
                SalaryEmployee(newName, newSsn, newSalary), title(newTitle),
                companyArea(newCompanyArea), supervisor(newSupervisor), 
                annualSalary(newSalary * 12) {}


void Administrator::setSupervisor(string newSupervisor) {
  supervisor = newSupervisor;
}


void Administrator::print() const {
  cout << "Title: " << title << ", name: " << name << endl;
  cout << "Company Area: " << companyArea << ", supervisor: " 
       << supervisor << endl;
  cout << "SSN: " << ssn << ", annual salary: " << annualSalary << endl;
}

void Administrator::printPayroll() const {
  cout << endl;
  cout << name << ", gets paid $" << annualSalary
       << " this year.\n";
  cout << endl;
}

/*

class Administrator : public SalaryEmployee {
 public:
  Administrator();
  Administrator(string newName, string newSsn, double newSalary,
                string newTitle, string newCompanyArea, string newSupervisor);
  void setSupervisor(string newSupervisor) const;
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
*/

} // Employees

