/*
 * Signal.cpp
 *
 *  Created on: Nov 17, 2013
 *      Author: Nathaniel Gallinger
 */

#include "Signal.h"

// Constructor
Project2::Signal::Signal(double voltageOffset, Time timeOffset)
: voltageOffset(voltageOffset), timeOffset(timeOffset)
{
}

// Empty Destructor
Project2::Signal::~Signal()
{
}

// Accessor
double
Project2::Signal::getVoltageOffset() const
{
  return this->voltageOffset;
}

// Accessor
Time
Project2::Signal::getTimeOffset() const
{
  return this->timeOffset;
}
