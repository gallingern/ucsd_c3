/*
 * Signal.h
 *
 *  Created on: Nov 17, 2013
 *      Author: Nathaniel Gallinger
 */

#ifndef SIGNAL_H_
#define SIGNAL_H_

#include "Time.h"
using Project2::Time;

namespace Project2
{
  class Signal
  {
  public:
    Signal(double voltageOffset, Time timeOffset);
    virtual ~Signal();
    virtual double getVoltageAtTime(Time t) const = 0;
  private:
    double voltageOffset;
    Time timeOffset;
  protected:
    double getVoltageOffset() const;
    Time getTimeOffset() const;
  };
}

#endif /* SIGNAL_H_ */
