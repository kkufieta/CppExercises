// Implementation file for class Person
#include <string>
#include <iostream>
#include "person.h"
using std::string;
using std::istream;
using std::ostream;

namespace People {

Person::Person() : name("No name yet") {};

Person::Person(string newName) : name(newName) {};

Person::Person(const Person& pSource) {
  name = pSource.name;
}

Person& Person::operator=(const Person& pSource) {
  name = pSource.name;
  return *this;
}

istream& operator >>(istream& inStream, Person& person) {
  inStream >> person.name;
  return inStream;
}

ostream& operator <<(ostream& outStream, const Person& person) {
  outStream << person.name;
  return outStream;
}
  
} 

