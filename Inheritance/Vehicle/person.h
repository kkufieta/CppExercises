// Header file for class Person
#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>
using std::string;
using std::istream;
using std::ostream;

namespace People {

class Person {
 public:
  Person();
  Person(string newName);
  Person(const Person& pSource);
  Person& operator=(const Person& pSource);
  friend istream& operator >>(istream& inStream, Person& person);
  friend ostream& operator <<(ostream& outStream, const Person& person);
 private:
  string name;
};

} 

#endif // PERSON_H
