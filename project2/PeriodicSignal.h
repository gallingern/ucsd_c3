/*
 * PeriodicSignal.h
 *
 *  Created on: Nov 17, 2013
 *      Author: Nathaniel Gallinger
 */

#ifndef PERIODICSIGNAL_H_
#define PERIODICSIGNAL_H_

#include "Signal.h"
using Project2::Signal;

namespace Project2
{
  class PeriodicSignal : public Signal
  {
  public:
    PeriodicSignal(double voltageOffset,
                   Time timeOffset,
                   double minVoltage,
                   double maxVoltage,
                   Time period);
    virtual ~PeriodicSignal();
    virtual double getVoltageAtTime(Time t) const = 0;
  private:
    double minVoltage;
    double maxVoltage;
    Time period;
  protected:
    double getMinVoltage() const;
    double getMaxVoltage() const;
    Time getPeriod() const;
  };
}

#endif /* PERIODICSIGNAL_H_ */
