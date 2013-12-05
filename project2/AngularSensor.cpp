/*
 * AngularSensor.cpp
 *
 *  Created on: Nov 17, 2013
 *      Author: Nathaniel Gallinger
 */

#include "AngularSensor.h"

// Constructor
Project2::AngularSensor::AngularSensor(string name, Signal &source)
: Sensor(name, source)
{
}

// Accessor
string
Project2::AngularSensor::getUnits() const
{
  string retval = "Radians";
  return retval;
}
