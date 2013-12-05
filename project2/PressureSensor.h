/*
 * PressureSensor.h
 *
 *  Created on: Nov 17, 2013
 *      Author: Nathaniel Gallinger
 */

#ifndef PRESSURESENSOR_H_
#define PRESSURESENSOR_H_

#include "Sensor.h"
using Project2::Sensor;

namespace Project2
{
  class PressureSensor : public Sensor
  {
  public:
    PressureSensor(string name, Signal &source);
  protected:
    string getUnits() const;

  };
}

#endif /* PRESSURESENSOR_H_ */
