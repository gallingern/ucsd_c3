/*
 * hw8.cpp
 *
 *  Created on: Nov 25, 2013
 *      Author: Nathaniel Gallinger
 */

#include "Person.h"
#include <fstream>
#include <iostream>
using namespace std;

int main()
{
  //stringstream output;
  string temp;
  ifstream input ("hw8-input.txt");

  if (input.is_open()) {
    while (getline(input, temp)) {
      cout << temp << endl;
    }
    input.close();
  }
}
