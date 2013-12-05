/*
 * ConstantSignal.h
 *
 *  Created on: Nov 17, 2013
 *      Author: Nathaniel Gallinger
 */

#ifndef CONSTANTSIGNAL_H_
#define CONSTANTSIGNAL_H_

#include "Signal.h"
using Project2::Signal;

namespace Project2
{
  class ConstantSignal : public Signal
  {
  public:
    ConstantSignal(double voltageOffset, Time timeOffset);
    double getVoltageAtTime(Time t) const;
  };
}

#endif /* CONSTANTSIGNAL_H_ */
