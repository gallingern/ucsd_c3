/*
 * Date.h
 *
 *  Created on: Oct 16, 2013
 *      Author: Nathaniel Gallinger
 */

#ifndef DATE_H_
#define DATE_H_

#include <iostream>
using std::cerr;
using std::cout;

#include <ctime>

namespace NathanielGallinger
{
  class Date
  {
  public:
    // Constructor
    Date();
    Date(int month, int day, int year);

    // Accessors and Mutators
    inline int getMonth() const;
    inline int getDay() const;
    inline int getYear() const;

    // Display function
    void display();

  private:
    // Private data members
    int month;
    int day;
    int year;

    // Check for valid date
    int checkDate(int month, int day, int year);
  };

  // Accessors
  inline int Date::getMonth() const
  {
    return month;
  }

  inline int Date::getDay() const
  {
    return day;
  }

  inline int Date::getYear() const
  {
    return year;
  }
}

#endif /* DATE_H_ */
