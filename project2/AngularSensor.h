/*
 * AngularSensor.h
 *
 *  Created on: Nov 17, 2013
 *      Author: Nathaniel Gallinger
 */

#ifndef ANGULARSENSOR_H_
#define ANGULARSENSOR_H_

#include "Sensor.h"
using Project2::Sensor;

namespace Project2
{
  class AngularSensor : public Sensor
  {
  public:
    AngularSensor(string name, Signal &source);
  protected:
    string getUnits() const;

  };
}

#endif /* ANGULARSENSOR_H_ */
