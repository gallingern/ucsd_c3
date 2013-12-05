/*
 * Date.cpp
 *
 *  Created on: Oct 16, 2013
 *      Author: Nathaniel Gallinger
 */

#include "Date.h"

// Default Constructor
NathanielGallinger::Date::Date()
{
  // Set date to current date
  const char monthIncrement = 1;
  const int yearAdd = 1900;
  time_t now = time(0);
  struct tm* tm = localtime(&now);
  month = tm->tm_mon + monthIncrement;
  day = tm->tm_mday;
  year = yearAdd + tm->tm_year;
}

// Constructor
NathanielGallinger::Date::Date(int month, int day, int year)
{
  if(checkDate(month, day, year)) {
    this->month = month;
    this->day = day;
    this->year = year;
  }
}

// Display function
void
NathanielGallinger::Date::display()
{
  cout << month << "/" << day << "/" << year << "\n";
}

// Check for valid date
int
NathanielGallinger::Date::checkDate(int month, int day, int year)
{
  const char VALID = 1;
  const char INVALID = 0;
  const char MAX_MONTH = 12;
  const char MIN_MONTH = 1;
  const char MIN_YEAR = 0;
  const char JAN = 1;
  const char FEB = 2;
  const char MAR = 3;
  const char APR = 4;
  const char MAY = 5;
  const char JUN = 6;
  const char JUL = 7;
  const char AUG = 8;
  const char SEP = 9;
  const char OCT = 10;
  const char NOV = 11;
  const char DEC = 12;
  const char MIN_DAY = 1;
  const char MAX_DAY_31 = 31;
  const char MAX_DAY_30 = 30;
  const char MAX_DAY_FEB = 28;

  int retval = VALID;

  // Verify month
  if ((month < MIN_MONTH) || (month > MAX_MONTH)) {
    cerr << "Month " << month << " invalid, must be in the range [1-12]\n";
    retval = INVALID;
  }

  // Verify year
  if (year < MIN_YEAR) {
    cerr << "Year " << year << " not valid, must be greater than or equal to zero\n";
    retval = INVALID;
  }

  // Verify day
  switch (month) {
  // fall through cases for days with 31 days
  case JAN:
  case MAR:
  case MAY:
  case JUL:
  case AUG:
  case OCT:
  case DEC:
    if ((day < MIN_DAY) || (day > MAX_DAY_31)) {
      cerr << "Day " << day << " not valid, must be in the range [1-31]\n";
      retval = INVALID;
    }
    break;
  // fall through cases for days with 30 days
  case APR:
  case JUN:
  case SEP:
  case NOV:
    if ((day < MIN_DAY) || (day > MAX_DAY_30)) {
      cerr << "Day " << day << " not valid, must be in the range [1-30]\n";
      retval = INVALID;
    }
    break;
  // check feb for 28, assume no leap year
  case FEB:
    if ((day < MIN_DAY) || (day > MAX_DAY_FEB)) {
      cerr << "Day " << day << " not valid, must be in the range [1-28]\n";
      retval = INVALID;
    }
    break;
  default:
    //  Invalid month
    retval = INVALID;
    break;
  }

  return retval;
}
