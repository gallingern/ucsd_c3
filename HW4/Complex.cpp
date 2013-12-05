/*
 * Complex.cpp
 *
 * Created on: Oct 23, 2013
 * Author: Nathaniel Gallinger
 */

#include "Complex.h"

// Constructor
NathanielGallinger::Complex::Complex(double real, double imaginary)
: real(real), imaginary(imaginary)
{
}

// + operator overload
const NathanielGallinger::Complex
NathanielGallinger::Complex::operator+(const Complex &op2)
{
  double resultReal, resultImag;
  resultReal = this->real + op2.real;
  resultImag = this->imaginary + op2.imaginary;
  return Complex(resultReal, resultImag);
}

// - operator overload
const NathanielGallinger::Complex
NathanielGallinger::Complex::operator-(const Complex &op2)
{
  double resultReal, resultImag;
  resultReal = this->real - op2.real;
  resultImag = this->imaginary - op2.imaginary;
  return Complex(resultReal, resultImag);
}

// == operator overload
const bool
NathanielGallinger::Complex::operator==(const Complex &op2)
{
  return this->real == op2.real && this->imaginary == op2.imaginary;
}

// != operator overload
const bool
NathanielGallinger::Complex::operator!=(const Complex &op2)
{
  return !(this->real == op2.real && this->imaginary == op2.imaginary);
}

// << operator overload
ostream &
NathanielGallinger::operator<<(ostream &out, const Complex &value)
{
  out << value.real;
  // if positive, print positive sign
  if (value.imaginary >= 0)
    out << "+";
  out << value.imaginary;
  out << "i";
  return out;
}

// >> operator overload
istream &
NathanielGallinger::operator>>(istream &in, Complex &value)
{
  in >> value.real;
  in >> value.imaginary;
  return in;
}
