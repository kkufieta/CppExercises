#include <iostream>
using namespace std;

namespace Space1 {
  void greeting() {
    cout << "Hello from space1\n";
  }
}

namespace Space2 {
  void greeting() {
    cout << "Hello from space2\n";
  }
  namespace Space3 {
    void greeting() {
      cout << "Space 3, and I'm confused.\n";
    }
  }
}

void bigGreeting() {
  cout << "biggest greeting ever!\n";
}

int main() {
  Space1::greeting();
  Space2::greeting();
  bigGreeting();
  Space2::Space3::greeting();
  return 0;
}
