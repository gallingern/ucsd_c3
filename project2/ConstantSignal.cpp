/*
 * ConstantSignal.cpp
 *
 *  Created on: Nov 17, 2013
 *      Author: Nathaniel Gallinger
 */

#include "ConstantSignal.h"

// Constructor
Project2::ConstantSignal::ConstantSignal(double voltageOffset, Time timeOffset)
: Signal(voltageOffset, timeOffset)
{
}

// Accessor
double
Project2::ConstantSignal::getVoltageAtTime(Time t) const
{
  return this->Project2::Signal::getVoltageOffset();
}
