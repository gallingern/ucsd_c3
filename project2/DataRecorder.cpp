/*
 * DataRecorder.cpp
 *
 *  Created on: Nov 17, 2013
 *      Author: Nathaniel Gallinger
 */

#include "DataRecorder.h"
#include <iomanip>

// Constructor
Project2::DataRecorder::DataRecorder(ostream &out)
: out(out)
{
}

// Log function
void
Project2::DataRecorder::log(Time timestamp,
                            string sensorName,
                            double sensorVoltage,
                            string sensorUnits)
{
  out << timestamp
      << " - " << sensorName
      << " - " << std::fixed << std::showpoint << std::setprecision(2) << sensorVoltage
      << " " << sensorUnits << "\n";
}
