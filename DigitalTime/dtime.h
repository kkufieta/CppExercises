// Interface for the class DigitalTime.
// Values of this type are times of day. The values are input and output in
// 24-hour notation, e.g. 9:30 and 14:45.

#ifndef DTIME_H
#define DTIME_H

#include <iostream>
using std::istream;
using std::ostream;

namespace DTimeNS {
  class DigitalTime {
   public:
    DigitalTime(int theHour, int theMinute);
    DigitalTime(); // Initializes the time value to 0:00

    int getHour() const;
    int getMinute() const;
    void advance(int minutesAdded);   
    void advance(int hoursAdded, int minutesAdded);   
    // Changes the time to minutesAdded minutes later.

    friend bool operator ==(const DigitalTime& time1, const DigitalTime& time2);
    friend istream& operator>>(istream& ins, DigitalTime& theObject);
    friend ostream& operator<<(ostream& outs, const DigitalTime& theObject);
    
   private:
    int hour;
    int minute;
  };
} // namespace DTimeNS

#endif // DTIME_H
