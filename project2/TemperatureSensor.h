/*
 * TemperatureSensor.h
 *
 *  Created on: Nov 17, 2013
 *      Author: Nathaniel Gallinger
 */

#ifndef TEMPERATURESENSOR_H_
#define TEMPERATURESENSOR_H_

#include "Sensor.h"
using Project2::Sensor;

namespace Project2
{
  class TemperatureSensor : public Sensor
  {
  public:
    TemperatureSensor(string name, Signal &source);
  protected:
    string getUnits() const;

  };
}

#endif /* TEMPERATURESENSOR_H_ */
