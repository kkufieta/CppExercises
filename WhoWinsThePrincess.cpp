/*
n suitors, remove every 3rd suitor until only one is left
*/
#include <vector>
#include <iostream>
using namespace std;

int getWinner(int suitors);
void printVector(const vector<int> &v);

int main() {
  int n;
  cout << "How many suitors are there? ";
  cin >> n;
  
  int winner = getWinner(n);
  cout << "The winner is: " << winner << endl;

  return 0;
}
  
int getWinner(int suitors) {
  vector<int> v(suitors);
  for (int i = 0; i < suitors; i++) {
    v[i] = i + 1;
  }
  printVector(v);

  int modulo = 0;
  int modulo_temp = (v.size() + modulo) % 3;
  int i = 0;
  while(v.size() > 1) {
    for(i = 2 - modulo; i < v.size(); i = i + 2) {
      v.erase(v.begin() + i);
      printVector(v);
    }
    modulo = modulo_temp;
    modulo_temp = (v.size() + modulo) % 3;
  }
  
  return v[0];
}

void printVector(const vector<int> &v) {
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << endl;
}
  
  
