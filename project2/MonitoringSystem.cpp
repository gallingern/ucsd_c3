/*
 * MonitoringSystem.cpp
 *
 *  Created on: Nov 17, 2013
 *      Author: Nathaniel Gallinger
 */

#include "MonitoringSystem.h"

// Constructor
Project2::MonitoringSystem::MonitoringSystem(ostream &out)
{
  this->recorder = new DataRecorder(out);
}

// Destructor
Project2::MonitoringSystem::~MonitoringSystem()
{
  delete this->recorder;
}

// Add Sensor Function
void
Project2::MonitoringSystem::addSensor(Sensor *s)
{
  this->sensors.push_back(s);
}

// Take Reading Function
void
Project2::MonitoringSystem::takeReading(Time t)
{
  for (unsigned int idx = 0; idx < this->sensors.size(); idx++) {
    this->sensors[idx]->takeReading(t, *this->recorder);
  }
}
