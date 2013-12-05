/*
 * PressureSensor.cpp
 *
 *  Created on: Nov 17, 2013
 *      Author: Nathaniel Gallinger
 */

#include "PressureSensor.h"

// Constructor
Project2::PressureSensor::PressureSensor(string name, Signal &source)
: Sensor(name, source)
{
}

// Accessor
string
Project2::PressureSensor::getUnits() const
{
  string retval = "Pounds per square inch (PSI)";
  return retval;
}
