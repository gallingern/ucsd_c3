/*
 * Person.h
 *
 *  Created on: Nov 25, 2013
 *      Author: Nathaniel Gallinger
 */

#ifndef PERSON_H_
#define PERSON_H_

#include <string>
using std::string;

#include <iostream>
using std::istream;
using std::ostream;

namespace NathanielGallinger
{
  class Person
  {
    // friend function stream operator overloads
    friend istream &operator>>(istream &in, Person &person);
    friend ostream &operator<<(ostream &out, const Person &person);
  public:
    // Constructor
    Person(string firstName,
           string lastName,
           int ageYears,
           double heightInches,
           double weightPounds);
  private:
    // Private data members
    string firstName;
    string lastName;
    int ageYears;
    double heightInches;
    double weightPounds;
  };

  // friend function stream operator overloads
  istream &operator>>(istream &in, Person &person);
  ostream &operator<<(ostream &out, const Person &person);
}

#endif /* PERSON_H_ */
