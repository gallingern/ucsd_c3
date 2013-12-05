/*
* Vending Machine Project
* CSE-40477
*
* VendingMachine.h
* YOU MUST NOT CHANGE THIS FILE.
*/
#ifndef PROJECT1_VENDINGMACHINE_H
#define PROJECT1_VENDINGMACHINE_H

#include <ostream>
using std::ostream;

#include "Coin.h"
#include "DeliveryChute.h"
#include "Product.h"
#include "ProductButton.h"
#include "ProductRack.h"
#include "StatusPanel.h"

namespace Project1
{
    //=========================================================================
    // SUMMARY
    //      A vending machine containing products (soft drinks).  Two types of
    //      users interact with a vending machine, customers and service
    //      professionals.
    // 
    //      A customer can insert coins into a coin slot, press any of the
    //      buttons to cause the appropriate product to be delivered if enough
    //      money has been inserted, retrieve a product from a delivery chute,
    //      and view a status panel to see diagnostic messages (e.g. not enough
    //      money was entered when a button was pressed, a button was pressed
    //      and the vending machine is out of the associated product, etc.).
    // 
    //      A service professional can add products to the vending machine,
    //      obtain a count of the number of products of a given type left in
    //      the machine, and obtain a sum of the total money in the machine.
    // 
    // RESOURCES
    //      A vending machine owns (i.e. is responsible for destroying)
    //      all products and coins that are inserted into the machine as well
    //      as any other objects it internally creates.  The vending machine
    //      relinquishes ownership of all products and coins that are removed
    //      from the vending machine.
    //=========================================================================
    class VendingMachine
    {
    public:
        static const int NUM_PRODUCT_RACKS = 3;
        static const int MAX_COINS = 200;

        //---------------------------------------------------------------------
        // SUMMARY
        //      Constructor.  Creates an empty vending machine (containing no
        //      products or coins).  The vending machine will be initialized to
        //      contain one product button connected to a product rack for each
        //      entry in the productNames list.  The products stored in
        //      each rack will be priced according to the corresponding entry
        //      in the productPrices list (e.g. the products in the rack for
        //      productNames[0] will have the price given by productPrices[0]).
        //      The vending machine and its underlying components (specifically
        //      DeliveryChute and ProductRack) will output all error messages
        //      to a status panel initialized to write to statusPanelStream.
        //
        // RESOURCES
        //      The vending machine will be initialized to not own any product
        //      or coins.
        //
        // PARAMETERS
        //      statusPanelStream
        //          The ostream to which error messages will be written during
        //          the operation of the vending machine.
        //      productNames
        //          The names of all products that the vending machine can
        //          hold.  A product rack will be created for each of these
        //          products.
        //      productPrices
        //          The prices of the products stored within the vending
        //          machine.  Each entry in this list corresponds
        //          to the product at the same index in the productNames list.
        //
        // RETURNS
        //      Nothing
        //---------------------------------------------------------------------
        VendingMachine(
            ostream &statusPanelStream,
            const char *productNames[NUM_PRODUCT_RACKS],
            unsigned productPrices[NUM_PRODUCT_RACKS]);

        //---------------------------------------------------------------------
        // SUMMARY
        //      Destructor.  Destroys the vending machine.
        //
        // RESOURCES
        //      All owned products, coins, and internally created objects are
        //      destroyed.
        //
        // PARAMETERS
        //      None
        //
        // RETURNS
        //      Nothing
        //---------------------------------------------------------------------
        ~VendingMachine();

        //---------------------------------------------------------------------
        // SUMMARY
        //      Inserts a coin into the vending machine coin slot; this
        //      increases the current balance that can be used to purchase
        //      products.  If the coin is invalid (a wooden nickel) the coin
        //      will be rejected and MESSAGE_CODE_BAD_COIN will be output to
        //      the status panel.  It is safe to assume that no more than
        //      MAX_COINS will ever be inserted into the vending machine.
        //
        // RESOURCES
        //      The vending machine takes ownership of the coin if and only if
        //      the coin is accepted.
        //
        // PARAMETERS
        //      pCoin
        //          The coin to be inserted into the vending machine.
        //
        // RETURNS
        //      Whether the coin was successfully inserted into the vending
        //      machine.
        //---------------------------------------------------------------------
        bool insertCoin(Coin *pCoin);

        //---------------------------------------------------------------------
        // SUMMARY
        //      Presses the given button (the buttons are indexed starting with
        //      zero).  If an invalid button was pressed 
        //      MESSAGE_CODE_WRONG_BUTTON will be output to the stauts panel.
        //      If not enough money was inserted into the vending machine to
        //      purchase a product from the rack associated with the given
        //      button MESSAGECODE_INSUFFICIENT_MONEY will be output.  If none
        //      of the cases occur the vending machine will delegate the remainder
        //      of the processing to the button.
        //
        // RESOURCES
        //      None
        //
        // PARAMETERS
        //      button
        //          The index of the button to be pressed.
        //
        // RETURNS
        //      Whether the press was succesful.  If it was successful then
        //      the product from the appropriate rack will have been dropped
        //      into the delivery chute and the available balance will have
        //      been reduced by the cost of the product.
        //---------------------------------------------------------------------
        bool pressButton(int button);

        //---------------------------------------------------------------------
        // SUMMARY
        //      Retrieves the product currently sitting in the delivery chute.
        //
        // RESOURCES
        //      The vending machine relinquishes ownership of the product in
        //      the delivery chute.
        //
        // PARAMETERS
        //      None
        //
        // RETURNS
        //      The product currently in the delivery or 0 if no product is
        //      currently in the delivery chute.
        //---------------------------------------------------------------------
        Product *retrieveProduct();

        //---------------------------------------------------------------------
        // SUMMARY
        //      Add the product to the vending machine.
        //
        // RESOURCES
        //      The vending machine takes ownership of the product if and only
        //      if the product is accepted.  If there is no product rack
        //      in the vending machine that is compatible with the product
        //      added then MESSAGECODE_NO_RACK_FOR_PRODUCT will be output to
        //      the status panel.
        //
        // PARAMETERS
        //      pProduct
        //          The product to be added to the vending machine.
        //
        // RETURNS
        //      Whether the product was successfully added to the vending
        //      machine.
        //---------------------------------------------------------------------
        bool addProduct(Product* pProduct);

        //---------------------------------------------------------------------
        // SUMMARY
        //      Return the number of products with the given name currently
        //      in the vending machine.  If no product racks exist that are
        //      compatible with the given name zero will be returned.
        //
        // RESOURCES
        //      None
        //
        // PARAMETERS
        //      productName
        //          The name of the product for which to return a count.
        //
        // RETURNS
        //      The number of products with the given name currently in the
        //      vending machine.  If no product racks exist that are
        //      compatible with the given name zero will be returned.
        //---------------------------------------------------------------------
        unsigned getProductCount(const char *productName) const;

        //---------------------------------------------------------------------
        // SUMMARY
        //      Return the sum of the values of all coins currently in the
        //      vending machine.
        //
        // RESOURCES
        //      None
        //
        // PARAMETERS
        //      None
        //
        // RETURNS
        //      The sum of the values of all coins currently in the vending
        //      machine.
        //---------------------------------------------------------------------
        unsigned countTill() const;

        //---------------------------------------------------------------------
        // SUMMARY
        //      Return the number of coins currently in the vending machine.
        //
        // RESOURCES
        //      None
        //
        // PARAMETERS
        //      None
        //
        // RETURNS
        //      The number of coins currently in the vending machine.
        //---------------------------------------------------------------------
        unsigned getNumCoinsInCoinBox() const;

    private:
        // A small display panel visible on the front of the vending machine.
        // As customers and service professionals use the vending machine
        // appropriate messages are displayed on this panel.
        StatusPanel statusPanel;

        // Delivery chute at the bottom front of the vending machine; when a
        // product is purchased it is dropped into this delivery chute; the
        // customer can then retrieve the product with her hand.
        DeliveryChute deliveryChute;

        // Buttons visible on the front of the vending machine that customers
        // may push to purchase a product.
        ProductButton *productButtons[NUM_PRODUCT_RACKS];

        // Racks of products within the vending machine.  Each rack is
        // associated with a button; when the button is pressed the rack will
        // release the next available product.
        ProductRack *productRacks[NUM_PRODUCT_RACKS];

        // All coins currently in the vending machine.
        Coin *coinBox[MAX_COINS];

        // Number of coins currently in the vending machine.
        unsigned numCoins;

        // Total monetary balance (in cents) remaining from coins that have
        // been inserted into the vending machine but not been spent on
        // purchasing products.
        unsigned unspentMoneyCents;
    }; 
}

#endif
