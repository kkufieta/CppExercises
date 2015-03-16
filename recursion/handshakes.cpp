/* We have n people in a room, where int n >= 1. 
 * Each person shakes hands once with every other person. What is the total 
 * number, h(n) of handshakes?
 * e.g. handshakes(1) = 0, handshakes(2) = 1, ...
 */
#include <iostream>
#include <cstdlib>
using std::cout;
using std::cin;
using std::endl;

int handshakes(int n);

int main() {
  for (int i = 1; i <= 10; i++) {
    cout << "Total # of handshakes with " << i
         << " people in a room is "
         << handshakes(i) << endl;
  }

  return 0;
}

int handshakes(int n) {
  if (n < 1) {
    cout << "The number of people in the room must be >= 1.\n";
    exit(1);
  } else if (n == 1) {
    return 0;
  } else {
    return (n-1) + handshakes(n-1);
  }
}
