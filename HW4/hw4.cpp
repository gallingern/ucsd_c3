/*
 * hw4.cpp
 *
 * Created on: Oct 23, 2013
 * Author: Nathaniel Gallinger
 */

#include "Complex.h"

using NathanielGallinger::Complex;

int main()
{
  // Create 2 complex objects
  Complex c1(3, 5);
  Complex c2(8, 7);

  // Test overloaded operators
  Complex result1 = c1 + c2;
  cout << result1 << "\n";
  Complex result2 = c1 - c2;
  cout << result2 << "\n";

  cout << "Input c1: \n";
  cin >> c1;
  cout << "Input c2: \n";
  cin >> c2;

  cout << c1 << " == " << c2 << ": " << (c1 == c2) << "\n";
  cout << c1 << " != " << c2 << ": " << (c1 != c2) << "\n";}
