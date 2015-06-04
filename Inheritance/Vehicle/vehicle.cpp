// Implementation file for class Vehicle
#include <string>
#include <iostream>
#include "vehicle.h"
#include "person.h"
using std::string;
using std::cout;
using std::endl;
using People::Person;

namespace Vehicles {

Vehicle::Vehicle() : manufacturer("no manufacturer yet"), numCylinders(0),
                     owner() {};


Vehicle::Vehicle(string newManufacturer, int newNumCylinders, Person newOwner) 
          : manufacturer(newManufacturer), numCylinders(newNumCylinders),
            owner(newOwner) {};

Vehicle::Vehicle(const Vehicle& vSource) {
  manufacturer = vSource.manufacturer;
  numCylinders = vSource.numCylinders;
  owner = vSource.owner;
}

Vehicle& Vehicle::operator=(const Vehicle& vSource) {
  manufacturer = vSource.manufacturer;
  numCylinders = vSource.numCylinders;
  owner = vSource.owner;
  return *this;
}

void Vehicle::print() const {
  cout << "Manufacturer: " << manufacturer << ", number Cylinders: "
       << numCylinders << ", owner: " << owner << endl;
}

}
