// Implementation file for the class HourlyEmployee
// Derived from the class Employee

#include <string>
#include <iostream>
#include "hourlyEmployee.h"
using std::string;
using std::cout;
using std::endl;

namespace Employees{

HourlyEmployee::HourlyEmployee() : Employee(), hourlyPayRate(0), hours(0){}

HourlyEmployee::HourlyEmployee(string newName, string newSsn,
  double newPayRate, double newHours) : Employee(newName, newSsn), 
                                        hourlyPayRate(newPayRate), 
                                        hours(newHours) {}

double HourlyEmployee::getHourlyPayRate() const {
  return hourlyPayRate;
}

double HourlyEmployee::getHours() const {
  return hours;
}

void HourlyEmployee::setHourlyPayRate(double newHourlyPayRate) {
  hourlyPayRate = newHourlyPayRate;
}

void HourlyEmployee::setHours(double newHours) {
  hours = newHours;
}

void HourlyEmployee::printPayroll() const {
  cout << endl;
  cout << name << ", worked " << hours << " hours.\n"
       << "With a hourly pay rate of " << hourlyPayRate
       << " the net pay is $" << hourlyPayRate * hours << endl;
  cout << endl;
}

} // Employees

