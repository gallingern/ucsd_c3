/*
 * Time.cpp
 *
 *  Created on: Nov 17, 2013
 *      Author: Nathaniel Gallinger
 */

#include "Time.h"

// Constructor
Project2::Time::Time(int hours, int minutes, int seconds)
{
  const int MIN_CONV = 60;
  const int HR_CONV = 3600;

  this->seconds = seconds +
                  (minutes * MIN_CONV) +
                  (hours * HR_CONV);
}

// Accessor
int
Project2::Time::getTotalTimeAsSeconds()
{
  return this->seconds;
}

// Overloaded += operator
const Project2::Time &
Project2::Time::operator+=(const Time &rhs)
{
  this->seconds += rhs.seconds;
  return *this;
}

// Overloaded << operator
ostream &
Project2::operator<<(ostream &os, const Time &rhs)
{
  const int MIN_CONV = 60;
  const int HR_CONV = 3600;
  int hours = rhs.seconds/HR_CONV;
  int min = (rhs.seconds - (hours * HR_CONV))/MIN_CONV;
  int sec = rhs.seconds - (hours * HR_CONV) - (min * MIN_CONV);
  os << hours << "h:" << min << "m:" << sec << "s";
  return os;
}
