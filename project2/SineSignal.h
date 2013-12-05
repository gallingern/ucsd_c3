/*
 * SineSignal.h
 *
 *  Created on: Nov 17, 2013
 *      Author: Nathaniel Gallinger
 */

#ifndef SINESIGNAL_H_
#define SINESIGNAL_H_

#include "PeriodicSignal.h"
using Project2::PeriodicSignal;

namespace Project2
{
  class SineSignal : public PeriodicSignal
  {
  public:
    SineSignal(double voltageOffset,
               Time timeOffset,
               double minVoltage,
               double maxVoltage,
               Time period);
    double getVoltageAtTime(Time t) const;
  };
}

#endif /* SINESIGNAL_H_ */
