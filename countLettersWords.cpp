// Read in a line of text
// Output the number of words in the line & the number of occurences of each letter
// Define a word to be any string of letters that is delimited at each end by either:
// - whitespace, a period, a comma, or the beginning or end of line

// Assumption: input consists entirely of letters, whitespace, commas, periods.

// count uppercase and lowercase versions of a letter as the same letter.

// Output the letters in alphabetical order

#include <iostream>
#include <string>
using namespace std;

const string DELIMITER(" .,!:?\n");

string toLowerCase(const string &line);
int countWords(const string &line);
void countLetters(const string &line);
string deleteDelimiters(const string &line);


int main() {
  string line;
  cout << "Enter a line of text (that consists entirely "
       << "of letters, whitespace, \ncommas, periods):\n";
  getline(cin, line);
  line += "\n";
  line = toLowerCase(line);
  cout << line << endl;
  int numberWords = countWords(line);
  cout << numberWords << " words\n";
  countLetters(line);
  return 0;
}

string toLowerCase(const string &line) {
  string temp(line);
  for (int i = 0; i < temp.length(); i++) {
    temp.at(i) = static_cast<char>(tolower(temp.at(i)));
  }
  return temp;
}

int countWords(const string &line) {
  char prior, next;
  int counter = 0;
  int indexPrior = -1;
  int indexNext = -1;
  for (int i = 0; i < line.length() - 1; i++) {
    indexPrior = -1;
    indexNext = -1;
    prior = line.at(i);
    next = line.at(i + 1);
    //cout << prior << " ... " << next ;
    indexPrior = DELIMITER.find(prior);
    indexNext = DELIMITER.find(next);
    if (indexNext >= 0 && indexNext < line.length() && indexPrior == -1) {
      counter++;
    }
    //cout << " ... " << counter << endl;
  }
  return counter;
}

string deleteDelimiters(const string &line) {
  string temp(line);
  char letter;
  char delimiter;
  for (int i = 0; i < temp.length(); i++) {
    letter = temp.at(i);
    for (int j = 0; j < DELIMITER.length(); j++) {
      delimiter = DELIMITER.at(j);
      if (letter == delimiter) {
        temp.erase(i, 1);
        i--;
      }
    }
  }
  return temp;
}

void countLetters(const string &line) {
  string temp = deleteDelimiters(line);
  string output, nextOutput; 
  string alphabet("abcdefghijklmnopqrstuvwxyz");
  char nextAlphabet, nextLetter;
  int counter(0);
  for (int i = 0; i < alphabet.length(); i++) {
    counter = 0;
    nextAlphabet = alphabet.at(i);
    for (int j = 0; j < temp.length(); j++) {
      nextLetter = temp.at(j);
      if (nextAlphabet == nextLetter) {
        counter++;
      }
    }
    if (counter > 0) {
      cout << counter << " " << nextAlphabet << endl;
    }
  }
}
