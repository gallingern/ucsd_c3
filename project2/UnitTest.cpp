// Include standard library headers
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <ostream>
using std::ostream;

#include <sstream>
using std::stringstream;

#include <string>
using std::string;

// Include test headers
#include "TestFramework.h"
#include "UnitTest.h"

// Include Project2 headers
#include "AngularSensor.h"
using Project2::AngularSensor;

#include "ConstantSignal.h"
using Project2::ConstantSignal;

#include "DataRecorder.h"
using Project2::DataRecorder;

#include "MonitoringSystem.h"
using Project2::MonitoringSystem;

#include "PeriodicSignal.h"
using Project2::PeriodicSignal;

#include "PressureSensor.h"
using Project2::PressureSensor;

#include "SawtoothSignal.h"
using Project2::SawtoothSignal;

#include "Sensor.h"
using Project2::Sensor;

#include "Signal.h"
using Project2::Signal;

#include "SineSignal.h"
using Project2::SineSignal;

#include "TemperatureSensor.h"
using Project2::TemperatureSensor;

#include "Time.h"
using Project2::Time;

#include "VibrationSensor.h"
using Project2::VibrationSensor;

void Project2UnitTest::Initialize(ostream &out)
{
	TestFramework::Initialize(&out);
}

void Project2UnitTest::DisplaySummary()
{
	TestFramework::DisplaySummary();
}

void TestTime_ToString()
{
	TestFramework::BeginTest("TestTime_ToString");

	Time time(1, 2, 3);
   stringstream ss;
   ss << time;
	TEST_ASSERT("1h:2m:3s" == ss.str());

	TestFramework::EndTest();
}

void TestTime_OperatorPlusEqual()
{
	TestFramework::BeginTest("TestTime_OperatorPlusEqual");

	Time time1(80, 2, 3);
	Time time2(217, 59, 59);
	time1 += time2;
   stringstream ss;
   ss << time1;
	TEST_ASSERT("298h:2m:2s" == ss.str());

	TestFramework::EndTest();
}

void Project2UnitTest::TestTime()
{
	TestTime_ToString();
	TestTime_OperatorPlusEqual();
}

void TestDataRecorder_log0DigitsAfterSensorValueDecimal()
{
	TestFramework::BeginTest("TestDataRecorder_log0DigitsAfterSensorValueDecimal");

	stringstream ss;
	DataRecorder dr(ss);
	dr.log(Time(5, 6, 7), "test sensor", 12., "test units");
	TEST_ASSERT("5h:6m:7s - test sensor - 12.00 test units\n" == ss.str());

	TestFramework::EndTest();
}

void TestDataRecorder_log1DigitsAfterSensorValueDecimal()
{
	TestFramework::BeginTest("TestDataRecorder_log1DigitsAfterSensorValueDecimal");

	stringstream ss;
	DataRecorder dr(ss);
	dr.log(Time(5, 6, 7), "test sensor", 12.1, "test units");
	TEST_ASSERT("5h:6m:7s - test sensor - 12.10 test units\n" == ss.str());

	TestFramework::EndTest();
}

void TestDataRecorder_log2DigitsAfterSensorValueDecimal()
{
	TestFramework::BeginTest("TestDataRecorder_log2DigitsAfterSensorValueDecimal");

	stringstream ss;
	DataRecorder dr(ss);
	dr.log(Time(5, 6, 7), "test sensor", 12.23, "test units");
	TEST_ASSERT("5h:6m:7s - test sensor - 12.23 test units\n" == ss.str());

	TestFramework::EndTest();
}

void TestDataRecorder_log3DigitsAfterSensorValueDecimal()
{
	TestFramework::BeginTest("TestDataRecorder_log3DigitsAfterSensorValueDecimal");

	// 3rd digit <= 5 --> round down
	stringstream ss1;
	DataRecorder dr1(ss1);
	dr1.log(Time(5, 6, 7), "test sensor", 12.235, "test units");
	TEST_ASSERT("5h:6m:7s - test sensor - 12.23 test units\n" == ss1.str());

	// 3rd digit > 5 --> round up
	stringstream ss2;
	DataRecorder dr2(ss2);
	dr2.log(Time(5, 6, 7), "test sensor", 12.236, "test units");
	TEST_ASSERT("5h:6m:7s - test sensor - 12.24 test units\n" == ss2.str());

	TestFramework::EndTest();
}

void Project2UnitTest::TestDataRecorder()
{
	TestDataRecorder_log0DigitsAfterSensorValueDecimal();
	TestDataRecorder_log1DigitsAfterSensorValueDecimal();
	TestDataRecorder_log2DigitsAfterSensorValueDecimal();
	TestDataRecorder_log3DigitsAfterSensorValueDecimal();
}

void TestConstantSignal_Zeroed()
{
	TestFramework::BeginTest("TestConstantSignal_Zeroed");

	ConstantSignal cs(0, Time(0, 0, 0));
	TEST_ASSERT(0 == cs.getVoltageAtTime(Time(0, 0, 0)));
	TEST_ASSERT(0 == cs.getVoltageAtTime(Time(1, 1, 1)));
	TEST_ASSERT(0 == cs.getVoltageAtTime(Time(327, 59, 59)));

	TestFramework::EndTest();
}

void TestConstantSignal_VariedVoltageOffset()
{
	TestFramework::BeginTest("TestConstantSignal_VariedVoltageOffset");

	// Positive voltage offset
	ConstantSignal cs1(12.5, Time(0, 0, 0));
	TEST_ASSERT(12.5 == cs1.getVoltageAtTime(Time(0, 0, 0)));
	TEST_ASSERT(12.5 == cs1.getVoltageAtTime(Time(1, 1, 1)));
	TEST_ASSERT(12.5 == cs1.getVoltageAtTime(Time(327, 59, 59)));

	// Negative voltage offset
	ConstantSignal cs2(-12.5, Time(0, 0, 0));
	TEST_ASSERT(-12.5 == cs2.getVoltageAtTime(Time(0, 0, 0)));
	TEST_ASSERT(-12.5 == cs2.getVoltageAtTime(Time(1, 1, 1)));
	TEST_ASSERT(-12.5 == cs2.getVoltageAtTime(Time(327, 59, 59)));

	TestFramework::EndTest();
}

void TestConstantSignal_VariedTimeOffset()
{
	TestFramework::BeginTest("TestConstantSignal_VariedTimeOffset");

	// Positive time offset
	ConstantSignal cs1(0, Time(1, 2, 3));
	TEST_ASSERT(0 == cs1.getVoltageAtTime(Time(0, 0, 0)));
	TEST_ASSERT(0 == cs1.getVoltageAtTime(Time(1, 1, 1)));
	TEST_ASSERT(0 == cs1.getVoltageAtTime(Time(327, 59, 59)));

	TestFramework::EndTest();
}

void TestConstantSignal_VariedAll()
{
	TestFramework::BeginTest("TestConstantSignal_VariedAll");

	// Positive voltage offset, positive time offset
	ConstantSignal cs1(73.8, Time(1, 2, 3));
	TEST_ASSERT(73.8 == cs1.getVoltageAtTime(Time(0, 0, 0)));
	TEST_ASSERT(73.8 == cs1.getVoltageAtTime(Time(1, 1, 1)));
	TEST_ASSERT(73.8 == cs1.getVoltageAtTime(Time(327, 59, 59)));

	// Negative voltage offset, positive time offset
	ConstantSignal cs2(-73.8, Time(1, 2, 3));
	TEST_ASSERT(-73.8 == cs2.getVoltageAtTime(Time(0, 0, 0)));
	TEST_ASSERT(-73.8 == cs2.getVoltageAtTime(Time(1, 1, 1)));
	TEST_ASSERT(-73.8 == cs2.getVoltageAtTime(Time(327, 59, 59)));

	TestFramework::EndTest();
}

void Project2UnitTest::TestConstantSignal()
{
	TestConstantSignal_Zeroed();
	TestConstantSignal_VariedVoltageOffset();
	TestConstantSignal_VariedTimeOffset();
	TestConstantSignal_VariedAll();
}

void TestSawtoothSignal_Zeroed()
{
	TestFramework::BeginTest("TestSawtoothSignal_Zeroed");

	// Zero voltage offset, zero time offset, voltage range from 0 to 10, period 1 minute
	SawtoothSignal ss1(0, Time(0, 0, 0), 0, 10, Time(0, 1, 0));
	TEST_ASSERT(0 == ss1.getVoltageAtTime(Time(0, 0, 0)));
	TEST_ASSERT(2.5 == ss1.getVoltageAtTime(Time(0, 0, 15)));
	TEST_ASSERT(5 == ss1.getVoltageAtTime(Time(0, 0, 30)));
	TEST_ASSERT(7.5 == ss1.getVoltageAtTime(Time(0, 0, 45)));
	TEST_ASSERT(0 == ss1.getVoltageAtTime(Time(0, 0, 60)));

	// Zero voltage offset, zero time offset, voltage range from 0 to 2000, period 1 hour
	SawtoothSignal ss2(0, Time(0, 0, 0), 0, 2000, Time(1, 0, 0));
	TEST_ASSERT(0 == ss2.getVoltageAtTime(Time(0, 0, 0)));
	TEST_ASSERT(500 == ss2.getVoltageAtTime(Time(0, 15, 0)));
	TEST_ASSERT(1000 == ss2.getVoltageAtTime(Time(0, 30, 0)));
	TEST_ASSERT(1500 == ss2.getVoltageAtTime(Time(0, 45, 0)));
	TEST_ASSERT(0 == ss2.getVoltageAtTime(Time(1, 0, 0)));

	// Zero voltage offset, zero time offset, voltage range from -10 to 10, period 4 hours
	SawtoothSignal ss3(0, Time(0, 0, 0), -10, 10, Time(4, 0, 0));
	TEST_ASSERT(-10 == ss3.getVoltageAtTime(Time(0, 0, 0)));
	TEST_ASSERT(-5 == ss3.getVoltageAtTime(Time(1, 0, 0)));
	TEST_ASSERT(0 == ss3.getVoltageAtTime(Time(2, 0, 0)));
	TEST_ASSERT(5 == ss3.getVoltageAtTime(Time(3, 0, 0)));
	TEST_ASSERT(-10 == ss3.getVoltageAtTime(Time(4, 0, 0)));

	TestFramework::EndTest();
}

void TestSawtoothSignal_VariedVoltageOffset()
{
	TestFramework::BeginTest("TestSawtoothSignal_VariedVoltageOffset");

	// Positive voltage offset, zero time offset, voltage range from 0 to 10, period 1 minute
	SawtoothSignal ss1(13, Time(0, 0, 0), 0, 10, Time(0, 1, 0));
	TEST_ASSERT(13 == ss1.getVoltageAtTime(Time(0, 0, 0)));
	TEST_ASSERT(15.5 == ss1.getVoltageAtTime(Time(0, 0, 15)));
	TEST_ASSERT(18 == ss1.getVoltageAtTime(Time(0, 0, 30)));
	TEST_ASSERT(20.5 == ss1.getVoltageAtTime(Time(0, 0, 45)));
	TEST_ASSERT(13 == ss1.getVoltageAtTime(Time(0, 0, 60)));

	// Negative voltage offset, zero time offset, voltage range from 0 to 10, period 1 minute
	SawtoothSignal ss2(-13, Time(0, 0, 0), 0, 10, Time(0, 1, 0));
	TEST_ASSERT(-13 == ss2.getVoltageAtTime(Time(0, 0, 0)));
	TEST_ASSERT(-10.5 == ss2.getVoltageAtTime(Time(0, 0, 15)));
	TEST_ASSERT(-8.0 == ss2.getVoltageAtTime(Time(0, 0, 30)));
	TEST_ASSERT(-5.5 == ss2.getVoltageAtTime(Time(0, 0, 45)));
	TEST_ASSERT(-13 == ss2.getVoltageAtTime(Time(0, 0, 60)));

	TestFramework::EndTest();
}

void TestSawtoothSignal_VariedTimeOffset()
{
	TestFramework::BeginTest("TestSawtoothSignal_VariedTimeOffset");

	// Zero voltage offset, 15 second time offset, voltage range from 0 to 10, period 1 minute
	SawtoothSignal ss1(0, Time(0, 0, 15), 0, 10, Time(0, 1, 0));
	TEST_ASSERT(2.5 == ss1.getVoltageAtTime(Time(0, 0, 0)));
	TEST_ASSERT(5 == ss1.getVoltageAtTime(Time(0, 0, 15)));
	TEST_ASSERT(7.5 == ss1.getVoltageAtTime(Time(0, 0, 30)));
	TEST_ASSERT(0 == ss1.getVoltageAtTime(Time(0, 0, 45)));
	TEST_ASSERT(2.5 == ss1.getVoltageAtTime(Time(0, 0, 60)));

	TestFramework::EndTest();
}

void TestSawtoothSignal_VariedAll()
{
	TestFramework::BeginTest("TestSawtoothSignal_VariedAll");

	// Positive voltage offset, 15 second time offset, voltage range from 0 to 10, period 1 minute
	SawtoothSignal ss1(3, Time(0, 0, 15), 0, 10, Time(0, 1, 0));
	TEST_ASSERT(5.5 == ss1.getVoltageAtTime(Time(0, 0, 0)));
	TEST_ASSERT(8 == ss1.getVoltageAtTime(Time(0, 0, 15)));
	TEST_ASSERT(10.5 == ss1.getVoltageAtTime(Time(0, 0, 30)));
	TEST_ASSERT(3 == ss1.getVoltageAtTime(Time(0, 0, 45)));
	TEST_ASSERT(5.5 == ss1.getVoltageAtTime(Time(0, 0, 60)));

	// Negative voltage offset, 15 second time offset, voltage range from 0 to 10, period 1 minute
	SawtoothSignal ss2(-3, Time(0, 0, 15), 0, 10, Time(0, 1, 0));
	TEST_ASSERT(-0.5 == ss2.getVoltageAtTime(Time(0, 0, 0)));
	TEST_ASSERT(2 == ss2.getVoltageAtTime(Time(0, 0, 15)));
	TEST_ASSERT(4.5 == ss2.getVoltageAtTime(Time(0, 0, 30)));
	TEST_ASSERT(-3 == ss2.getVoltageAtTime(Time(0, 0, 45)));
	TEST_ASSERT(-0.5 == ss2.getVoltageAtTime(Time(0, 0, 60)));

	TestFramework::EndTest();
}

void Project2UnitTest::TestSawtoothSignal()
{
	TestSawtoothSignal_Zeroed();
	TestSawtoothSignal_VariedVoltageOffset();
	TestSawtoothSignal_VariedTimeOffset();
	TestSawtoothSignal_VariedAll();
}

bool IsWithinRange(double expectedValue, double delta, double actualValue)
{
	return (actualValue > expectedValue - delta) && (actualValue < expectedValue + delta);
}

void TestSineSignal_Zeroed()
{
	TestFramework::BeginTest("TestSineSignal_Zeroed");

	// Zero voltage offset, zero time offset, voltage range from 0 to 10, period 1 minute
	SineSignal ss1(0, Time(0, 0, 0), 0, 10, Time(0, 1, 0));
	TEST_ASSERT(IsWithinRange(5, .1, ss1.getVoltageAtTime(Time(0, 0, 0))));
	TEST_ASSERT(IsWithinRange(10, .1, ss1.getVoltageAtTime(Time(0, 0, 15))));
	TEST_ASSERT(IsWithinRange(5, .1, ss1.getVoltageAtTime(Time(0, 0, 30))));
	TEST_ASSERT(IsWithinRange(0, .1, ss1.getVoltageAtTime(Time(0, 0, 45))));
	TEST_ASSERT(IsWithinRange(5, .1, ss1.getVoltageAtTime(Time(0, 0, 60))));

	// Zero voltage offset, zero time offset, voltage range from 0 to 2000, period 1 hour
	SineSignal ss2(0, Time(0, 0, 0), 0, 2000, Time(1, 0, 0));
	TEST_ASSERT(IsWithinRange(1000, .1, ss2.getVoltageAtTime(Time(0, 0, 0))));
	TEST_ASSERT(IsWithinRange(2000, .1, ss2.getVoltageAtTime(Time(0, 15, 0))));
	TEST_ASSERT(IsWithinRange(1000, .1, ss2.getVoltageAtTime(Time(0, 30, 0))));
	TEST_ASSERT(IsWithinRange(0, .1, ss2.getVoltageAtTime(Time(0, 45, 0))));
	TEST_ASSERT(IsWithinRange(1000, .1, ss2.getVoltageAtTime(Time(1, 0, 0))));

	// Zero voltage offset, zero time offset, voltage range from -10 to 10, period 4 hours
	SineSignal ss3(0, Time(0, 0, 0), -10, 10, Time(4, 0, 0));
	TEST_ASSERT(IsWithinRange(0, .1, ss3.getVoltageAtTime(Time(0, 0, 0))));
	TEST_ASSERT(IsWithinRange(10, .1, ss3.getVoltageAtTime(Time(1, 0, 0))));
	TEST_ASSERT(IsWithinRange(0, .1, ss3.getVoltageAtTime(Time(2, 0, 0))));
	TEST_ASSERT(IsWithinRange(-10, .1, ss3.getVoltageAtTime(Time(3, 0, 0))));
	TEST_ASSERT(IsWithinRange(0, .1, ss3.getVoltageAtTime(Time(4, 0, 0))));

	TestFramework::EndTest();
}

void TestSineSignal_VariedVoltageOffset()
{
	TestFramework::BeginTest("TestSineSignal_VariedVoltageOffset");

	// Positive voltage offset, zero time offset, voltage range from 0 to 10, period 1 minute
	SineSignal ss1(13, Time(0, 0, 0), 0, 10, Time(0, 1, 0));
	TEST_ASSERT(IsWithinRange(18, .1, ss1.getVoltageAtTime(Time(0, 0, 0))));
	TEST_ASSERT(IsWithinRange(23, .1, ss1.getVoltageAtTime(Time(0, 0, 15))));
	TEST_ASSERT(IsWithinRange(18, .1, ss1.getVoltageAtTime(Time(0, 0, 30))));
	TEST_ASSERT(IsWithinRange(13, .1, ss1.getVoltageAtTime(Time(0, 0, 45))));
	TEST_ASSERT(IsWithinRange(18, .1, ss1.getVoltageAtTime(Time(0, 0, 60))));

	// Negative voltage offset, zero time offset, voltage range from 0 to 10, period 1 minute
	SineSignal ss2(-13, Time(0, 0, 0), 0, 10, Time(0, 1, 0));
	TEST_ASSERT(IsWithinRange(-8, .1, ss2.getVoltageAtTime(Time(0, 0, 0))));
	TEST_ASSERT(IsWithinRange(-3, .1, ss2.getVoltageAtTime(Time(0, 0, 15))));
	TEST_ASSERT(IsWithinRange(-8, .1, ss2.getVoltageAtTime(Time(0, 0, 30))));
	TEST_ASSERT(IsWithinRange(-13, .1, ss2.getVoltageAtTime(Time(0, 0, 45))));
	TEST_ASSERT(IsWithinRange(-8, .1, ss2.getVoltageAtTime(Time(0, 0, 60))));

	TestFramework::EndTest();
}

void TestSineSignal_VariedTimeOffset()
{
	TestFramework::BeginTest("TestSineSignal_VariedTimeOffset");

	// Zero voltage offset, 15 second time offset, voltage range from 0 to 10, period 1 minute
	SineSignal ss1(0, Time(0, 0, 15), 0, 10, Time(0, 1, 0));
	TEST_ASSERT(IsWithinRange(10, .1, ss1.getVoltageAtTime(Time(0, 0, 0))));
	TEST_ASSERT(IsWithinRange(5, .1, ss1.getVoltageAtTime(Time(0, 0, 15))));
	TEST_ASSERT(IsWithinRange(0, .1, ss1.getVoltageAtTime(Time(0, 0, 30))));
	TEST_ASSERT(IsWithinRange(5, .1, ss1.getVoltageAtTime(Time(0, 0, 45))));
	TEST_ASSERT(IsWithinRange(10, .1, ss1.getVoltageAtTime(Time(0, 0, 60))));

	TestFramework::EndTest();
}

void TestSineSignal_VariedAll()
{
	TestFramework::BeginTest("TestSineSignal_VariedAll");

	// Positive voltage offset, 15 second time offset, voltage range from 0 to 10, period 1 minute
	SineSignal ss1(13, Time(0, 0, 15), 0, 10, Time(0, 1, 0));
	TEST_ASSERT(IsWithinRange(23, .1, ss1.getVoltageAtTime(Time(0, 0, 0))));
	TEST_ASSERT(IsWithinRange(18, .1, ss1.getVoltageAtTime(Time(0, 0, 15))));
	TEST_ASSERT(IsWithinRange(13, .1, ss1.getVoltageAtTime(Time(0, 0, 30))));
	TEST_ASSERT(IsWithinRange(18, .1, ss1.getVoltageAtTime(Time(0, 0, 45))));
	TEST_ASSERT(IsWithinRange(23, .1, ss1.getVoltageAtTime(Time(0, 0, 60))));

	// Negative voltage offset, 15 second time offset, voltage range from 0 to 10, period 1 minute
	SineSignal ss2(-13, Time(0, 0, 15), 0, 10, Time(0, 1, 0));
	TEST_ASSERT(IsWithinRange(-3, .1, ss2.getVoltageAtTime(Time(0, 0, 0))));
	TEST_ASSERT(IsWithinRange(-8, .1, ss2.getVoltageAtTime(Time(0, 0, 15))));
	TEST_ASSERT(IsWithinRange(-13, .1, ss2.getVoltageAtTime(Time(0, 0, 30))));
	TEST_ASSERT(IsWithinRange(-8, .1, ss2.getVoltageAtTime(Time(0, 0, 45))));
	TEST_ASSERT(IsWithinRange(-3, .1, ss2.getVoltageAtTime(Time(0, 0, 60))));

	TestFramework::EndTest();
}

void Project2UnitTest::TestSineSignal()
{
	TestSineSignal_Zeroed();
	TestSineSignal_VariedVoltageOffset();
	TestSineSignal_VariedTimeOffset();
	TestSineSignal_VariedAll();
}

void TestAngularSensor_takeReadingFromConstantSignal()
{
	TestFramework::BeginTest("TestAngularSensor_takeReadingFromConstantSignal");

	ConstantSignal sig(0, Time(0, 1, 0));
	AngularSensor sensor("angular sensor", sig);
	stringstream ss;
	DataRecorder dr(ss);
	sensor.takeReading(Time(0, 0, 30), dr);
	TEST_ASSERT("0h:0m:30s - angular sensor - 0.00 Radians\n" == ss.str());

	TestFramework::EndTest();
}

void TestAngularSensor_takeReadingFromSawtoothSignal()
{
	TestFramework::BeginTest("TestAngularSensor_takeReadingFromSawtoothSignal");

	SawtoothSignal sig(0, Time(0, 0, 0), 0, 10, Time(0, 1, 0));
	AngularSensor sensor("angular sensor", sig);
	stringstream ss;
	DataRecorder dr(ss);
	sensor.takeReading(Time(0, 0, 30), dr);
	TEST_ASSERT("0h:0m:30s - angular sensor - 5.00 Radians\n" == ss.str());

	TestFramework::EndTest();
}

void TestAngularSensor_takeReadingFromSineSignal()
{
	TestFramework::BeginTest("TestAngularSensor_takeReadingFromSineSignal");

	SineSignal sig(0, Time(0, 0, 0), 0, 10, Time(0, 1, 0));
	AngularSensor sensor("angular sensor", sig);
	stringstream ss;
	DataRecorder dr(ss);
	sensor.takeReading(Time(0, 0, 30), dr);
	TEST_ASSERT("0h:0m:30s - angular sensor - 5.00 Radians\n" == ss.str());

	TestFramework::EndTest();
}

void Project2UnitTest::TestAngularSensor()
{
	TestAngularSensor_takeReadingFromConstantSignal();
	TestAngularSensor_takeReadingFromSawtoothSignal();
	TestAngularSensor_takeReadingFromSineSignal();
}

void TestPressureSensor_takeReadingFromConstantSignal()
{
	TestFramework::BeginTest("TestPressureSensor_takeReadingFromConstantSignal");

	ConstantSignal sig(0, Time(0, 1, 0));
	PressureSensor sensor("pressure sensor", sig);
	stringstream ss;
	DataRecorder dr(ss);
	sensor.takeReading(Time(0, 0, 30), dr);
	TEST_ASSERT("0h:0m:30s - pressure sensor - 0.00 Pounds per square inch (PSI)\n" == ss.str());

	TestFramework::EndTest();
}

void TestPressureSensor_takeReadingFromSawtoothSignal()
{
	TestFramework::BeginTest("TestPressureSensor_takeReadingFromSawtoothSignal");

	SawtoothSignal sig(0, Time(0, 0, 0), 0, 10, Time(0, 1, 0));
	PressureSensor sensor("pressure sensor", sig);
	stringstream ss;
	DataRecorder dr(ss);
	sensor.takeReading(Time(0, 0, 30), dr);
	TEST_ASSERT("0h:0m:30s - pressure sensor - 5.00 Pounds per square inch (PSI)\n" == ss.str());

	TestFramework::EndTest();
}

void TestPressureSensor_takeReadingFromSineSignal()
{
	TestFramework::BeginTest("TestPressureSensor_takeReadingFromSineSignal");

	SineSignal sig(0, Time(0, 0, 0), 0, 10, Time(0, 1, 0));
	PressureSensor sensor("pressure sensor", sig);
	stringstream ss;
	DataRecorder dr(ss);
	sensor.takeReading(Time(0, 0, 30), dr);
	TEST_ASSERT("0h:0m:30s - pressure sensor - 5.00 Pounds per square inch (PSI)\n" == ss.str());

	TestFramework::EndTest();
}

void Project2UnitTest::TestPressureSensor()
{
	TestPressureSensor_takeReadingFromConstantSignal();
	TestPressureSensor_takeReadingFromSawtoothSignal();
	TestPressureSensor_takeReadingFromSineSignal();
}

void TestTemperatureSensor_takeReadingFromConstantSignal()
{
	TestFramework::BeginTest("TestTemperatureSensor_takeReadingFromConstantSignal");

	ConstantSignal sig(0, Time(0, 1, 0));
	TemperatureSensor sensor("temperature sensor", sig);
	stringstream ss;
	DataRecorder dr(ss);
	sensor.takeReading(Time(0, 0, 30), dr);
	TEST_ASSERT("0h:0m:30s - temperature sensor - 0.00 Degrees Celsius\n" == ss.str());

	TestFramework::EndTest();
}

void TestTemperatureSensor_takeReadingFromSawtoothSignal()
{
	TestFramework::BeginTest("TestTemperatureSensor_takeReadingFromSawtoothSignal");

	SawtoothSignal sig(0, Time(0, 0, 0), 0, 10, Time(0, 1, 0));
	TemperatureSensor sensor("temperature sensor", sig);
	stringstream ss;
	DataRecorder dr(ss);
	sensor.takeReading(Time(0, 0, 30), dr);
	TEST_ASSERT("0h:0m:30s - temperature sensor - 5.00 Degrees Celsius\n" == ss.str());

	TestFramework::EndTest();
}

void TestTemperatureSensor_takeReadingFromSineSignal()
{
	TestFramework::BeginTest("TestTemperatureSensor_takeReadingFromSineSignal");

	SineSignal sig(0, Time(0, 0, 0), 0, 10, Time(0, 1, 0));
	TemperatureSensor sensor("temperature sensor", sig);
	stringstream ss;
	DataRecorder dr(ss);
	sensor.takeReading(Time(0, 0, 30), dr);
	TEST_ASSERT("0h:0m:30s - temperature sensor - 5.00 Degrees Celsius\n" == ss.str());

	TestFramework::EndTest();
}

void Project2UnitTest::TestTemperatureSensor()
{
	TestTemperatureSensor_takeReadingFromConstantSignal();
	TestTemperatureSensor_takeReadingFromSawtoothSignal();
	TestTemperatureSensor_takeReadingFromSineSignal();
}

void TestVibrationSensor_takeReadingFromConstantSignal()
{
	TestFramework::BeginTest("TestVibrationSensor_takeReadingFromConstantSignal");

	ConstantSignal sig(0, Time(0, 1, 0));
	VibrationSensor sensor("vibration sensor", sig);
	stringstream ss;
	DataRecorder dr(ss);
	sensor.takeReading(Time(0, 0, 30), dr);
	TEST_ASSERT("0h:0m:30s - vibration sensor - 0.00 Hertz (Hz)\n" == ss.str());

	TestFramework::EndTest();
}

void TestVibrationSensor_takeReadingFromSawtoothSignal()
{
	TestFramework::BeginTest("TestVibrationSensor_takeReadingFromSawtoothSignal");

	SawtoothSignal sig(0, Time(0, 0, 0), 0, 10, Time(0, 1, 0));
	VibrationSensor sensor("vibration sensor", sig);
	stringstream ss;
	DataRecorder dr(ss);
	sensor.takeReading(Time(0, 0, 30), dr);
	TEST_ASSERT("0h:0m:30s - vibration sensor - 5.00 Hertz (Hz)\n" == ss.str());

	TestFramework::EndTest();
}

void TestVibrationSensor_takeReadingFromSineSignal()
{
	TestFramework::BeginTest("TestVibrationSensor_takeReadingFromSineSignal");

	SineSignal sig(0, Time(0, 0, 0), 0, 10, Time(0, 1, 0));
	VibrationSensor sensor("vibration sensor", sig);
	stringstream ss;
	DataRecorder dr(ss);
	sensor.takeReading(Time(0, 0, 30), dr);
	TEST_ASSERT("0h:0m:30s - vibration sensor - 5.00 Hertz (Hz)\n" == ss.str());

	TestFramework::EndTest();
}

void Project2UnitTest::TestVibrationSensor()
{
	TestVibrationSensor_takeReadingFromConstantSignal();
	TestVibrationSensor_takeReadingFromSawtoothSignal();
	TestVibrationSensor_takeReadingFromSineSignal();
}

void TestMonitoringSystem_takeReadingNoSensors()
{
	TestFramework::BeginTest("TestMonitoringSystem_takeReadingNoSensors");

	stringstream ss;
	MonitoringSystem ms(ss);
	ms.takeReading(Time(0, 0, 0));
	TEST_ASSERT("" == ss.str());

	TestFramework::EndTest();
}

void TestMonitoringSystem_takeReading1Sensors()
{
	TestFramework::BeginTest("TestMonitoringSystem_takeReading1Sensors");

	stringstream ss;
	MonitoringSystem ms(ss);
	ConstantSignal sig(0, Time(0, 0, 0));
	AngularSensor sensor("Horizontal rotation", sig);
	ms.addSensor(&sensor);
	ms.takeReading(Time(0, 0, 0));
	TEST_ASSERT("0h:0m:0s - Horizontal rotation - 0.00 Radians\n" == ss.str());

	TestFramework::EndTest();
}

void TestMonitoringSystem_takeReading2Sensors()
{
	TestFramework::BeginTest("TestMonitoringSystem_takeReading2Sensors");

	stringstream ss;
	MonitoringSystem ms(ss);

	// Sensor 1
	SawtoothSignal sig1(0, Time(0, 0, 0), 0, 10, Time(0, 1, 0));
	AngularSensor sensor1("Horizontal rotation", sig1);
	ms.addSensor(&sensor1);

	// Sensor 2
	SineSignal sig2(0, Time(0, 0, 0), 0, 10, Time(0, 1, 0));
	PressureSensor sensor2("Cabin pressure", sig2);
	ms.addSensor(&sensor2);

	ms.takeReading(Time(0, 0, 0));
	string expected = string("0h:0m:0s - Horizontal rotation - 0.00 Radians\n")
		+ "0h:0m:0s - Cabin pressure - 5.00 Pounds per square inch (PSI)\n";
	TEST_ASSERT(expected == ss.str());

	TestFramework::EndTest();
}

void TestMonitoringSystem_Take2Readings3Sensors()
{
	TestFramework::BeginTest("TestMonitoringSystem_Take2Readings3Sensors");

	stringstream ss;
	MonitoringSystem ms(ss);

	// Sensor 1
	SawtoothSignal sig1(0, Time(0, 0, 0), 0, 10, Time(0, 1, 0));
	AngularSensor sensor1("Horizontal rotation", sig1);
	ms.addSensor(&sensor1);

	// Sensor 2
	SineSignal sig2(0, Time(0, 0, 0), 0, 10, Time(0, 1, 0));
	PressureSensor sensor2("Cabin pressure", sig2);
	ms.addSensor(&sensor2);

	// Sensor 3
	ConstantSignal sig3(305.18, Time(0, 0, 0));
	TemperatureSensor sensor3("Core temperature", sig3);
	ms.addSensor(&sensor3);

	// Reading 1
	Time t = Time(0, 0, 0);
	ms.takeReading(t);
	string expected = string("0h:0m:0s - Horizontal rotation - 0.00 Radians\n")
		+ "0h:0m:0s - Cabin pressure - 5.00 Pounds per square inch (PSI)\n"
		+ "0h:0m:0s - Core temperature - 305.18 Degrees Celsius\n";
	TEST_ASSERT(expected == ss.str());

	// Reading 2
	t += Time(0, 0, 15);
	ms.takeReading(t);
	expected = string("0h:0m:0s - Horizontal rotation - 0.00 Radians\n")
		+ "0h:0m:0s - Cabin pressure - 5.00 Pounds per square inch (PSI)\n"
		+ "0h:0m:0s - Core temperature - 305.18 Degrees Celsius\n"
		+ "0h:0m:15s - Horizontal rotation - 2.50 Radians\n"
		+ "0h:0m:15s - Cabin pressure - 10.00 Pounds per square inch (PSI)\n"
		+ "0h:0m:15s - Core temperature - 305.18 Degrees Celsius\n";

	TestFramework::EndTest();
}

void TestMonitoringSystem_Take5Readings5Sensors()
{
	TestFramework::BeginTest("TestMonitoringSystem_Take5Readings5Sensors");

	stringstream ss;
	MonitoringSystem ms(ss);

	// Sensor 1
	SawtoothSignal sig1(0, Time(0, 0, 0), 0, 10, Time(0, 1, 0));
	AngularSensor sensor1("Horizontal rotation", sig1);
	ms.addSensor(&sensor1);

	// Sensor 2
	SineSignal sig2(0, Time(0, 0, 0), 0, 10, Time(0, 1, 0));
	PressureSensor sensor2("Cabin pressure", sig2);
	ms.addSensor(&sensor2);

	// Sensor 3
	ConstantSignal sig3(305.18, Time(0, 0, 0));
	TemperatureSensor sensor3("Core temperature", sig3);
	ms.addSensor(&sensor3);

	// Sensor 4
	ConstantSignal sig4(10, Time(0, 0, 0));
	VibrationSensor sensor4("Wing vibration", sig4);
	ms.addSensor(&sensor4);

	// Sensor 5
	SawtoothSignal sig5(0, Time(0, 0, 15), -10, 0, Time(0, 1, 0));
	AngularSensor sensor5("Vertical rotation", sig5);
	ms.addSensor(&sensor5);

	// Take 5 readings
	Time t = Time(0, 0, 0);
	for (int i = 0; i < 5; ++i)
	{
		ms.takeReading(t);
		t += Time(0, 0, 15);
	}

	// Verify readings
	string expected = string("0h:0m:0s - Horizontal rotation - 0.00 Radians\n")
		+ "0h:0m:0s - Cabin pressure - 5.00 Pounds per square inch (PSI)\n"
		+ "0h:0m:0s - Core temperature - 305.18 Degrees Celsius\n"
		+ "0h:0m:0s - Wing vibration - 10.00 Hertz (Hz)\n"
		+ "0h:0m:0s - Vertical rotation - -7.50 Radians\n" 
		+ "0h:0m:15s - Horizontal rotation - 2.50 Radians\n"
		+ "0h:0m:15s - Cabin pressure - 10.00 Pounds per square inch (PSI)\n"
		+ "0h:0m:15s - Core temperature - 305.18 Degrees Celsius\n"
		+ "0h:0m:15s - Wing vibration - 10.00 Hertz (Hz)\n"
		+ "0h:0m:15s - Vertical rotation - -5.00 Radians\n"
		+ "0h:0m:30s - Horizontal rotation - 5.00 Radians\n"
		+ "0h:0m:30s - Cabin pressure - 5.00 Pounds per square inch (PSI)\n"
		+ "0h:0m:30s - Core temperature - 305.18 Degrees Celsius\n"
		+ "0h:0m:30s - Wing vibration - 10.00 Hertz (Hz)\n"
		+ "0h:0m:30s - Vertical rotation - -2.50 Radians\n"
		+ "0h:0m:45s - Horizontal rotation - 7.50 Radians\n"
		+ "0h:0m:45s - Cabin pressure - 0.00 Pounds per square inch (PSI)\n"
		+ "0h:0m:45s - Core temperature - 305.18 Degrees Celsius\n"
		+ "0h:0m:45s - Wing vibration - 10.00 Hertz (Hz)\n"
		+ "0h:0m:45s - Vertical rotation - -10.00 Radians\n"
		+ "0h:1m:0s - Horizontal rotation - 0.00 Radians\n"
		+ "0h:1m:0s - Cabin pressure - 5.00 Pounds per square inch (PSI)\n"
		+ "0h:1m:0s - Core temperature - 305.18 Degrees Celsius\n"
		+ "0h:1m:0s - Wing vibration - 10.00 Hertz (Hz)\n"
		+ "0h:1m:0s - Vertical rotation - -7.50 Radians\n";
	TEST_ASSERT(expected == ss.str());

	TestFramework::EndTest();
}

void Project2UnitTest::TestMonitoringSystem()
{
	TestMonitoringSystem_takeReadingNoSensors();
	TestMonitoringSystem_takeReading1Sensors();
	TestMonitoringSystem_takeReading2Sensors();
	TestMonitoringSystem_Take2Readings3Sensors();
	TestMonitoringSystem_Take5Readings5Sensors();
}
