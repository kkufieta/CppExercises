// Objects of this class are partially filled arrays of doubles.

#include <iostream>
using namespace std;

class A {
 public:
  A();
  A(int size);
  A(const A &object);
  
  void addElement(double element);
  // Precondition: The array is not full.
  // Postcondition: The element has been added.

  bool full() const {return (capacity == used);}
  // Returns true if the array is full, false otherwise.

  int getCapacity() const {return capacity;}
  int getNumberUsed() const {return used;}

  void emptyArray() {used = 0;}
  // Empties the array

  double& operator[](int index);
  // Read and change access to elements 0 through numberUsed - 1.

  A& operator =(const A& right); // Overloaded assignment operator

  ~A(); // Destructor

 private:
  double *a; // Array of doubles
  int capacity; // Size of the array
  int used; // Number of array positions currently in use
};

void testA();

int main() {
  cout << "This program tests the class A.\n";
  char ans;
  do {
    testA();
    cout << "Test again? (y/n) ";
    cin >> ans;
  } while((ans == 'y') || (ans == 'Y'));

  return 0;
}

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

void A::addElement(double element) {
  if (used >= capacity) {
    cout << "Attempt to exceed capacity in A.\n";
    exit(0);
  }
  a[used] = element;
  used++;
}

double& A::operator[](int index) {
  if (index >= used) {
    cout << "Illegal index in A.\n";
    exit(0);
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

A::~A() {
  delete [] a;
}

void testA() {
  int cap;
  cout << "Enter capacity of this array: ";
  cin >> cap;
  A temp(cap);

  cout << "Enter up to " << cap << " nonnegative numbers.\n";
  cout << "Place a negative number at the end.\n";
  
  double next;
  cin >> next;
  while ((next >= 0) && (!temp.full())) {
    temp.addElement(next);
    cin >> next;
  }
  cout << "You entered the following " << temp.getNumberUsed() 
       << " numbers:\n";
  int count = temp.getNumberUsed();
  for (int i = 0; i < count; i++) {
    cout << temp[i] << " ";
  }
  cout << endl;
}
