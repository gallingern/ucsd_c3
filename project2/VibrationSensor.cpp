/*
 * VibrationSensor.cpp
 *
 *  Created on: Nov 17, 2013
 *      Author: Nathaniel Gallinger
 */

#include "VibrationSensor.h"

// Constructor
Project2::VibrationSensor::VibrationSensor(string name, Signal &source)
: Sensor(name, source)
{
}

// Accessor
string
Project2::VibrationSensor::getUnits() const
{
  string retval = "Hertz (Hz)";
  return retval;
}
