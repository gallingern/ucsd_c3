/*
 * PeriodicSignal.cpp
 *
 *  Created on: Nov 17, 2013
 *      Author: Nathaniel Gallinger
 */

#include "PeriodicSignal.h"

// Constructor
Project2::PeriodicSignal::PeriodicSignal(double voltageOffset,
               Time timeOffset,
               double minVoltage,
               double maxVoltage,
               Time period)
: Signal(voltageOffset, timeOffset),
  minVoltage(minVoltage),
  maxVoltage(maxVoltage),
  period(period)
{
}

// Empty Destructor
Project2::PeriodicSignal::~PeriodicSignal()
{
}

// Accessor
double
Project2::PeriodicSignal::getMinVoltage() const
{
  return this->minVoltage;
}

// Accessor
double
Project2::PeriodicSignal::getMaxVoltage() const
{
  return this->maxVoltage;
}

// Accessor
Time
Project2::PeriodicSignal::getPeriod() const
{
  return this->period;
}
