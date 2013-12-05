/*
 * hw5.cpp
 *
 * Created on: Nov 9, 2013
 * Author: Nathaniel Gallinger
 */

#include "Shapes.h"
using namespace NathanielGallinger;

int main()
{
  const char NUM_SHAPES = 4;
  enum shapes {
    CIRCLE = 0,
    SQUARE = 1,
    SPHERE = 2,
    CUBE = 3
  };

  Shapes *pShapes[4];
  // create a shape of each type
  pShapes[CIRCLE] = new Circle(4);
  pShapes[SQUARE] = new Square(10);
  pShapes[SPHERE] = new Sphere(15);
  pShapes[CUBE] = new Cube(60);

  // loop through, call display on each shape, then delete
  for (int idx = 0; idx < NUM_SHAPES; idx++) {
    pShapes[idx]->display();
    delete pShapes[idx];
  }
}
