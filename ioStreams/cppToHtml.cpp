// Transforms a *.cpp file into HTML compatible code by changing:
// < into &lt
// > into &gt
// add the tag <PRE> to the beginning of the file
// ad the tag </PRE> to the end of the file

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
using std::ifstream;
using std::ofstream;
using std::endl;
using std::cout;
using std::cin;
using std::string;

void cppToHtml(ifstream& inStream, ofstream& outStream);

int main() {
  ifstream inStream;
  ofstream outStream;
  
  string cppFileName, htmlFileName;
  cout << "Enter the cpp file name: ";
  cin >> cppFileName;
  inStream.open(cppFileName);
  if (inStream.fail()) {
    cout << "Input file opening failed.\n";
    exit(1);
  }
  cout << "Enter the html file name: ";
  cin >> htmlFileName;
  outStream.open(htmlFileName);
  if (outStream.fail()) {
    cout << "Output file opening failed.\n";
    exit(1);
  }

  cppToHtml(inStream, outStream);
  
  inStream.close();
  outStream.close();

  return 0;
}

void cppToHtml(ifstream& inStream, ofstream& outStream) {
  char next;
  inStream.get(next);
  outStream << "<PRE>" << endl;
  while (!inStream.eof()) {
    if (next == '<') {
      outStream << "&lt;";
    } else if (next == '>') {
      outStream << "&gt;";
    } else {
      outStream << next;
    }
    inStream.get(next);
  }
  outStream << endl << "</PRE" << endl;
}
