/*
 * Sensor.cpp
 *
 *  Created on: Nov 17, 2013
 *      Author: Nathaniel Gallinger
 */

#include "Sensor.h"

// Constructor
Project2::Sensor::Sensor(string name, Signal &source)
: name(name), source(&source)
{
}

// Empty Destructor
Project2::Sensor::~Sensor()
{
}

// Take Reading function
void
Project2::Sensor::takeReading(Time t, DataRecorder &recorder)
{
  recorder.log(t, this->getName(), this->getSource().getVoltageAtTime(t), this->getUnits());
}

// Accessor
string
Project2::Sensor::getName() const
{
  return this->name;
}

// Accessor
Signal &
Project2::Sensor::getSource() const
{
  return *this->source;
}
