/*
 * SawtoothSignal.cpp
 *
 *  Created on: Nov 17, 2013
 *      Author: Nathaniel Gallinger
 */

#include "SawtoothSignal.h"
#include <cmath>

// Constructor
Project2::SawtoothSignal::SawtoothSignal(double voltageOffset,
                                         Time timeOffset,
                                         double minVoltage,
                                         double maxVoltage,
                                         Time period)
: PeriodicSignal(voltageOffset,
  timeOffset,
  minVoltage,
  maxVoltage,
  period)
{
}

// Accessor
double
Project2::SawtoothSignal::getVoltageAtTime(Time t) const
{
  double retval = this->getVoltageOffset() + this->getMinVoltage() +
                  fmod((((double)t.getTotalTimeAsSeconds() +
                  (double)this->getTimeOffset().getTotalTimeAsSeconds()) *
                  (this->getMaxVoltage() - this->getMinVoltage()) /
                  (double)this->getPeriod().getTotalTimeAsSeconds()),
                  (this->getMaxVoltage() - this->getMinVoltage()));
  return retval;
}
