/*
 * Date.cpp
 *
 *  Created on: Oct 16, 2013
 *      Author: Nathaniel Gallinger
 */


#include <iostream>
using std::cerr;
using std::cout;

// Class date
class Date
{
public:
  // Constructor
  Date(int month, int day, int year)
  {
    this->month = checkMonth(month);
    this->day = day;
    this->year = year;
  }

  // Accessors and Mutators
  void setMonth(int month)
  {
    this->month = checkMonth(month);
  }

  int  getMonth()
  {
    return month;
  }

  void setDay(int day)
  {
    this->day = day;
  }

  int  getDay()
  {
    return day;
  }

  void setYear(int year)
  {
    this->year = year;
  }

  int  getYear()
  {
    return year;
  }

  // Display function
  void display()
  {
    cout << month << "/" << day << "/" << year << "\n";
  }

private:
  // Private data members
  int month;
  int day;
  int year;

  // Check for valid month
  int checkMonth(int month)
  {
    const char maxMonth = 12;
    const char minMonth = 1;
    int retval = minMonth;
    if ((month >= minMonth) && (month <= maxMonth)) {
      retval = month;
    }
    else {
      cerr << "Month must be in the range [1-12]\n";
    }
    return retval;
  }
};

int main()
{
  // Create date object
  Date date1(12, 12, 12);
  // Display object
  date1.display();

  // Test Accessors and Mutators
  date1.setDay(1);
  date1.setMonth(1);
  date1.setYear(1);
  cout << date1.getMonth() << "/" << date1.getDay() << "/" << date1.getYear() << "\n";
}
