/*
* Vending Machine Project
* CSE-40477
*
* UnitTest.cpp
* YOU MUST NOT CHANGE THIS FILE.
*/
#include <cstring>
using std::strcmp;

#include <fstream>
using std::ostream;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <sstream>
using std::stringstream;

#include "TestFramework.h"
#include "UnitTest.h"

#include "VendingMachine.h"
using Project1::Coin;
using Project1::DeliveryChute;
using Project1::Product;
using Project1::ProductButton;
using Project1::ProductRack;
using Project1::StatusPanel;
using Project1::VendingMachine;

const char *productNames[] =
{
    "Coke",
    "Pepsi",
    "Sprite"
};

unsigned productPrices[] =
{
    25,
    25,
    25
};

void
Project1UnitTest::Initialize(ostream &out)
{
    TestFramework::Initialize(&out);
}

void
Project1UnitTest::DisplaySummary()
{
    TestFramework::DisplaySummary();
}

void
TestCoin_CoinTypeConstructor()
{
    TestFramework::BeginTest("TestCoin_CoinTypeConstructor");

    // CoinType constructor
    Coin coinCoinType(Coin::COINTYPE_PENNY);
    TEST_ASSERT(Coin::COINTYPE_PENNY == coinCoinType.getDenomination());

    TestFramework::EndTest();
}

void
TestCoin_AllDenominationsAndValues()
{
    TestFramework::BeginTest("TestCoin_AllDenominationsAndValues");

    // All denominations and values
    Coin coin1(Coin::COINTYPE_PENNY);
    TEST_ASSERT(Coin::COINTYPE_PENNY == coin1.getDenomination());
    TEST_ASSERT(1 == coin1.getValueCents());
    Coin coin2(Coin::COINTYPE_NICKEL);
    TEST_ASSERT(Coin::COINTYPE_NICKEL == coin2.getDenomination());
    TEST_ASSERT(5 == coin2.getValueCents());
    Coin coin3(Coin::COINTYPE_DIME);
    TEST_ASSERT(Coin::COINTYPE_DIME == coin3.getDenomination());
    TEST_ASSERT(10 == coin3.getValueCents());
    Coin coin4(Coin::COINTYPE_QUARTER);
    TEST_ASSERT(Coin::COINTYPE_QUARTER == coin4.getDenomination());
    TEST_ASSERT(25 == coin4.getValueCents());
    Coin coin5(Coin::COINTYPE_HALF_DOLLAR);
    TEST_ASSERT(Coin::COINTYPE_HALF_DOLLAR == coin5.getDenomination());
    TEST_ASSERT(50 == coin5.getValueCents());
    Coin coin6(Coin::COINTYPE_DOLLAR);
    TEST_ASSERT(Coin::COINTYPE_DOLLAR == coin6.getDenomination());
    TEST_ASSERT(100 == coin6.getValueCents());

    TestFramework::EndTest();
}

void
Project1UnitTest::TestCoin()
{
    TestCoin_CoinTypeConstructor();
    TestCoin_AllDenominationsAndValues();
}

void
TestProduct_Constructor()
{
    TestFramework::BeginTest("TestProduct_Constructor");

    // Constructor
    Product p1("Coca Cola", "Coke", "12 fl oz");
    TEST_ASSERT(strcmp("Coca Cola", p1.getBrand()) == 0);
    TEST_ASSERT(strcmp("Coke", p1.getName()) == 0);
    TEST_ASSERT(strcmp("12 fl oz", p1.getSize()) == 0);

    TestFramework::EndTest();
}

void
TestProduct_GettersSetters()
{
    TestFramework::BeginTest("TestProduct_GettersSetters");

    // All getters & setters
    Product p2("", "", "");
    p2.setBrand("Pepsi Cola");
    TEST_ASSERT(strcmp("Pepsi Cola", p2.getBrand()) == 0);
    p2.setName("Pepsi");
    TEST_ASSERT(strcmp("Pepsi", p2.getName()) == 0);
    p2.setSize("24 fl oz");
    TEST_ASSERT(strcmp("24 fl oz", p2.getSize()) == 0);

    TestFramework::EndTest();
}

void
Project1UnitTest::TestProduct()
{
    TestProduct_Constructor();
    TestProduct_GettersSetters();
}

void
TestDeliveryChute_Constructor()
{
    TestFramework::BeginTest("TestDeliveryChute_Constructor");

    // Constructor
    stringstream ss1;
    StatusPanel sp1(ss1);
    DeliveryChute d1(sp1);
    TEST_ASSERT(0 == d1.retrieveProduct());

    TestFramework::EndTest();
}

void
TestDeliveryChute_DroppingProductIntoEmptyChute()
{
    TestFramework::BeginTest(
        "TestDeliveryChute_DroppingProductIntoEmptyChute");

    // Dropping product into empty chute
    stringstream ss1;
    StatusPanel sp1(ss1);
    DeliveryChute d2(sp1);
    TEST_ASSERT(d2.insertProduct(
        new Product("Coca Cola", "Coke", "12 fl oz")));
    Product *p2 = d2.retrieveProduct();
    TEST_ASSERT(0 != p2);
    TEST_ASSERT(strcmp("Coca Cola", p2->getBrand()) == 0);
    delete p2;

    TestFramework::EndTest();
}

void
TestDeliveryChute_DroppingProductIntoNonEmptyChute()
{
    TestFramework::BeginTest(
        "TestDeliveryChute_DroppingProductIntoNonEmptyChute");

    // Dropping product into non-empty chute
    stringstream ss1;
    StatusPanel sp1(ss1);
    DeliveryChute d3(sp1);
    d3.insertProduct(new Product("Coca Cola", "Coke", "12 fl oz"));
    Product *p3 = new Product("Pepsi Cola", "Pepsi", "24 fl oz");
    TEST_ASSERT(!d3.insertProduct(p3));
    delete p3;
    p3 = d3.retrieveProduct();
    TEST_ASSERT(p3 != 0);
    TEST_ASSERT(strcmp("Coca Cola", p3->getBrand()) == 0);
    delete p3;

    TestFramework::EndTest();
}

void
TestDeliveryChute_ErrorMessages()
{
    TestFramework::BeginTest(
        "TestDeliveryChute_ErrorMessages");

    // Insert product into full chute
    stringstream ss1;
    StatusPanel sp1(ss1);
    DeliveryChute dc1(sp1);
    dc1.insertProduct(new Product("Coca Cola", "Coke", "12 fl oz"));
    Product *p1 = new Product("Pepsi Cola", "Pepsi", "24 fl oz");
    TEST_ASSERT(!dc1.insertProduct(p1));
    TEST_ASSERT("Cannot purchase product; a product is already in delivery chute\n" == ss1.str());
    delete p1;

    TestFramework::EndTest();
}

void
Project1UnitTest::TestDeliveryChute()
{
    TestDeliveryChute_Constructor();
    TestDeliveryChute_DroppingProductIntoEmptyChute();
    TestDeliveryChute_DroppingProductIntoNonEmptyChute();
    TestDeliveryChute_ErrorMessages();
}

void
TestProductRack_Constructor()
{
    TestFramework::BeginTest("TestProductRack_Constructor");

    // Constructor
    stringstream ss1;
    StatusPanel sp1(ss1);
    DeliveryChute c1(sp1);
    ProductRack pr1(sp1, "Coke", c1, 25);
    TEST_ASSERT(pr1.isCompatibleProduct("Coke"));
    TEST_ASSERT(!pr1.isCompatibleProduct("Pepsi"));

    TestFramework::EndTest();
}

void
TestProductRack_deliverProductFromEmptyRack()
{
    TestFramework::BeginTest("TestProductRack_deliverProductFromEmptyRack");

    // Deliver product from empty rack
    stringstream ss1;
    StatusPanel sp1(ss1);
    DeliveryChute c2(sp1);
    ProductRack pr2(sp1, "Coke", c2, 25);
    TEST_ASSERT(!pr2.deliverProduct());

    TestFramework::EndTest();
}

void
TestProductRack_AddAndDeliverOneProduct()
{
    TestFramework::BeginTest("TestProductRack_AddAndDeliverOneProduct");

    // Add & deliver 1 product
    stringstream ss1;
    StatusPanel sp1(ss1);
    DeliveryChute c3(sp1);
    ProductRack pr3(sp1, "Coke", c3, 25);
    Product *p3 = new Product("Coca Cola", "Coke", "12 fl oz");
    TEST_ASSERT(pr3.addProduct(p3));
    TEST_ASSERT(pr3.deliverProduct());
    Product *p3Copy = c3.retrieveProduct();
    TEST_ASSERT(p3 == p3Copy);
    delete p3Copy;
    TEST_ASSERT(!pr3.deliverProduct());

    TestFramework::EndTest();
}

void
TestProductRack_AddAndDeliverTwoProducts()
{
    TestFramework::BeginTest("TestProductRack_AddAndDeliverTwoProducts");

    // Add & deliver 2 products
    stringstream ss1;
    StatusPanel sp1(ss1);
    DeliveryChute c4(sp1);
    ProductRack pr4(sp1, "Coke", c4, 25);
    TEST_ASSERT(pr4.addProduct(new Product("Coca Cola", "Coke", "12 fl oz")));
    TEST_ASSERT(pr4.addProduct(new Product("Coca Cola", "Coke", "12 fl oz")));
    Product *p4;
    TEST_ASSERT(pr4.deliverProduct());
    p4 = c4.retrieveProduct();
    TEST_ASSERT(0 != p4);
    TEST_ASSERT(strcmp("Coke", p4->getName()) == 0);
    delete p4;
    TEST_ASSERT(pr4.deliverProduct());
    p4 = c4.retrieveProduct();
    TEST_ASSERT(0 != p4);
    TEST_ASSERT(strcmp("Coke", p4->getName()) == 0);
    delete p4;
    TEST_ASSERT(!pr4.deliverProduct());

    TestFramework::EndTest();
}

void
TestProductRack_AddTooManyProducts()
{
    TestFramework::BeginTest("TestProductRack_AddTooManyProducts");

    // Add too many products
    stringstream ss1;
    StatusPanel sp1(ss1);
    DeliveryChute c6(sp1);
    ProductRack pr6(sp1, "Coke", c6, 25);
    for (int i = 0; i < ProductRack::MAX_PRODUCTS; ++i)
    {
        TEST_ASSERT(pr6.addProduct(
            new Product("Coca Cola", "Coke", "12 fl oz")));
    }
    Product *p6 = new Product("Coca Cola", "Coke", "12 fl oz");
    TEST_ASSERT(!pr6.addProduct(p6));
    delete p6;
    for (int i = 0; i < ProductRack::MAX_PRODUCTS; ++i)
    {
        TEST_ASSERT(pr6.deliverProduct());
        p6 = c6.retrieveProduct();
        TEST_ASSERT(0 != p6);
        delete p6;
    }
    TEST_ASSERT(!pr6.deliverProduct());

    TestFramework::EndTest();
}

void
TestProductRack_InvalidProductName()
{
    TestFramework::BeginTest("TestProductRack_InvalidProductName");

    // Add product name that doesn't match an allowed name in a product rack
    stringstream ss1;
    StatusPanel sp1(ss1);
    DeliveryChute c6(sp1);
    ProductRack pr6(sp1, "Coke", c6, 25);
    Product *p6 = new Product(
        "Coca Cola", "Unmatched product name", "12 fl oz");
    TEST_ASSERT(!pr6.addProduct(p6));
    delete p6;

    TestFramework::EndTest();
}

void
TestProductRack_IsEmpty()
{
    TestFramework::BeginTest("TestProductRack_IsEmpty");

    // Verify empty
    stringstream ss1;
    StatusPanel sp1(ss1);
    DeliveryChute c6(sp1);
    ProductRack pr6(sp1, "Coke", c6, 25);
    TEST_ASSERT(pr6.isEmpty());

    // Verify not empty
    Product *p6 = new Product("Coca Cola", "Coke", "12 fl oz");
    pr6.addProduct(p6);
    TEST_ASSERT(!pr6.isEmpty());
    TEST_ASSERT(pr6.deliverProduct());
    TEST_ASSERT(0 != c6.retrieveProduct());
    delete p6;

    TestFramework::EndTest();
}

void
TestProductRack_IsFull()
{
    TestFramework::BeginTest("TestProductRack_IsFull");

    // Verify not full
    stringstream ss1;
    StatusPanel sp1(ss1);
    DeliveryChute c6(sp1);
    ProductRack pr6(sp1, "Coke", c6, 25);
    TEST_ASSERT(!pr6.isFull());

    // Verify full
    Product *p6;
    for (int i = 0; i < ProductRack::MAX_PRODUCTS; ++i)
    {
        p6 = new Product("Coca Cola", "Coke", "12 fl oz");
        pr6.addProduct(p6);
    }
    TEST_ASSERT(pr6.isFull());
    for (int i = 0; i < ProductRack::MAX_PRODUCTS; ++i)
    {
        TEST_ASSERT(pr6.deliverProduct());
        TEST_ASSERT((p6 = c6.retrieveProduct()) != 0);
        delete p6;
    }

    TestFramework::EndTest();
}

void
TestProductRack_ErrorMessages()
{
    TestFramework::BeginTest(
        "TestProductRack_ErrorMessages");

    // Insert product into full rack
    stringstream ss1;
    StatusPanel sp1(ss1);
    DeliveryChute dc1(sp1);
    ProductRack pr1(sp1, "Coke", dc1, 25);
    Product *p1;
    for (int i = 0; i < ProductRack::MAX_PRODUCTS; ++i)
    {
        p1 = new Product("Coca Cola", "Coke", "12 fl oz");
        pr1.addProduct(p1);
    }
    p1 = new Product("Coca Cola", "Coke", "12 fl oz");
    TEST_ASSERT(!pr1.addProduct(p1));
    delete p1;
    TEST_ASSERT("The rack for the named product is full\n" == ss1.str());

    // Insert incompatible product into rack
    stringstream ss2;
    StatusPanel sp2(ss2);
    DeliveryChute dc2(sp2);
    ProductRack pr2(sp2, "Coke", dc2, 25);
    Product *p2 = new Product("Pepsi Cola", "Pepsi", "24 fl oz");
    TEST_ASSERT(!pr2.addProduct(p2));
    delete p2;
    TEST_ASSERT("Product name does not match product rack allowed name\n" == ss2.str());

    // Deliver product from empty rack
    stringstream ss3;
    StatusPanel sp3(ss3);
    DeliveryChute dc3(sp3);
    ProductRack pr3(sp3, "Coke", dc3, 25);
    TEST_ASSERT(!pr3.deliverProduct());
    TEST_ASSERT("Product sold out\n" == ss3.str());

    TestFramework::EndTest();
}

void
Project1UnitTest::TestProductRack()
{
    TestProductRack_Constructor();
    TestProductRack_deliverProductFromEmptyRack();
    TestProductRack_AddAndDeliverOneProduct();
    TestProductRack_AddAndDeliverTwoProducts();
    TestProductRack_AddTooManyProducts();
    TestProductRack_InvalidProductName();
    TestProductRack_IsEmpty();
    TestProductRack_IsFull();
    TestProductRack_ErrorMessages();
}

void
TestProductButton_Constructor()
{
    TestFramework::BeginTest("TestProductButton_Constructor");

    // Constructor
    stringstream ss1;
    StatusPanel sp1(ss1);
    DeliveryChute c1(sp1);
    ProductRack pr1(sp1, "Coke", c1, 25);
    ProductButton pb1(pr1);
    TEST_ASSERT(!pb1.press());

    TestFramework::EndTest();
}

void
TestProductButton_pressingWithAProductInTheRack()
{
    TestFramework::BeginTest(
        "TestProductButton_pressingWithAProductInTheRack");

    // pressing with a product in the rack
    stringstream ss1;
    StatusPanel sp1(ss1);
    DeliveryChute c2(sp1);
    ProductRack pr2(sp1, "Coke", c2, 25);
    ProductButton pb2(pr2);
    Product *p2 = new Product("Coca Cola", "Coke", "12 fl oz");
    pr2.addProduct(p2);
    TEST_ASSERT(pb2.press());
    Product *p2Copy = c2.retrieveProduct();
    TEST_ASSERT(p2 == p2Copy);
    delete p2Copy;

    TestFramework::EndTest();
}

void
Project1UnitTest::TestProductButton()
{
    TestProductButton_Constructor();
    TestProductButton_pressingWithAProductInTheRack();
}

void
TestStatusPanel_DisplayMessage()
{
    TestFramework::BeginTest("TestStatusPanel_Display");

    // NO_RACK_FOR_PRODUCT
    stringstream ss1;
    StatusPanel sp1(ss1);
    sp1.displayMessage(StatusPanel::MESSAGECODE_NO_RACK_FOR_PRODUCT);
    TEST_ASSERT("No rack designated for the named product\n" == ss1.str());

    // RACK_IS_FULL
    stringstream ss2;
    StatusPanel sp2(ss2);
    sp2.displayMessage(StatusPanel::MESSAGECODE_RACK_IS_FULL);
    TEST_ASSERT("The rack for the named product is full\n" == ss2.str());

    // BAD_COIN
    stringstream ss3;
    StatusPanel sp3(ss3);
    sp3.displayMessage(StatusPanel::MESSAGECODE_BAD_COIN);
    TEST_ASSERT("Bad coin inserted\n" == ss3.str());

    // SOLD_OUT
    stringstream ss4;
    StatusPanel sp4(ss4);
    sp4.displayMessage(StatusPanel::MESSAGECODE_SOLD_OUT);
    TEST_ASSERT("Product sold out\n" == ss4.str());

    // WRONG_BUTTON
    stringstream ss5;
    StatusPanel sp5(ss5);
    sp5.displayMessage(StatusPanel::MESSAGECODE_WRONG_BUTTON);
    TEST_ASSERT("You're pressing a nasty old chewing gum wad, not a button!\n"
        == ss5.str());

    // INSUFFICIENT_MONEY
    stringstream ss6;
    StatusPanel sp6(ss6);
    sp6.displayMessage(StatusPanel::MESSAGECODE_INSUFFICIENT_MONEY);
    TEST_ASSERT(
        "Insufficient money to make purchase, "
        "insert more money then try again\n" == ss6.str());

    TestFramework::EndTest();
}

void
Project1UnitTest::TestStatusPanel()
{
    TestStatusPanel_DisplayMessage();
}

void
TestVendingMachine_Constructor()
{
    TestFramework::BeginTest("TestVendingMachine_Constructor");

    // Constructor
    stringstream ss1;
    VendingMachine vm1(ss1, productNames, productPrices);
    TEST_ASSERT(0 == vm1.retrieveProduct());
    TEST_ASSERT(0 == vm1.getProductCount("Coke"));
    TEST_ASSERT(0 == vm1.getProductCount("Pepsi"));
    TEST_ASSERT(0 == vm1.getProductCount("Sprite"));
    TEST_ASSERT(0 == vm1.countTill());

    TestFramework::EndTest();
}

void
TestVendingMachine_BuyOneProduct()
{
    TestFramework::BeginTest("TestVendingMachine_BuyOneProduct");

    // Buy 1 product
    stringstream ss2;
    VendingMachine vm2(ss2, productNames, productPrices);
    Product *p2 = new Product("Coca Cola", "Coke", "12 fl oz");
    TEST_ASSERT(vm2.addProduct(p2));
    TEST_ASSERT(1 == vm2.getProductCount("Coke"));
    TEST_ASSERT(0 == vm2.getProductCount("Pepsi"));
    TEST_ASSERT(0 == vm2.getProductCount("Sprite"));
    Coin *c2 = new Coin(Coin::COINTYPE_QUARTER);
    TEST_ASSERT(vm2.insertCoin(c2));
    TEST_ASSERT(vm2.pressButton(0));
    Product *p2Copy = vm2.retrieveProduct();
    TEST_ASSERT(p2 == p2Copy);
    TEST_ASSERT(0 == vm2.getProductCount("Coke"));
    TEST_ASSERT(25 == vm2.countTill());
    delete p2Copy;

    TestFramework::EndTest();
}

void
TestVendingMachine_BuyOneProductWithNoCoins()
{
    TestFramework::BeginTest("TestVendingMachine_BuyOneProductWithNoCoins");

    // Attempt to buy 1 product without inserting any coins
    stringstream ss3;
    VendingMachine vm3(ss3, productNames, productPrices);
    Product *p3 = new Product("Coca Cola", "Coke", "12 fl oz");
    vm3.addProduct(p3);
    TEST_ASSERT(!vm3.pressButton(0));
    Product *p3Copy = vm3.retrieveProduct();
    TEST_ASSERT(0 == p3Copy);
    TEST_ASSERT(1 == vm3.getProductCount("Coke"));
    TEST_ASSERT(0 == vm3.countTill());

    TestFramework::EndTest();
}

void
TestVendingMachine_BuyOneProductWithInsufficientCoins()
{
    TestFramework::BeginTest(
        "TestVendingMachine_BuyOneProductWithInsufficientCoins");

    // Attempt to buy 1 product inserting insufficient coins
    stringstream ss4;
    VendingMachine vm4(ss4, productNames, productPrices);
    Product *p4 = new Product("Coca Cola", "Coke", "12 fl oz");
    vm4.addProduct(p4);
    Coin *c4_1 = new Coin(Coin::COINTYPE_DIME);
    Coin *c4_2 = new Coin(Coin::COINTYPE_PENNY);
    vm4.insertCoin(c4_1);
    vm4.insertCoin(c4_2);
    TEST_ASSERT(!vm4.pressButton(0));
    Product *p4Copy = vm4.retrieveProduct();
    TEST_ASSERT(0 == p4Copy);
    TEST_ASSERT(1 == vm4.getProductCount("Coke"));
    TEST_ASSERT(11 == vm4.countTill());

    TestFramework::EndTest();
}

void
TestVendingMachine_BuyOneProductWithTooManyCoins()
{
    TestFramework::BeginTest(
        "TestVendingMachine_BuyOneProductWithTooManyCoins");

    // Buy 1 product entering more than enough money
    stringstream ss5;
    VendingMachine vm5(ss5, productNames, productPrices);
    Product *p5 = new Product("Coca Cola", "Coke", "12 fl oz");
    vm5.addProduct(p5);
    Coin *c5 = new Coin(Coin::COINTYPE_DOLLAR);
    vm5.insertCoin(c5);
    TEST_ASSERT(vm5.pressButton(0));
    Product *p5Copy = vm5.retrieveProduct();
    TEST_ASSERT(p5 == p5Copy);
    TEST_ASSERT(0 == vm5.getProductCount("Coke"));
    TEST_ASSERT(100 == vm5.countTill());
    delete p5Copy;

    TestFramework::EndTest();
}

void
TestVendingMachine_insertCoinsForTwoProductsThenBuyTwo()
{
    TestFramework::BeginTest(
        "TestVendingMachine_insertCoinsForTwoProductsThenBuyTwo");

    // Buy 2 products entering more than enough money before buying either
    stringstream ss6;
    VendingMachine vm6(ss6, productNames, productPrices);
    Product *p6_1 = new Product("Coca Cola", "Coke", "12 fl oz");
    Product *p6_2 = new Product("Pepsi Cola", "Pepsi", "12 fl oz");
    vm6.addProduct(p6_1);
    vm6.addProduct(p6_2);
    Coin *c6 = new Coin(Coin::COINTYPE_DOLLAR);
    vm6.insertCoin(c6);
    TEST_ASSERT(vm6.pressButton(0));
    Product *p6_1Copy = vm6.retrieveProduct();
    TEST_ASSERT(p6_1 == p6_1Copy);
    TEST_ASSERT(vm6.pressButton(1));
    Product *p6_2Copy = vm6.retrieveProduct();
    TEST_ASSERT(p6_2 == p6_2Copy);
    TEST_ASSERT(0 == vm6.getProductCount("Coke"));
    TEST_ASSERT(0 == vm6.getProductCount("Pepsi"));
    TEST_ASSERT(100 == vm6.countTill());
    delete p6_1Copy;
    delete p6_2Copy;

    TestFramework::EndTest();
}

void
TestVendingMachine_InsertAllValidCoins()
{
    TestFramework::BeginTest("TestVendingMachine_InsertAllValidCoins");

    // Insert every possible coin
    stringstream ss7;
    VendingMachine vm7(ss7, productNames, productPrices);
    Coin *c7_1 = new Coin(Coin::COINTYPE_DIME);
    Coin *c7_2 = new Coin(Coin::COINTYPE_DOLLAR);
    Coin *c7_3 = new Coin(Coin::COINTYPE_HALF_DOLLAR);
    Coin *c7_4 = new Coin(Coin::COINTYPE_NICKEL);
    Coin *c7_5 = new Coin(Coin::COINTYPE_PENNY);
    Coin *c7_6 = new Coin(Coin::COINTYPE_QUARTER);
    TEST_ASSERT(vm7.insertCoin(c7_1));
    TEST_ASSERT(vm7.insertCoin(c7_2));
    TEST_ASSERT(vm7.insertCoin(c7_3));
    TEST_ASSERT(vm7.insertCoin(c7_4));
    TEST_ASSERT(vm7.insertCoin(c7_5));
    TEST_ASSERT(vm7.insertCoin(c7_6));
    TEST_ASSERT(191 == vm7.countTill());

    TestFramework::EndTest();
}

void
TestVendingMachine_InsertInvalidCoin()
{
    TestFramework::BeginTest("TestVendingMachine_InsertInvalidCoin");

    // Insert invalid coin
    stringstream ss8;
    VendingMachine vm8(ss8, productNames, productPrices);
    Coin *c8 = new Coin(Coin::COINTYPE_WOODEN_NICKEL);
    TEST_ASSERT(!vm8.insertCoin(c8));
    TEST_ASSERT(0 == vm8.countTill());
    delete c8;

    TestFramework::EndTest();
}

void
TestVendingMachine_InsertInvalidProduct()
{
    TestFramework::BeginTest("TestVendingMachine_InsertInvalidProduct");

    // Add an invalid product
    stringstream ss9;
    VendingMachine vm9(ss9, productNames, productPrices);
    Product *p9 = new Product("7Up, The Un-Cola", "7Up", "12 fl oz");
    TEST_ASSERT(!vm9.addProduct(p9));
    TEST_ASSERT(0 == vm9.getProductCount("Coke"));
    TEST_ASSERT(0 == vm9.getProductCount("Pepsi"));
    TEST_ASSERT(0 == vm9.getProductCount("Sprite"));
    delete p9;

    TestFramework::EndTest();
}

void
TestVendingMachine_AddTooManyProducts()
{
    TestFramework::BeginTest("TestVendingMachine_AddTooManyProducts");

    // Add too many products
    stringstream ss10;
    VendingMachine vm10(ss10, productNames, productPrices);
    Product *p10;
    for (int i = 0; i < ProductRack::MAX_PRODUCTS; ++i)
    {
        p10 = new Product("Coca Cola", "Coke", "12 fl oz");
        TEST_ASSERT(vm10.addProduct(p10));
    }
    p10 = new Product("Coca Cola", "Coke", "12 fl oz");
    TEST_ASSERT(!vm10.addProduct(p10));
    delete p10;

    TestFramework::EndTest();
}

void
TestVendingMachine_BuyAndSellFullCapacityOfRacks()
{
    TestFramework::BeginTest(
        "TestVendingMachine_BuyAndSellFullCapacityOfRacks");

    // Buy / sell full capacity of each rack
    stringstream ss11;
    VendingMachine vm11(ss11, productNames, productPrices);
    int i;
    for (i = 0; i < ProductRack::MAX_PRODUCTS; ++i)
    {
        TEST_ASSERT(vm11.addProduct(
            new Product("Coca Cola", "Coke", "12 fl oz")));
        TEST_ASSERT(vm11.addProduct(
            new Product("Pepsi Cola", "Pepsi", "12 fl oz")));
        TEST_ASSERT(vm11.addProduct(
            new Product("Sprite", "Sprite", "12 fl oz")));
    }
    TEST_ASSERT(ProductRack::MAX_PRODUCTS == vm11.getProductCount("Coke"));
    TEST_ASSERT(ProductRack::MAX_PRODUCTS == vm11.getProductCount("Pepsi"));
    TEST_ASSERT(ProductRack::MAX_PRODUCTS == vm11.getProductCount("Sprite"));
    for (i = 0; i < ProductRack::MAX_PRODUCTS; ++i)
    {
        Coin *c11 = new Coin(Coin::COINTYPE_QUARTER);
        TEST_ASSERT(vm11.insertCoin(c11));
        TEST_ASSERT(vm11.pressButton(0));
        Product *p11 = vm11.retrieveProduct();
        TEST_ASSERT(0 != p11);
        delete p11;
    }
    for (i = 0; i < ProductRack::MAX_PRODUCTS; ++i)
    {
        Coin *c11 = new Coin(Coin::COINTYPE_QUARTER);
        TEST_ASSERT(vm11.insertCoin(c11));
        TEST_ASSERT(vm11.pressButton(1));
        Product *p11 = vm11.retrieveProduct();
        TEST_ASSERT(0 != p11);
        delete p11;
    }
    for (i = 0; i < ProductRack::MAX_PRODUCTS; ++i)
    {
        Coin *c11 = new Coin(Coin::COINTYPE_QUARTER);
        TEST_ASSERT(vm11.insertCoin(c11));
        TEST_ASSERT(vm11.pressButton(2));
        Product *p11 = vm11.retrieveProduct();
        TEST_ASSERT(0 != p11);
        delete p11;
    }
    TEST_ASSERT(0 == vm11.getProductCount("Coke"));
    TEST_ASSERT(0 == vm11.getProductCount("Pepsi"));
    TEST_ASSERT(0 == vm11.getProductCount("Sprite"));
    TEST_ASSERT(3 * ProductRack::MAX_PRODUCTS * 25 == vm11.countTill());

    TestFramework::EndTest();
}

void
TestVendingMachine_ErrorMessages()
{
    TestFramework::BeginTest("TestVendingMachine_VerifyErrorMessages");

    // NO_RACK_FOR_PRODUCT error message
    stringstream ss13;
    VendingMachine vm13(ss13, productNames, productPrices);
    Product *p13 = new Product("7Up, The Un-Cola", "7Up", "12 fl oz");
    TEST_ASSERT(!vm13.addProduct(p13));
    delete p13;
    TEST_ASSERT("No rack designated for the named product\n" == ss13.str());

    // RACK_IS_FULL error message (should be handled by internal rack)
    stringstream ss14;
    VendingMachine vm14(ss14, productNames, productPrices);
    Product *p14;
    for (int i = 0; i < ProductRack::MAX_PRODUCTS; ++i)
    {
        p14 = new Product("Coca Cola", "Coke", "12 fl oz");
        TEST_ASSERT(vm14.addProduct(p14));
    }
    p14 = new Product("Coca Cola", "Coke", "12 fl oz");
    TEST_ASSERT(!vm14.addProduct(p14));
    delete p14;
    TEST_ASSERT("The rack for the named product is full\n" == ss14.str());

    // BAD_COIN error message
    stringstream ss15;
    VendingMachine vm15(ss15, productNames, productPrices);
    Coin *c15 = new Coin(Coin::COINTYPE_WOODEN_NICKEL);
    TEST_ASSERT(!vm15.insertCoin(c15));
    TEST_ASSERT("Bad coin inserted\n" == ss15.str());
    delete c15;

    // SOLD_OUT error message )(should be handled by internal rack)
    stringstream ss16;
    VendingMachine vm16(ss16, productNames, productPrices);
    Coin *c16 = new Coin(Coin::COINTYPE_QUARTER);
    TEST_ASSERT(vm16.insertCoin(c16));
    TEST_ASSERT(!vm16.pressButton(0));
    TEST_ASSERT("Product sold out\n" == ss16.str());

    // WRONG_BUTTON error message
    stringstream ss17;
    VendingMachine vm17(ss17, productNames, productPrices);
    Coin *c17 = new Coin(Coin::COINTYPE_QUARTER);
    TEST_ASSERT(vm17.insertCoin(c17));
    TEST_ASSERT(!vm17.pressButton(7));
    TEST_ASSERT(
        "You're pressing a nasty old chewing gum wad, not a button!\n"
        == ss17.str());

    // INSUFFICIENT_MONEY error message
    stringstream ss18;
    VendingMachine vm18(ss18, productNames, productPrices);
    Coin *c18 = new Coin(Coin::COINTYPE_PENNY);
    TEST_ASSERT(vm18.insertCoin(c18));
    Product *p18 = new Product("Coca Cola", "Coke", "12 fl oz");
    TEST_ASSERT(vm18.addProduct(p18));
    TEST_ASSERT(!vm18.pressButton(0));
    TEST_ASSERT(
        "Insufficient money to make purchase, "
        "insert more money then try again\n" == ss18.str());

    TestFramework::EndTest();
}

void
TestVendingMachine_CoinBox()
{
    TestFramework::BeginTest("TestVendingMachine_CoinBox");

    // Constructor
    stringstream ss1;
    VendingMachine vm1(ss1, productNames, productPrices);
    vm1.insertCoin(new Coin(Coin::COINTYPE_PENNY));
    vm1.insertCoin(new Coin(Coin::COINTYPE_NICKEL));
    vm1.insertCoin(new Coin(Coin::COINTYPE_DIME));
    vm1.insertCoin(new Coin(Coin::COINTYPE_QUARTER));
    vm1.insertCoin(new Coin(Coin::COINTYPE_HALF_DOLLAR));
    vm1.insertCoin(new Coin(Coin::COINTYPE_DOLLAR));
    TEST_ASSERT(191 == vm1.countTill());
    unsigned numCoins = vm1.getNumCoinsInCoinBox();
    TEST_ASSERT(6 == numCoins);

    TestFramework::EndTest();
}

void
Project1UnitTest::TestVendingMachine()
{
    TestVendingMachine_Constructor();
    TestVendingMachine_BuyOneProduct();
    TestVendingMachine_BuyOneProductWithNoCoins();
    TestVendingMachine_BuyOneProductWithInsufficientCoins();
    TestVendingMachine_BuyOneProductWithTooManyCoins();
    TestVendingMachine_insertCoinsForTwoProductsThenBuyTwo();
    TestVendingMachine_InsertAllValidCoins();
    TestVendingMachine_InsertInvalidProduct();
    TestVendingMachine_AddTooManyProducts();
    TestVendingMachine_BuyAndSellFullCapacityOfRacks();
    TestVendingMachine_ErrorMessages();
    TestVendingMachine_CoinBox();
}
