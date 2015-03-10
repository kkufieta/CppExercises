// BINARY SEARCH
// Given: Array of ints: a[size=n], with a[0] <= a[1] <= a[2] <= ... <= a[n-1]
// Task: Find an item in the array and return the index, or determin that the
// item is not in the array.

// Binary search: 
// Set the "key" as the element that we are seeking after.
// Split the array in two subarrays by determining the "middle".
// Check if the middle == key. If not, check if key > or < middle.
// Search the respective subarray (> middle or < middle), 
// and neglect the other subarray.
// Repeat the procedure for the subarray at hand.

#include <iostream>
#include <assert.h>
using std::cout;
using std::cin;
using std::endl;
const int ARRAY_SIZE = 10;

bool binarySearch(const int a[], int key, int startIndex, int endIndex, 
                    int& keyIndex);
// Implementation from the book:
void search(const int a[], int first, int last, int key, 
              bool& found, int& location);
// Precondition: a[first] through a[last] are sorted in increasing order.
// Postcondition: if key is not one of the values a[first] through a[last],
// then found == false; otherwice, a[location] == key and found == true.

void testBinarySearch();


int main() {
  int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int aSize = 10;
  int key(9), keyIndex(-1), startIndex(0), endIndex(aSize - 1);
  bool found;
  // Search for key in a[]. Return true if key is found
  // and set index to the position of the key. Return false
  // if the key is not found.
  found = binarySearch(a, key, startIndex, endIndex, keyIndex);
  if (found == true) {
    cout << "The key " << key << " was found in a at the index "
         << keyIndex << endl;
  } else {
    cout << "The key " << key << " could not be found in a.\n";
  }
  
  /*
  cout << "Testing the binary search: \n";
  testBinarySearch();
  */

  // Program from the book that tests "search(..)"
  int b[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  const int finalIndex = ARRAY_SIZE - 1;
  int location;
  cout << "Enter a number to be located: ";
  cin >> key;
  search(b, 0, finalIndex, key, found, location);
  if (found) {
    cout << key << " is in index location " << location << endl;
  } else {
    cout << key << " is not in the array." << endl;
  }
  
  return 0;
}

bool binarySearch(const int a[], int key, int startIndex, int endIndex, 
                    int& keyIndex) {
  cout << "Searching in a (sub)string, with start index "
       << startIndex << " and end index " << endIndex << endl;
  bool found = false;
  int midIndex = -1;
  // If startIndex > endIndex, then key is not in the list.
  if (startIndex > endIndex) {
    found = false;
  } else {
    midIndex = (startIndex + endIndex)/2;
    if (key == a[midIndex]) {
      found = true;
      keyIndex = midIndex;
    } else if (key > a[midIndex]) {
      startIndex = midIndex + 1;
      found = binarySearch(a, key, startIndex, endIndex, keyIndex);
    } else if (key < a[midIndex]) {
      endIndex = midIndex - 1;
      found = binarySearch(a, key, startIndex, endIndex, keyIndex);
    }
  }
  return found;
}

void search(const int a[], int first, int last, int key,
              bool& found, int& location) {
  int mid;
  if (first > last) {
    found = false;
  } else {
    mid = (first + last)/2;
    if (key == a[mid]) {
      found = true;
      location = mid;
    } else if (key < a[mid]) {
      search(a, first, mid - 1, key, found, location);
    } else if (key > a[mid]) {
      search(a, mid + 1, last, key, found, location);
    }
  }
}
  



void testBinarySearch() {
  int sizeA(10), sizeB(0), sizeC(1);
  int a[] = {2, 14, 15, 39, 50, 421, 555, 890, 1000, 10000};
  int b[] = {};
  int c[] = {0};

  cout << "Test case 1: \n";
  bool found = false;
  int keyIndex = -1;
  found = binarySearch(a, 15, 0, sizeA-1, keyIndex);
  assert(found == true);
  assert(keyIndex == 2);

  cout << "Test case 2: \n";
  found = false;
  keyIndex = -1;
  found = binarySearch(a, 900, 0, sizeA-1, keyIndex);
  assert(found == false);
  assert(keyIndex == -1);

  cout << "Test case 3: \n";
  found = false;
  keyIndex = -1;
  found = binarySearch(a, 1, 5, 8, keyIndex);
  assert(found == false);
  assert(keyIndex == -1);

  cout << "Test case 4: \n";
  found = false;
  keyIndex = -1;
  found = binarySearch(a, 890, 5, 8, keyIndex);
  assert(found == true);
  assert(keyIndex == 7);

  cout << "Test case 5: \n";
  found = false;
  keyIndex = -1;
  found = binarySearch(b, 890, 5, 8, keyIndex);
  assert(found == false);
  assert(keyIndex == -1);

  cout << "Test case 6: \n";
  found = false;
  keyIndex = -1;
  found = binarySearch(b, 1, 0, sizeB, keyIndex);
  assert(found == false);
  assert(keyIndex == -1);

  cout << "Test case 7: \n";
  found = false;
  keyIndex = -1;
  found = binarySearch(c, 1, 0, sizeC-1, keyIndex);
  assert(found == false);
  assert(keyIndex == -1);

  cout << "Test case 8: \n";
  found = false;
  keyIndex = -1;
  found = binarySearch(c, 0, 0, 1, keyIndex);
  assert(found == true);
  assert(keyIndex == 0);
  
}
