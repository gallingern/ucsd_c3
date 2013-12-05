/*
* Vending Machine Project
* CSE-40477
*
* ProductButton.h
* YOU MUST NOT CHANGE THIS FILE.
*/
#ifndef PROJECT1_PRODUCTBUTTON_H
#define PROJECT1_PRODUCTBUTTON_H

#include "Product.h"
#include "ProductRack.h"

namespace Project1
{
    //=========================================================================
    // SUMMARY
    //      A button associated with a product rack.  Pressing the button
    //      will cause  the associated product rack to deliver one of its
    //      products.
    //
    // RESOURCES
    //      A product button does not own any resources.
    //=========================================================================
    class ProductButton
    {
    public:
        //---------------------------------------------------------------------
        // SUMMARY
        //      Constructor.  Creates a product button associated with the
        //      given product rack.  When the button is pressed the given
        //      product rack will deliver one of its products.
        //
        // RESOURCES
        //      None
        //
        // PARAMETERS
        //      productRack
        //          The product rack that will deliver a product when the
        //          button is pressed.
        //
        // RETURNS
        //      Nothing
        //---------------------------------------------------------------------
        ProductButton(ProductRack &productRack);

        //---------------------------------------------------------------------
        // SUMMARY
        //      Causes the associated product rack to deliver its next available
        //      product.
        //
        // RESOURCES
        //      None
        //
        // PARAMETERS
        //      None
        //
        // RETURNS
        //      Whether the product rack was able to deliver a product.
        //---------------------------------------------------------------------
        bool press();

        //---------------------------------------------------------------------
        // SUMMARY
        //      Returns the price of products in the associated product rack.
        //
        // RESOURCES
        //      None
        //
        // PARAMETERS
        //      None
        //
        // RETURNS
        //      The price of products in the associated product rack.
        //---------------------------------------------------------------------
        unsigned getProductPriceCents() const;

    private:
        ProductRack &productRack;
    };
}

#endif
