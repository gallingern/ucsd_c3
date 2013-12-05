/*
 * Complex.h
 *
 * Created on: Oct 23, 2013
 * Author: Nathaniel Gallinger
 */

#ifndef COMPLEX_H_
#define COMPLEX_H_

#include <iostream>
using std::ostream;
using std::istream;
using std::cerr;
using std::cout;
using std::cin;

namespace NathanielGallinger
{
  class Complex
  {
    // friend function stream operator overloads
    friend ostream &operator<<(ostream &out, const Complex &value);
    friend istream &operator>>(istream &in, Complex &value);
  public:
    // Constructor
    Complex(double = 0, double = 0);
    // member function operator overloads
    const Complex operator+(const Complex &op2);
    const Complex operator-(const Complex &op2);
    const bool operator==(const Complex &op2);
    const bool operator!=(const Complex &op2);
  private:
    // Private data members
    double real;
    double imaginary;
  };
  // friend function stream operator overloads
  ostream &operator<<(ostream &out, const Complex &value);
  istream &operator>>(istream &in, Complex &value);
}
#endif /* COMPLEX_H_ */
