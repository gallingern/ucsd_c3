/*
* Vending Machine Project
* CSE-40477
*
* main.cpp
* YOU MUST NOT CHANGE THIS FILE.
*/

/*
// Uncomment this section and the section at the start of main to dump a memory
// leak report at program terimination when using Visual Studio.
// See http://msdn.microsoft.com/en-us/library/x98tx3cf.aspx for more info.
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
*/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include "UnitTest.h"

int main()
{
    /*
    // Uncomment this section and the section at the start of this file to
    // dump a memory leak report at program termination when using Visual
    // Studio.
    _CrtSetDbgFlag ( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
    */

    /*
    // Uncomment this section to set a memory-allocation breakpoint at the
    // given memory allocation number when using Visual Studio.
    _CrtSetBreakAlloc(947);
    */

    // Initialize
    Project1UnitTest::Initialize(cout);

    // Run tests
    Project1UnitTest::TestCoin();
    Project1UnitTest::TestProduct();
    Project1UnitTest::TestDeliveryChute();
    Project1UnitTest::TestProductRack();
    Project1UnitTest::TestProductButton();
    Project1UnitTest::TestStatusPanel();
    Project1UnitTest::TestVendingMachine();

    // Display test results
    Project1UnitTest::DisplaySummary();

    // Wait for user response
    cout << endl << "Press enter to continue...";
    cin.get();
}
