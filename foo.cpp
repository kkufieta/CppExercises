#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class Student {
 public:
  Student();
  Student(string studentName);
  Student(const Student& source);
  ~Student();
  void addStudent(string studentName, int numberClasses, string classes[]);
  void addClasses(int numberClasses, string classes[]);
  void print() const;
  void resetClasses();
  Student& operator=(const Student& source);
 private:
  string name;
  int numClasses;
  string *classList;
};

int main() {
  Student s1("kathi"), s2("kjetil"), s3;
  string classes1[] = {"pups", "pipi", "kaka", "vann"};
  string classes2[] = {"pupss", "pipis", "kakas", "vanns", "ostekake"};
  s1.addClasses(4, classes1);
  s2.addClasses(5, classes2);
  s1.print();
  s2.print();
  s3.print();
  Student s4(s1);
  s1 = s2;
  s1.print();
  s2.print();
  s4.print();
  s4.resetClasses();
  
  return 0;
}

Student::Student() : name(""), numClasses(1) {
  classList = new string[numClasses];
}

Student::Student(string studentName) : name(studentName), numClasses(1) {
  classList = new string[numClasses];
}

Student::Student(const Student& source) {
  name = source.name;
  numClasses = source.numClasses;
  classList = new string[numClasses];
  for (int i = 0; i < numClasses; i++) {
    classList[i] = source.classList[i];
  }
}

Student::~Student() {
  delete [] classList;
}

void Student::addStudent(string studentName, int numberClasses, 
                                                  string classes[]) {
  name = studentName;
  if (numClasses != numberClasses) {
    delete [] classList;
    numClasses = numberClasses;
    classList = new string[numClasses];
  }
  for (int i = 0; i < numClasses; i++) {
    classList[i] = classes[i];
  }
}

void Student::addClasses(int numberClasses, string classes[]) {
  if (numClasses != numberClasses) {
    delete [] classList;
    numClasses = numberClasses;
    classList = new string[numClasses];
  }
  for (int i = 0; i < numClasses; i++) {
    classList[i] = classes[i];
  }
}

void Student::print() const {
  cout << "Name: " << name << endl;
  cout << "Classes: ";
  for (int i = 0; i < numClasses; i++) {
    cout << classList[i] << ", ";
  }
  cout << endl;
}

void Student::resetClasses() {
  numClasses = 0;
  delete [] classList;
}

Student& Student::operator=(const Student& source) {
  name = source.name;
  if (numClasses != source.numClasses) {
    delete [] classList;
    numClasses = source.numClasses;
    classList = new string[numClasses];
  }
  for (int i = 0; i < numClasses; i++) {
    classList[i] = source.classList[i];
  }
  return *this;
}
