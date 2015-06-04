/* Program to test the base class "Employee" and its
 * derived classes "HourlyEmployee" and "SalaryEmployee"
 */

#include <iostream>
#include <string>
#include "hourlyEmployee.h"
#include "salaryEmployee.h"
#include "administrator.h"
using std::cout;
using std::endl;
using std::string;
using Employees::HourlyEmployee;
using Employees::SalaryEmployee;
using Employees::Administrator;

int main() {
  HourlyEmployee employeeOne("Jenny", "123456", 15, 30);
  SalaryEmployee employeeTwo("Benny", "987653", 5000);
  Administrator admin("Admin", "123", 10000, "title", "comparea", "supervisor");
  admin.print();
  admin.printPayroll();
  admin.setSupervisor("BOSS");
  admin.print();

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

