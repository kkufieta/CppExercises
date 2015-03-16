/* Towers of Hanoi: 
 * A stack of n disks of decreasing size is placed on one of three posts. The 
 * task is to move the disks one at a time from the first post to the second. 
 * To do this, any disk can be moved from any post to any other post, subject 
 * to the rule that you can never place a larger disk over a smaller disk. The 
 * (spare) third post is provided to make the solution possible. Your task is 
 * to write a recursive function that describes instructions for a solution to 
 * this problem. Output a sequence of instructions that will solve the problem.

 * Hint: If you could move (n-1) disks from the first post to the third post 
 * using the second post as a spuare, the last disk could be moved from the 
 * first post to the second post. Then by using the same techique you can move 
 * the (n-1) disks from the third post to the second post, using the first post
 * as a spare. 
*/
#include <iostream>
#include <cstdlib>
using std::cout;
using std::cin;
using std::endl;

void hanoi(int n, char source, char dest, char spare);

int main() {
  int n;
  char source('a'), dest('b'), spare('c');
  cout << source << endl;
  cout << "Choose the number of disks (n >= 1): ";
  cin >> n;
  
  hanoi(n, source, dest, spare);

  return 0;
}

void hanoi(int n, char source, char dest, char spare) {
  if (n == 1) {
    cout << "Move disk " << n << " from post " 
         << source << " to post " << dest << ".\n";
  } else {
    hanoi(n-1, source, spare, dest);
    cout << "Move disk " << n << " from post " 
         << source << " to post " << dest << ".\n";
    hanoi(n-1, spare, dest, source);
  }
}
