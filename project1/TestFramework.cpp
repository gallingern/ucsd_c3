/*
* Vending Machine Project
* CSE-40477
*
* TestFramework.cpp
* YOU MUST NOT CHANGE THIS FILE.
*/
#include <iostream>
using std::endl;

#include <sstream>
using std::stringstream;

#include <string>
using std::string;

#include "TestFramework.h"

// Initialize static members
ostream *TestFramework::pos = 0;
string TestFramework::name = "";
vector<string> TestFramework::assertionResults = vector<string>();
bool TestFramework::passed = true;
unsigned TestFramework::totalTestsPassed = 0;
unsigned TestFramework::totalTestsFailed = 0;

void
TestFramework::Initialize(ostream *pos)
{
    TestFramework::pos = pos;
}

void
TestFramework::BeginTest(string name)
{
    *TestFramework::pos << ">>>>>> Beginning test '" << name << "'" << endl;

    TestFramework::name = name;
    TestFramework::assertionResults.clear();
    TestFramework::passed = true;
}

bool
TestFramework::Assert(bool condition, string file, unsigned line)
{
    if (!condition)
    {
        stringstream ss;
        TestFramework::passed = false;
        ss << "Assertion failed: file " << file << ", line " << line;
        TestFramework::assertionResults.push_back(ss.str());
    }

    return condition;
}

void
TestFramework::EndTest()
{
    if (TestFramework::passed)
    {
        ++TestFramework::totalTestsPassed;
    }
    else
    {
        ++TestFramework::totalTestsFailed;
    }

    // Display assertionResults
    for (size_t i = 0; i < TestFramework::assertionResults.size(); ++i)
    {
        *TestFramework::pos << "\t" << TestFramework::assertionResults[i]
        << endl;
    }

    // Display test result
    *TestFramework::pos << "<<<<<< Ending test '" << TestFramework::name
        << "' ";
    *TestFramework::pos << "---> "
        << (TestFramework::passed ? "Passed" : "FAILED") << endl << endl;
}

void
TestFramework::DisplaySummary()
{
    *TestFramework::pos << TestFramework::totalTestsPassed
        << " tests passed, " << TestFramework::totalTestsFailed
        << " tests failed" << endl << endl;
}
