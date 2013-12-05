/*
 * Sensor.h
 *
 *  Created on: Nov 17, 2013
 *      Author: Nathaniel Gallinger
 */

#ifndef SENSOR_H_
#define SENSOR_H_

#include <string>
using std::string;

#include "Signal.h"
using Project2::Signal;

#include "Time.h"
using Project2::Time;

#include "DataRecorder.h"
using Project2::DataRecorder;

namespace Project2
{
  class Sensor
  {
  public:
    Sensor(string name, Signal &source);
    virtual ~Sensor();
    void takeReading(Time t, DataRecorder &recorder);
  private:
    string name;
    Signal *source;
  protected:
    virtual string getUnits() const = 0;
    string getName() const;
    Signal & getSource() const;
  };
}

#endif /* SENSOR_H_ */
