// Implementation file for class Truck
#include <string>
#include "vehicle.h"
#include "truck.h"
#include "person.h"
using std::string;
using std::cout;
using std::endl;
using People::Person;

namespace Vehicles {

Truck::Truck() : Vehicle(), loadCapacity(0), towingCapacity(0) {};

Truck::Truck(string newManufacturer, int newNumCylinders, Person newOwner, 
             double newLoadCapacity, int newTowingCapacity) :
              Vehicle(newManufacturer, newNumCylinders, newOwner), 
              loadCapacity(newLoadCapacity), towingCapacity(newTowingCapacity)
              {};

Truck::Truck(const Truck& tSource) : Vehicle(tSource) { 
  loadCapacity = tSource.loadCapacity;
  towingCapacity = tSource.towingCapacity;
  // manufacturer = tSource.manufacturer;
  // numCylinders = tSource.numCylinders;
  // owner = tSource.owner;
}

Truck& Truck::operator=(const Truck& tSource) {
  Vehicle::operator=(tSource);
  loadCapacity = tSource.loadCapacity;
  towingCapacity = tSource.towingCapacity;
  // manufacturer = tSource.manufacturer;
  // numCylinders = tSource.numCylinders;
  // owner = tSource.owner;
  return *this;
}

void Truck::print() const {
  Vehicle::print();
  cout << "Load capacity: " << loadCapacity << ", towing capacity: "
       << towingCapacity << endl;
}

}
