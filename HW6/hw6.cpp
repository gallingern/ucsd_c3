/*
 * hw6.c
 *
 *  Created on: Nov 12, 2013
 *      Author: Nathaniel Gallinger
 */
#include "Array.h"
#include <iostream>
#include <stdexcept>

using std::cerr;
using std::cout;
using std::invalid_argument;
using namespace NathanielGallinger;

int main()
{
  const char ARRAY_LENGTH = 5;

  // Default constructor
  Array<int, ARRAY_LENGTH> arrayOfFiveInts;

  // Modify with L-value subscript operator
  for (int idx = 0; idx < ARRAY_LENGTH; idx++) {
    arrayOfFiveInts[idx] = idx;
  }

  // Output with R-value subscript operator
  for (int idx = 0; idx < ARRAY_LENGTH; idx++) {
    cout << arrayOfFiveInts[idx] << "\n";
  }

  // Const array using copy constructor
  const Array<int, ARRAY_LENGTH> constArray(arrayOfFiveInts);

  // Test copy assignment operator
  Array<int, ARRAY_LENGTH> arrayOfFiveInts2;
  arrayOfFiveInts2 = arrayOfFiveInts;

  // Compare arrays using == and !=
  cout << "Are these == ? : " << (arrayOfFiveInts2 == arrayOfFiveInts) << "\n";
  cout << "Are these != ? : " << (arrayOfFiveInts2 != arrayOfFiveInts) << "\n";

  // L-value access < 0
  try
  {
    arrayOfFiveInts[-1] = 10;
  }
  catch (invalid_argument &ex)
  {
    cerr << ex.what() << "\n";
  }

  // L-value access >= SIZE< 0
  try
  {
    arrayOfFiveInts[ARRAY_LENGTH] = 10;
  }
  catch (invalid_argument &ex)
  {
    cerr << ex.what() << "\n";
  }

  // R-value access < 0
  try
  {
    cout << arrayOfFiveInts[-1] << "\n";
  }
  catch (invalid_argument &ex)
  {
    cerr << ex.what() << "\n";
  }

  // R-value access >= SIZE
  try
  {
    cout << arrayOfFiveInts[ARRAY_LENGTH] << "\n";
  }
  catch (invalid_argument &ex)
  {
    cerr << ex.what() << "\n";
  }
}
