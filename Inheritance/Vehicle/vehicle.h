// Header file for class Vehicle
#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include "person.h"
using std::string;
using People::Person;

namespace Vehicles {

class Vehicle {
 public:
  Vehicle();
  Vehicle(string newManufacturer, int newNumCylinders, Person newOwner);
  // copy constructor
  Vehicle(const Vehicle& vSource);
  // overloaded assignment operator
  Vehicle& operator=(const Vehicle& vSource);
  void print() const;
 protected:
  string manufacturer;
  int numCylinders;
  Person owner;
};

}


#endif // VEHICLE_H
