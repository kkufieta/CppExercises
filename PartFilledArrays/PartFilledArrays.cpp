#include "PartFilledArrays.h"
#include <iostream>
#include <cstdlib>
using std::cout;

namespace pfa{
  A::A() : capacity(50), used(0) {
    a = new double[capacity];
  }

  A::A(int size) : capacity(size), used(0) {
    a = new double[capacity];
  }

  A::A(const A &object) {
    capacity = object.capacity;
    used = object.used;
    a = new double[capacity];
    for (int i = 0; i < used; i++) {
      a[i] = object.a[i];
    }
  }

  A::~A() {
    delete [] a;
  }

  void A::addElement(double element) {
    if (used >= capacity) {
      cout << "Attempt to exceed capacity in A.\n";
      exit(0);
    }
    a[used] = element;
    used++;
  }

  bool A::full() const {
    return (used == capacity);
  }

  int A::getCapacity() const {
    return capacity;
  }

  int A::getNumberUsed() const {
    return used;
  }

  void A::emptyArray() {
    used = 0;
  }

  double& A::operator[](int index) {
    if (index >= used) {
      cout << "Illegal index in A. \n";
      exit(1);
    }
    return a[index];
  }

  A& A::operator=(const A& right) {
    if (capacity != right.capacity) {
      delete [] a;
      a = new double[right.capacity];
    }
    capacity = right.capacity;
    used = right.used;
    for (int i = 0; i < used; i++) {
      a[i] = right.a[i];
    }
    return *this;
  }
} // namespace pfa
