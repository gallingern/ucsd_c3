/*
 * DataRecorder.h
 *
 *  Created on: Nov 17, 2013
 *      Author: Nathaniel Gallinger
 */

#ifndef DATARECORDER_H_
#define DATARECORDER_H_

#include <iostream>
using std::ostream;

#include <string>
using std::string;

#include "Time.h"
using Project2::Time;

namespace Project2
{
  class DataRecorder
  {
  public:
    DataRecorder(ostream &out);
    void log(Time timestamp,
             string sensorName,
             double sensorVoltage,
             string sensorUnits);
  private:
    ostream &out;
  };
}

#endif /* DATARECORDER_H_ */
