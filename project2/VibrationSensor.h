/*
 * VibrationSensor.h
 *
 *  Created on: Nov 17, 2013
 *      Author: Nathaniel Gallinger
 */

#ifndef VIBRATIONSENSOR_H_
#define VIBRATIONSENSOR_H_

#include "Sensor.h"
using Project2::Sensor;

namespace Project2
{
  class VibrationSensor : public Sensor
  {
  public:
    VibrationSensor(string name, Signal &source);
  protected:
    string getUnits() const;

  };
}

#endif /* VIBRATIONSENSOR_H_ */
