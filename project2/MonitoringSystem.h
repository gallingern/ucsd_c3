/*
 * MonitoringSystem.h
 *
 *  Created on: Nov 17, 2013
 *      Author: Nathaniel Gallinger
 */

#ifndef MONITORINGSYSTEM_H_
#define MONITORINGSYSTEM_H_

#include "DataRecorder.h"
using Project2::DataRecorder;

#include "Sensor.h"
using Project2::Sensor;

#include "Time.h"
using Project2::Time;

#include <vector>
using std::vector;

namespace Project2
{
  class MonitoringSystem
  {
  public:
    MonitoringSystem(ostream &out);
    ~MonitoringSystem();
    void addSensor(Sensor *s);
    void takeReading(Time t);
  private:
    DataRecorder *recorder;
    vector <Sensor *> sensors;
  };
}

#endif /* MONITORINGSYSTEM_H_ */
