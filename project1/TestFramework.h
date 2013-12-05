/*
* Vending Machine Project
* CSE-40477
*
* TestFramework.h
* YOU MUST NOT CHANGE THIS FILE.
*/
#ifndef TESTFRAMEWORK_H
#define TESTFRAMEWORK_H

#include <iostream>
using std::ostream;

#include <string>
using std::string;

#include <vector>
using std::vector;

#define TEST_ASSERT(condition) \
    (TestFramework::Assert(condition, __FILE__, __LINE__))

class TestFramework
{
public:
    static void Initialize(ostream *pos);
    static void BeginTest(string name);
    static bool Assert(bool condition, string file, unsigned line);
    static void EndTest();
    static void DisplaySummary();

private:
    TestFramework();
    static ostream *pos;
    static string name;
    static vector<string> assertionResults;
    static bool passed;
    static unsigned totalTestsPassed;
    static unsigned totalTestsFailed;
};

#endif
