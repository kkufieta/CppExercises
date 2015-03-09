// Reads all the numbers in the file rawdata.dat and writes the numbers
// to the screen and to the file neat.dat in a neatly formatted way.

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
using std::ifstream;
using std::ofstream;
using std::cout;
using std::endl;
using std::ios;
using std::setw;

void makeNeat(ifstream& messyFile, ofstream& neatFile,
              int numberAfterDecimalpoint, int fieldWidth);
// Precondition: The streams messyFile and neatFile have been connected
// to two different files. The file named messyFile contains only
// floating-point numbers.
// Postcondition: The numbers in the file connected to messyFile have been 
// written to the screen and to the file connected to the stream neatFile. 
// The numbers are written one per line, in fixed-point notation (i.e. not in 
// e-notation), with numberAfterDecimalpoint digits after the decimal point; 
// each number is preceded by a plus or minus sign and each number is in a 
// field of width fieldWidth. (This function does not close the file.)

int main() {
  ifstream messyFile("rawdata.txt");
  ofstream neatFile("neat.txt");
  if (messyFile.fail()) {
    cout << "Input file opening failed.\n";
    exit(1);
  }
  if (neatFile.fail()) {
    cout << "Output file opening failed.\n";
    exit(1);
  }

  makeNeat(messyFile, neatFile, 5, 12);

  messyFile.close();
  neatFile.close();

  cout << "End of program.\n";


  return 0;
}

void makeNeat(ifstream& messyFile, ofstream& neatFile, 
              int numberAfterDecimalpoint, int fieldWidth) {
  neatFile.setf(ios::fixed);
  neatFile.setf(ios::showpos);
  neatFile.setf(ios::showpoint);
  neatFile.precision(numberAfterDecimalpoint);

  cout.setf(ios::fixed);
  cout.setf(ios::showpos);
  cout.setf(ios::showpoint);
  cout.precision(numberAfterDecimalpoint);

  double next;
  messyFile >> next;
  while (!messyFile.eof()) {
    cout << setw(fieldWidth) << next << endl;
    neatFile << setw(fieldWidth) << next << endl;
    messyFile >> next;
  }
}
