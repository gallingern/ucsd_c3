/*
 * TemperatureSensor.cpp
 *
 *  Created on: Nov 17, 2013
 *      Author: Nathaniel Gallinger
 */

#include "TemperatureSensor.h"

// Constructor
Project2::TemperatureSensor::TemperatureSensor(string name, Signal &source)
: Sensor(name, source)
{
}

// Accessor
string
Project2::TemperatureSensor::getUnits() const
{
  string retval = "Degrees Celsius";
  return retval;
}
