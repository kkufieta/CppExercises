// Header file for class Truck
// Derived from the class Vehicle
#ifndef TRUCK_H
#define TRUCK_H

#include <string>
#include "vehicle.h"
#include "person.h"
using std::string;
using People::Person;

namespace Vehicles {

class Truck : public Vehicle {
 public:
  Truck();
  Truck(string newManufacturer, int newNumCylinders, Person newOwner, 
        double newLoadCapacity, int newTowingCapacity);
  // copy constructor
  Truck(const Truck& tSource);
  // overloaded assignment operator
  Truck& operator=(const Truck& tSource);
  void print() const;
 protected:
  double loadCapacity;
  int towingCapacity;
  // string manufacturer;
  // int numCylinders;
  // Person owner;
};

}


#endif // TRUCK_H
