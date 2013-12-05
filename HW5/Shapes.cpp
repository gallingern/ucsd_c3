/*
 * Shapes.cpp
 *
 * Created on: Nov 9, 2013
 * Author: Nathaniel Gallinger
 */

#include "Shapes.h"

const double PI = 3.14159;

// Shapes destructor
NathanielGallinger::Shapes::~Shapes()
{
}

// TwoDimensionalShape destructor
NathanielGallinger::TwoDimensionalShape::~TwoDimensionalShape()
{
}

// TwoDimensionalShape destructor
NathanielGallinger::ThreeDimensionalShape::~ThreeDimensionalShape()
{
}

// Circle constructor
NathanielGallinger::Circle::Circle(double radius)
{
  this->radius = radius;
}

// Circle display function
void
NathanielGallinger::Circle::display() const
{
  cout << "Circle with radius " << radius << " has area " <<
      getArea() << "\n";
}

// Circle get area
double
NathanielGallinger::Circle::getArea() const
{
  return PI * pow(radius, 2);
}

// Square constructor
NathanielGallinger::Square::Square(double lengthOfSide)
{
  this->lengthOfSide = lengthOfSide;
}

// Square display function
void
NathanielGallinger::Square::display() const{
  cout << "Square with length of side " << lengthOfSide <<
      " has area " << getArea() << "\n";
}

// Square get area
double
NathanielGallinger::Square::getArea() const
{
  return pow(lengthOfSide, 2);
}

// Sphere constructor
NathanielGallinger::Sphere::Sphere(double radius)
{
  this->radius = radius;
}

// Sphere display fuction
void
NathanielGallinger::Sphere::display() const
{
  cout << "Sphere with radius " << radius << " has surface area " <<
      getSurfaceArea() << " and volume " << getVolume() << "\n";
}

// Sphere get surface area
double
NathanielGallinger::Sphere::getSurfaceArea() const
{
  return 4 * PI * pow(radius, 2);
}

// Sphere get volume
double
NathanielGallinger::Sphere::getVolume() const
{
  return (4/3) * PI * pow(radius, 3);
}

// Cube constructor
NathanielGallinger::Cube::Cube(double lengthOfSide)
{
  this->lengthOfSide = lengthOfSide;
}

// Cube display function
void
NathanielGallinger::Cube::display() const
{
  cout << "Cube with length of side " << lengthOfSide << " has surface area " <<
          getSurfaceArea() << " and volume " << getVolume() << "\n";
}

// Cube get surface area
double
NathanielGallinger::Cube::getSurfaceArea() const
{
  return 6 * pow(lengthOfSide, 2);
}

// Cube get volume
double
NathanielGallinger::Cube::getVolume() const
{
  return pow(lengthOfSide, 3);
}
