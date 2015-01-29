#include <iostream>
#include <cstdlib>
using namespace std;

class DayOfYear {
  public:
    DayOfYear();
    DayOfYear(int monthValue);
    DayOfYear(int monthValue, int dayValue);
    void input();
    void output();
    int getMonthNumber();
    int getDay();

  private:
    int month;
    int day;
    void testDate();
};

int main() {
  DayOfYear date1(2,21), date2(5), date3;
  cout << "Initialized dates:\n";
  date1.output(); cout << endl;
  date2.output(); cout << endl;
  date3.output(); cout << endl;

  date1 = DayOfYear(10, 31);
  cout << "date1 reset to the following: \n";
  date1.output(); cout << endl;
  
  return 0;
}


DayOfYear::DayOfYear() : month(1), day(1) {
  testDate(); 
}

DayOfYear::DayOfYear(int monthValue) : month(monthValue), day(1) {
  testDate(); 
}

DayOfYear::DayOfYear(int monthValue, int dayValue) 
                        : month(monthValue), day(dayValue) {
  testDate(); 
}

void DayOfYear::input() {
  cout << "Enter the month in numbers (1-12): ";
  cin >> month;
  cout << "Enter the day in numbers (1-31): ";
  cin >> day;
  testDate();
}

void DayOfYear::output() {
  switch(month) {
    case 1:
      cout << "January "; break;
    case 2:
      cout << "February "; break;
    case 3:
      cout << "March "; break;
    case 4: 
      cout << "April "; break;
    case 5:
      cout << "May "; break;
    case 6:
      cout << "June "; break;
    case 7:
      cout << "July "; break;
    case 8:
      cout << "August "; break;
    case 9:
      cout << "September "; break;
    case 10:
      cout << "October "; break;
    case 11:
      cout << "November "; break;
    case 12:
      cout << "December "; break;
    default:
      cout << "Error in DayOfYear::output(). Contact software vendor.\n";
  }
  cout << day;
}

int DayOfYear::getMonthNumber() {
  return month; 
}

int DayOfYear::getDay() {
  return day; 
}

void DayOfYear::testDate() {
  if (month < 1 || month > 13) {
    cout << "Invalid month value.\n";
    exit(1);
  }
  else if (day < 1 || day > 31) {
    cout << "Invalid day value.\n";
    exit(1);
  }
}
