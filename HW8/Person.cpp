/*
 * Person.cpp
 *
 *  Created on: Nov 25, 2013
 *      Author: Nathaniel Gallinger
 */

#include "Person.h"
#include <iomanip>

NathanielGallinger::Person::Person(string firstName,
                                   string lastName,
                                   int  ageYears,
                                   double heightInches,
                                   double weightPounds)
: firstName(firstName),
  lastName(lastName),
  ageYears(ageYears),
  heightInches(heightInches),
  weightPounds(weightPounds)
{
}

// Overloaded stream extraction operator
istream &
NathanielGallinger::operator>>(istream &in, Person &person)
{

  return in;
}

// Overloaded stream insertion operator
ostream &
NathanielGallinger::operator<<(ostream &out, const Person &person)
{
  out << std::fixed << std::showpoint << std::setprecision(2) << person.firstName << " " <<
         std::fixed << std::showpoint << std::setprecision(2) << person.lastName << " " <<
         std::fixed << std::showpoint << std::setprecision(2) << person.ageYears << " " <<
         std::fixed << std::showpoint << std::setprecision(2) << person.heightInches << " " <<
         std::fixed << std::showpoint << std::setprecision(2) << person.weightPounds << "\n";
  return out;
}
