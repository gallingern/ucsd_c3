/*
 * hw2.cpp
 *
 *  Created on: Oct 16, 2013
 *      Author: Nathaniel Gallinger
 */

#include "Date.h"

using NathanielGallinger::Date;

int main()
{
  // Create date object and specify numbers
  cout << "Constructor with arguments 12, 12, 12: \n";
  Date date1(12, 12, 12);
  // Display object
  date1.display();

  // Test Accessors
  cout << "Accessor functions returning first object: \n";
  cout << date1.getMonth() << "/" << date1.getDay() << "/" << date1.getYear() << "\n";

  // Create date object with default constructor
  cout << "Default constructor returning today's date: \n";
  Date date2;
  date2.display();

  // Test error cases
  cout << "Attempt to call constructor with invalid arguments: \n";
  cout << "Case 1: 13, 2, 1900 \n";
  Date date3(13, 2, 1900);
  cout << "Case 2: 12, 34, 1900 \n";
  Date date4(12, 34, 1900);
  cout << "Case 3: 12, 15, -5 \n";
  Date date5(12, 15, -5);
}
