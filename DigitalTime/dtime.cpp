#include <iostream>
#include <cstdlib>
#include <cctype>
using namespace std;
#include "dtime.h"

DigitalTime::DigitalTime(int theHour, int theMinute) {
  if (theHour < 0 || theHour > 24 || theMinute < 0 || theMinute > 59) {
    cerr << "Illegal argument to DigitalTime constructor.\n";
    exit(1);
  }
  hour = theHour;
  minute = theMinute;
  if (hour == 24) {
    hour = 0; // Standardize midnight as 0:00
  }
}

DigitalTime::DigitalTime() : hour(0), minute(0) {};

int DigitalTime::getHour() const {
  return hour;
}

int DigitalTime::getMinute() const {
  return minute;
}

void DigitalTime::advance(int minutesAdded) {
  int totalMinutes = minute + minutesAdded;
  minute = totalMinutes % 60;
  hour = (hour + totalMinutes / 60) % 24;
}

void DigitalTime::advance(int hoursAdded, int minutesAdded) {
  hour = (hour + hoursAdded) % 24;
  advance(minutesAdded);
}

bool operator==(const DigitalTime& time1, const DigitalTime& time2) {
  if ((time1.hour == time2.hour) && (time1.minute == time2.minute)) {
    return true;
  } else {
    return false;
  }
}
  


istream& operator>>(istream& ins, DigitalTime& theObject) {
  DigitalTime::readHour(theObject.hour);
  DigitalTime::readMinute(theObject.minute);
  return ins;
}

ostream& operator<<(ostream& outs, const DigitalTime& theObject) {
  outs << theObject.hour << ":";
  if (theObject.minute < 10) {
    outs << "0";
  }  
  outs << theObject.minute;
  return outs;
}

int DigitalTime::digitToInt(char c) {
  return (static_cast<int>(c) - static_cast<int>('0'));
}

void DigitalTime::readHour(int& theHour) {
  char h1, h2;
  cin >> h1 >> h2;
  if (!(isdigit(h1) && (isdigit(h2) || h2 == ':'))) {
    cerr << "Error: illegal input to readHour.\n";
    exit(1);
  }
  if (isdigit(h1) && h2 == ':') {
    theHour = digitToInt(h1);
  } else {
    theHour = digitToInt(h1) * 10 + digitToInt(h2);
    cin >> h1; // Discard ':'
    if (h1 != ':') {
      cerr << "Error: Illegal input to readHour.\n";
      exit(1);
    }
  }
  if (theHour == 24) {
    theHour = 0; // Standardize midnight as 0:00
  } else if (theHour < 0 || theHour > 24) {
      cerr << "Error: Illegal input to readHour.\n";
      exit(1);
    }
}

void DigitalTime::readMinute(int& theMinute) {
  char m1, m2;
  cin >> m1 >> m2;
  if (!(isdigit(m1) && isdigit(m2))) {
    cerr << "Error: illegal input to readMinute\n";
    exit(1);
  }
  theMinute = digitToInt(m1) * 10 + digitToInt(m2);
  if (theMinute < 0 || theMinute > 59) {
    cerr << "Error: illegal input to readMinute\n";
    exit(1);
  }
}
