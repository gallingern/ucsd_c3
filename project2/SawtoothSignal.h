/*
 * SawtoothSignal.h
 *
 *  Created on: Nov 17, 2013
 *      Author: Nathaniel Gallinger
 */

#ifndef SAWTOOTHSIGNAL_H_
#define SAWTOOTHSIGNAL_H_

#include "PeriodicSignal.h"
using Project2::PeriodicSignal;

namespace Project2
{
  class SawtoothSignal : public PeriodicSignal
  {
  public:
    SawtoothSignal(double voltageOffset,
                   Time timeOffset,
                   double minVoltage,
                   double maxVoltage,
                   Time period);
    double getVoltageAtTime(Time t) const;
  };
}

#endif /* SAWTOOTHSIGNAL_H_ */
