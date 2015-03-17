/* Program to test the base class "Employee" and its
 * derived classes "HourlyEmployee" and "SalaryEmployee"
 */

#include <iostream>
#include <string>
#include "hourlyEmployee.h"
#include "salaryEmployee.h"
using std::cout;
using std::endl;
using std::string;
using Employees::HourlyEmployee;
using Employees::SalaryEmployee;

int main() {
  HourlyEmployee employeeOne("Jenny", "123456", 15, 30);
  SalaryEmployee employeeTwo("Benny", "987653", 5000);

  employeeOne.printPayroll();
  employeeTwo.printPayroll();

  employeeOne.setName("Jelly Jenny");
  employeeOne.setSsn("123");
  employeeOne.setHours(40*4);

  employeeTwo.setName("Belly Benny");
  employeeTwo.setSsn("456");
  employeeTwo.setMonthlySalary(10600);
  employeeOne.printPayroll();
  employeeTwo.printPayroll();
  
  return 0;
}

