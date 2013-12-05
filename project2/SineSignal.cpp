/*
 * SineSignal.cpp
 *
 *  Created on: Nov 17, 2013
 *      Author: Nathaniel Gallinger
 */

#include "SineSignal.h"
#include <cmath>

// Constructor
Project2::SineSignal::SineSignal(double voltageOffset,
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
Project2::SineSignal::getVoltageAtTime(Time t) const
{
  const double PI = 3.14159265358979323846;
  double sinVal = sin(((double)t.getTotalTimeAsSeconds() +
                  (double)this->getTimeOffset().getTotalTimeAsSeconds()) * 2 * PI /
                  (double)this->getPeriod().getTotalTimeAsSeconds());
  double retval = this->getVoltageOffset() + this->getMinVoltage() +
                  (this->getMaxVoltage() - this->getMinVoltage()) / 2 +
                  sinVal * (this->getMaxVoltage() - this->getMinVoltage()) / 2;
  return retval;
}
