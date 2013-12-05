/*
* Vending Machine Project
* CSE-40477
*
* Product.h
* YOU MUST NOT CHANGE THIS FILE.
*/
#ifndef PROJECT1_PRODUCT_H
#define PROJECT1_PRODUCT_H

namespace Project1
{
    //=========================================================================
    // SUMMARY
    //      A product (soda) having the given brand, name, and size.  Example
    //      brands include "Pepsi Cola" and "Coca Cola".  Example names include
    //      "Pepsi" and "Coke".  Example sizes include "12 fl oz".
    //
    // RESOURCES
    //      A product does not own any resources.
    //=========================================================================
    class Product
    {
    public:
        static const int MAX_BRAND_LENGTH = 25;
        static const int MAX_NAME_LENGTH = 25;
        static const int MAX_SIZE_LENGTH = 25;

        //---------------------------------------------------------------------
        // SUMMARY
        //      Constructor.  Creates a product of the given brand, name, and
        //      size.  The name identifies the product; two products with the
        //      same name are considered to be the same product type.
        //
        // RESOURCES
        //      None
        //
        // PARAMETERS
        //      brand
        //          The product's brand.  It is safe to assume brand will
        //          never be longer than MAX_BRAND_LENGTH.
        //      name
        //          The product's name.  This uniquely identifies the product;
        //          two products with the same name are considered to be the
        //          same product type.  It is safe to assume name will never
        //          be longer than MAX_NAME_LENGTH.
        //      size
        //          The product's size.  It is safe to assume size will never
        //          be longer than MAX_SIZE_LENGTH.
        //
        // RETURNS
        //      Nothing
        //---------------------------------------------------------------------
        Product(const char *brand, const char *name, const char *size);

        //---------------------------------------------------------------------
        // SUMMARY
        //      Get and set the product's brand.
        //
        // RESOURCES
        //      None
        //
        // PARAMETERS
        //      brand
        //          The product's brand (e.g. Coca-Cola).
        //
        // RETURNS
        //      The product's brand.
        //---------------------------------------------------------------------
        const char *getBrand() const;
        void setBrand(const char *value);

        //---------------------------------------------------------------------
        // SUMMARY
        //      Get and set the product's name.
        //
        // RESOURCES
        //      None
        //
        // PARAMETERS
        //      name
        //          The product's name (e.g. Coke).
        //
        // RETURNS
        //      The product's name.
        //---------------------------------------------------------------------
        const char *getName() const;
        void setName(const char *value);

        //---------------------------------------------------------------------
        // SUMMARY
        //      Get and set the product's size.
        //
        // RESOURCES
        //      None
        //
        // PARAMETERS
        //      size
        //          The product's size (e.g. 12 fl. oz.).
        //
        // RETURNS
        //      The product's size.
        //---------------------------------------------------------------------
        const char *getSize() const;
        void setSize(const char *value);

    private:
        char brand[MAX_BRAND_LENGTH];
        char name[MAX_NAME_LENGTH];
        char size[MAX_SIZE_LENGTH];
    };
}

#endif
