/*
 * Time.h
 *
 *  Created on: Nov 17, 2013
 *      Author: Nathaniel Gallinger
 */

#ifndef TIME_H_
#define TIME_H_

#include <iostream>
using std::ostream;

namespace Project2
{
  class Time
  {
    friend ostream &operator<<(ostream &os, const Time &rhs);
  public:
    Time(int hours, int minutes, int seconds);
    int getTotalTimeAsSeconds();
    const Time &operator+=(const Time &rhs);
  private:
   int seconds;
  };
}

#endif /* TIME_H_ */
