/*
 * SavingsAccount.cpp
 *
 *  Created on: Oct 23, 2013
 *      Author: Nathaniel Gallinger
 */

#include <iostream>
#include <ctime>
#include "SavingsAccount.h"
using std::cerr;
using std::cout;

double NathanielGallinger::SavingsAccount::annualInterestRate;

// Constructor
NathanielGallinger::SavingsAccount::SavingsAccount(double savingsBalance)
{
  // Check to make sure valid
  if(savingsBalance >= 0) {
    this->savingsBalance = savingsBalance;
  }
  else {
    cerr << "Constructor Error, input must be non-negative\n";
    this->savingsBalance = 0;
  }
}

// Mutator
void
NathanielGallinger::SavingsAccount::setAnnualInterestRate(double newAnnualInterestRate)
{
  // Check to make sure valid
  if(newAnnualInterestRate >= 0) {
    SavingsAccount::annualInterestRate = newAnnualInterestRate;
  }
  else {
    cerr << "Mutator Error, input must be non-negative\n";
    SavingsAccount::annualInterestRate = 0;
  }
}

// Apply Monthly Interest
void
NathanielGallinger::SavingsAccount::applyMonthlyInterest()
{
  const char months = 12;
  const char percentage = 100;
  this->savingsBalance += this->savingsBalance * (SavingsAccount::annualInterestRate / (months * percentage));
}
