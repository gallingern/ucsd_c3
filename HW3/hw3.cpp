/*
 * hw3.cpp
 *
 *  Created on: Oct 23, 2013
 *      Author: Nathaniel Gallinger
 */

#include "SavingsAccount.h"

#include <iostream>
using std::cout;

using NathanielGallinger::SavingsAccount;

int main()
{
  // Create SavingsAccount object
  cout << "Constructor with argument 1500: \n";
  SavingsAccount account1(1500);
  cout << "Interest rate 10%\n";
  account1.setAnnualInterestRate(10);
  account1.applyMonthlyInterest();
  cout << "Account Balance: " << account1.getSavingsBalance() << "\n";

  // Test error cases
  SavingsAccount account2(-5);
  account2.setAnnualInterestRate(-5);

}
