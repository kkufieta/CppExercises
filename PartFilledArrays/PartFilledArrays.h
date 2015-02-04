#ifndef PFA_H
#define PFA_H

namespace pfa {
  class A {
   public:
    A();
    A(int size);
    A(const A &object);
    ~A(); // Destructor

    void addElement(double element);
    // Precondition: The array is not full.
    // Postcondition: The element has been added.

    bool full() const;
    // Returns true if the array is full, false otherwise.
    
    int getCapacity() const;
    int getNumberUsed() const;
    void emptyArray(); // Empties the array

    double& operator[](int index);
    // Read and change access to elements 0 through numberUsed - 1.

    A& operator =(const A& right); // Overloaded assignment operator
    
   private:
    double *a; // Array of doubles
    int capacity; // Size of the array
    int used; // Number of array positions currently in use
  };
} // namespace pfa

#endif // PFA_H
