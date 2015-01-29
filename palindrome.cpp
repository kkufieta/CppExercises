// Test for palindrome property.
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void swap(char &ch1, char &ch2);
string reverse(const string &s);
string removePunct(const string &s);
string makeLower(const string &s);
bool isPalindrome(const string &s);

int main() {
  string str;
  cout << "Enter a candidate for palindrome test\n"
       << "followed by pressing Return.\n";
  getline(cin, str);

  if (isPalindrome(str)) {
    cout << "\"" << str << "\" is a palindrome.";
  } else {
    cout << "\"" << str << "\" is not a palindrome.";
  }
  cout << endl;

  return 0;
}

void swap(char &ch1, char &ch2) {
  char temp = ch1;
  ch1 = ch2;
  ch2 = temp;
}

string reverse(const string &s) {
  int start = 0;
  int end = s.length() - 1;
  string temp(s);
  while (start < end) {
    swap(temp[start], temp[end]);
    start++;
    end--;
  }
  return temp;
}

string removePunct(const string &s) {
  string punct(",;:.?!'\" "); // includes a blank
  string noPunct(s);
  int index(-1);
  for (int i = 0; i < punct.length(); i++) {
    for (int j = 0; j < noPunct.length(); j++) {
      index = noPunct.find(punct[i], j);
      if (index >= 0 && index < noPunct.length()) {
        // cout << noPunct.find(punct) << endl;
        // cout << noPunct[index] << endl;
        noPunct.erase(index, 1);
        j = --index;
      }
    }
  }
  // cout << noPunct << endl;
  return noPunct;
}

string makeLower(const string &s) {
  string temp(s);
  for (int i = 0; i < temp.length(); i++) {
    temp.at(i) = static_cast<char>(tolower(temp.at(i)));
  }
  return temp;
}

bool isPalindrome(const string &s) {
  string temp = removePunct(s);
  temp = makeLower(temp);
  cout << temp << endl;
  cout << reverse(temp) << endl;
  return (temp == reverse(temp));
}
