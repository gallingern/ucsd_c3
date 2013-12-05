/*
 * Vending Machine Project
 * CSE-40477
 *
 * VendingMachine.cpp
 * YOU MUST IMPLEMENT THE FUNCTIONS IN THIS FILE.
 */
#include "Coin.h"
#include "DeliveryChute.h"
#include "Product.h"
#include "ProductButton.h"
#include "ProductRack.h"
#include "StatusPanel.h"
#include "VendingMachine.h"

Project1::VendingMachine::VendingMachine(
    ostream &statusPanelStream,
    const char *productNames[NUM_PRODUCT_RACKS],
    unsigned productPrices[NUM_PRODUCT_RACKS])
: statusPanel(statusPanelStream),
  deliveryChute(statusPanel),
  numCoins(0),
  unspentMoneyCents(0)
{
  for (int idx = 0; idx < NUM_PRODUCT_RACKS; idx++) {
    this->productRacks[idx] = new ProductRack(this->statusPanel, productNames[idx], this->deliveryChute, productPrices[idx]);
    this->productButtons[idx] = new ProductButton(*this->productRacks[idx]);
  }
}

Project1::VendingMachine::~VendingMachine()
{
  for (int idx = 0; idx < NUM_PRODUCT_RACKS; idx++) {
    delete this->productButtons[idx];
    delete this->productRacks[idx];
  }
}

bool
Project1::VendingMachine::insertCoin(Coin *pCoin)
{
  bool retval = true;

  if (pCoin->getDenomination() == pCoin->COINTYPE_WOODEN_NICKEL) {
    this->statusPanel.displayMessage(this->statusPanel.MESSAGECODE_BAD_COIN);
    retval = false;
  }
  else {
    this->coinBox[this->numCoins] = pCoin;
    this->unspentMoneyCents += pCoin->getValueCents();
    this->numCoins++;
  }

  return retval;
}

bool
Project1::VendingMachine::pressButton(int button)
{
  bool retval = false;

  if ((this->productButtons[button] == 0) || (button > (NUM_PRODUCT_RACKS - 1)))
    this->statusPanel.displayMessage(this->statusPanel.MESSAGECODE_WRONG_BUTTON);
  else if (this->productButtons[button]->getProductPriceCents() > this->unspentMoneyCents)
    this->statusPanel.displayMessage(this->statusPanel.MESSAGECODE_INSUFFICIENT_MONEY);
  else {
    retval = this->productButtons[button]->press();
    this->unspentMoneyCents -= this->productButtons[button]->getProductPriceCents();
  }

  return retval;
}

Project1::Product *
Project1::VendingMachine::retrieveProduct()
{
  return this->deliveryChute.retrieveProduct();
}

bool
Project1::VendingMachine::addProduct(Product *pProduct)
{
  bool retval = false;
  bool productFound = false;

  for (int idx = 0; idx < NUM_PRODUCT_RACKS; idx++) {
    if (this->productRacks[idx]->isCompatibleProduct(pProduct->getName())) {
      retval = this->productRacks[idx]->addProduct(pProduct);
      productFound = true;
      break;
    }
  }

  if (productFound == false)
    this->statusPanel.displayMessage(this->statusPanel.MESSAGECODE_NO_RACK_FOR_PRODUCT);

  return retval;
}

unsigned
Project1::VendingMachine::getProductCount(const char *productName) const
{
  int retval = 0;

  for (int idx = 0; idx < NUM_PRODUCT_RACKS; idx++) {
    if (this->productRacks[idx]->isCompatibleProduct(productName)) {
      retval = this->productRacks[idx]->getNumProductsInRack();
      break;
    }
  }

  return retval;
}

unsigned
Project1::VendingMachine::countTill() const
{
  unsigned int retval = 0;
  for (unsigned int idx = 0; idx < this->numCoins; idx++) {
    retval += this->coinBox[idx]->getValueCents();
  }

  return retval;
}

unsigned
Project1::VendingMachine::getNumCoinsInCoinBox() const
{
  return this->numCoins;
}
