/*
* Vending Machine Project
* CSE-40477
*
* UnitTest.h
* YOU MUST NOT CHANGE THIS FILE.
*
* Note:  In real-world development, a software developer writes unit tests
* for the code s/he produces.  These unit tests are intended to fully test
* the public interface of each class.  When an internal change is made
* to a class, the developer can re-run the unit-tests to verify that
* no part of the public interface was broken by the change.  Writing unit
* tests serves three major purposes:
*   1.  Unit tests allow you to test the functionality of each class
*       incrementally as development proceeds.
*   2.  Unit tests allow you to make changes to the internal implementation
*       of a class and be confident that the change hasn't broken
*       the public interface.
*   3.  Unit tests serve to document the public interface of each class.
*       Since unit tests demonstrate what is expected of a class' public
*       interface, they document how to use the class.  Unlike comments, the
*       self-documentation provided by unit tests won't become out-of-sync
*       with the classes, since the unit tests are compiled against
*       the classes.
*/
#ifndef UNITTEST_H
#define UNITTEST_H

#include <ostream>
using std::ostream;

namespace Project1UnitTest
{
    void Initialize(ostream &out);
    void DisplaySummary();
    void TestNothing();
    void TestCoin();
    void TestProduct();
    void TestDeliveryChute();
    void TestProductRack();
    void TestProductButton();
    void TestStatusPanel();
    void TestVendingMachine();
}

#endif
