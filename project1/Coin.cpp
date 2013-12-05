/*
 * Vending Machine Project
 * CSE-40477
 *
 * Coin.cpp
 * YOU MUST IMPLEMENT THE FUNCTIONS IN THIS FILE.
 */
#include "Coin.h"

Project1::Coin::Coin(CoinType denomination)
: denomination(denomination)
{
  // Empty Constructor
}

Project1::Coin::CoinType
Project1::Coin::getDenomination() const
{
  return this->denomination;
}

unsigned
Project1::Coin::getValueCents() const
{
  return this->denomination;
}
