#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string correctUpperToLowerCase(const string &s);
string correctSpacing(const string &s);
string correctNewLine(const string &s);
string correctSentence(const string &s);

int main() {
  char cline[101];
  string ignoreMe;
  cout << "Enter a sentence that contains a single period at the end: \n";
  cin.get(cline, 101, '.');
  getline(cin, ignoreMe);
  string line = cline;
  line = correctSentence(line);
  cout << line << endl;
  return 0;
}

string correctUpperToLowerCase(const string &s) {
  string temp(s);
  temp.at(0) = static_cast<char>(toupper(temp.at(0)));
  for (int i = 1; i < temp.length(); i++) {
    temp.at(i) = static_cast<char>(tolower(temp.at(i)));
  }
  return temp;
}

string correctSpacing(const string &s) {
  string temp(s);
  char prior, next;
  for (int i = 0; i < temp.length() - 1; i++) {
    prior = temp.at(i);
    next = temp.at(i + 1);
    if ((prior == ' ') && (next == ' ')) {
      temp.erase(i + 1, 1);
      i--;
    }
  }
  return temp;
}

string correctNewLine(const string &s) {
  string temp(s);
  int newLineCharPos = -1;
  for (int i = 0; i < temp.length(); i++) {
    newLineCharPos = temp.find('\n');
    if (newLineCharPos >= 0 && newLineCharPos < temp.length()) {
      temp.at(newLineCharPos) = ' ';
      newLineCharPos = -1;
    }
  }
  return temp;
}

string correctSentence(const string &s) {
  string temp(s);
  temp += '.';
  temp = correctUpperToLowerCase(temp);
  temp = correctNewLine(temp);
  temp = correctSpacing(temp);
  return temp;
}
