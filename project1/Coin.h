/*
* Vending Machine Project
* CSE-40477
*
* Coin.h
* YOU MUST NOT CHANGE THIS FILE.
*/
#ifndef PROJECT1_COIN_H
#define PROJECT1_COIN_H

namespace Project1
{
    //=========================================================================
    // SUMMARY
    //      Represents coins up to a dollar in value.  Includes wooden nickel
    //      that represents a bad coin that is worth nothing.
    //
    // RESOURCES
    //      A coin does not own any resources.
    //=========================================================================
    class Coin
    {
    public:
        //---------------------------------------------------------------------
        // Types of coins.  The enumerator's numeric value is the coin's value
        // in cents.
        //---------------------------------------------------------------------
        enum CoinType
        {
            COINTYPE_WOODEN_NICKEL = 0,
            COINTYPE_PENNY = 1,
            COINTYPE_NICKEL = 5,
            COINTYPE_DIME = 10,
            COINTYPE_QUARTER = 25,
            COINTYPE_HALF_DOLLAR = 50,
            COINTYPE_DOLLAR = 100
        };

        //---------------------------------------------------------------------
        // SUMMARY
        //      Constructor.  Initializes the coin's denomination to the given
        //      type.
        //
        // RESOURCES
        //      None
        //
        // PARAMETERS
        //      denomination
        //          The coin's denomination.
        //
        // RETURNS
        //      Nothing
        //---------------------------------------------------------------------
        Coin(CoinType denomination);

        //---------------------------------------------------------------------
        // SUMMARY
        //      Returns the type of this coin.
        //
        // RESOURCES
        //      None
        //
        // PARAMETERS
        //      None
        //
        // RETURNS
        //      The type of this coin.
        //---------------------------------------------------------------------
        CoinType getDenomination() const;

        //---------------------------------------------------------------------
        // SUMMARY
        //      Returns the value of the coin in cents.
        //
        // RESOURCES
        //      None
        //
        // PARAMETERS
        //      None
        //
        // RETURNS
        //      The value of the coin in cents.
        //---------------------------------------------------------------------
        unsigned getValueCents() const;

    private:
        CoinType denomination;
    };
}

#endif
