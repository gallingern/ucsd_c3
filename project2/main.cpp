/*
* Airplane Monitoring System Project
* CSE-40477
*
* main.cpp
* YOU MUST NOT CHANGE THIS FILE.
*/
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include "UnitTest.h"

int main()
{
    // Initialize
    Project2UnitTest::Initialize(cout);

    // Run tests
    Project2UnitTest::TestTime();
    Project2UnitTest::TestDataRecorder();
    Project2UnitTest::TestConstantSignal();
    Project2UnitTest::TestSawtoothSignal();
    Project2UnitTest::TestSineSignal();
    Project2UnitTest::TestAngularSensor();
    Project2UnitTest::TestPressureSensor();
    Project2UnitTest::TestTemperatureSensor();
    Project2UnitTest::TestVibrationSensor();
    Project2UnitTest::TestMonitoringSystem();

    // Display test results
    Project2UnitTest::DisplaySummary();

    // Wait for user input
    cout << endl << "Press enter to continue...";
    cin.get();
}
