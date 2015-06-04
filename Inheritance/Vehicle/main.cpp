#include <string>
#include <iostream>
#include "vehicle.h"
#include "truck.h"
#include "person.h"
using std::string;
using std::cout;
using std::endl;
using People::Person;
using Vehicles::Vehicle;
using Vehicles::Truck;

int main() {
  Vehicle car;
  Truck truck;
  Person Karl;

  car.print();
  truck.print();
  cout << Karl << endl;

  Vehicle car1("Ford", 5, Person("Kathi"));
  Truck truck1("VW", 10, Person("Kjetil"), 10.1, 1000);
  Person Karl2("Karl");

  car1.print();
  truck1.print();
  cout << Karl2 << endl;

  car = car1;
  truck = truck1;
  Karl = Karl2;

  car.print();
  truck.print();
  cout << Karl << endl;

  car = truck;
  car.print();

  return 0;
}
