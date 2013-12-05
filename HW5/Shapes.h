/*
 * Shapes.h
 *
 * Created on: Nov 9, 2013
 * Author: Nathaniel Gallinger
 */

#ifndef SHAPES_H_
#define SHAPES_H_

#include <cmath>
using std::pow;

#include <iostream>
using std::cout;

namespace NathanielGallinger
{
  // parent class
  class Shapes
  {
  public:
    virtual ~Shapes();
    virtual void display() const = 0;
  };

  // inherit from shapes
  class TwoDimensionalShape : public Shapes
  {
  public:
    virtual ~TwoDimensionalShape();
    virtual double getArea() const = 0;
  };

  // inherit from TwoDimensionalShape
  class Circle : public TwoDimensionalShape
  {
  public:
    Circle(double radius);
    void display() const;
    double getArea() const;
  private:
    double radius;
  };

  // inherit from TwoDimensionalShape
  class Square : public TwoDimensionalShape
  {
  public:
    Square(double lengthOfSide);
    void display() const;
    double getArea() const;
  private:
    double lengthOfSide;
  };

  // inherit from shapes
  class ThreeDimensionalShape : public Shapes
  {
  public:
    virtual ~ThreeDimensionalShape();
    virtual double getSurfaceArea() const = 0;
    virtual double getVolume() const = 0;
  };

  // inherit from ThreeDimensionalShape
  class Sphere : public ThreeDimensionalShape
  {
  public:
    Sphere(double radius);
    void display() const;
    double getSurfaceArea() const;
    double getVolume() const;
  private:
    double radius;
  };

  // inherit from ThreeDimensionalShape
  class Cube : public ThreeDimensionalShape
  {
  public:
    Cube(double lengthOfSide);
    void display() const;
    double getSurfaceArea() const;
    double getVolume() const;
  private:
    double lengthOfSide;
  };
}

#endif /* SHAPES_H_ */
