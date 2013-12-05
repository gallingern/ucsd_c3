/*
 * SavingsAccount.h
 *
 *  Created on: Oct 23, 2013
 *      Author: Nathaniel Gallinger
 */

#ifndef SAVINGSACCOUNT_H_
#define SAVINGSACCOUNT_H_

namespace NathanielGallinger
{
  class SavingsAccount
  {
  public:
    // Constructor
    SavingsAccount(double savingsBalance);

    // Accessor and Mutator
    inline double getSavingsBalance() const;
    static void setAnnualInterestRate(double annualInterestRate);

    // Display function
    void applyMonthlyInterest();


  private:
    // Private data members
    double savingsBalance;
    static double annualInterestRate;
  };

  // Accessor
  inline double SavingsAccount::getSavingsBalance() const
  {
    return savingsBalance;
  }
}

#endif /* SAVINGSACCOUNT_H_ */
