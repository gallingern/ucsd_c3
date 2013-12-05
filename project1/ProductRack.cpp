/*
 * Vending Machine Project
 * CSE-40477
 *
 * ProductRack.cpp
 * YOU MUST IMPLEMENT THE FUNCTIONS IN THIS FILE.
 */
#include <cstring>
using std::strcmp;

#include "ProductRack.h"

Project1::ProductRack::ProductRack(
    StatusPanel &statusPanel,
    const char *allowedProductName,
    DeliveryChute &deliveryChute,
    unsigned productPriceCents)
: statusPanel(statusPanel),
  deliveryChute(deliveryChute),
  productCount(0),
  productPriceCents(productPriceCents)
{
  strncpy(this->allowedProductName, allowedProductName, Product::MAX_NAME_LENGTH);
}

Project1::ProductRack::~ProductRack()
{
  // Empty Destructor
}

bool
Project1::ProductRack::isCompatibleProduct(const char *productName) const
{
  bool retval = false;

  if (!strcmp(productName, this->allowedProductName))
    retval = true;

  return retval;
}

bool
Project1::ProductRack::isFull() const
{
  bool retval = true;

  if (this->productCount < (unsigned)MAX_PRODUCTS)
    retval = false;

  return retval;
}

bool
Project1::ProductRack::isEmpty() const
{
  bool retval = false;

  if (this->productCount == 0)
    retval = true;

  return retval;
}

bool
Project1::ProductRack::addProduct(Product* pProduct)
{
  bool retval = true;

  if (this->isFull()) {
    retval = false;
    this->statusPanel.displayMessage(this->statusPanel.MESSAGECODE_RACK_IS_FULL);
  }
  else if (!isCompatibleProduct(pProduct->getName())) {
    retval = false;
    this->statusPanel.displayMessage(this->statusPanel.MESSAGECODE_PRODUCT_DOES_NOT_MATCH_PRODUCT_RACK);
  }

  if (retval == true) {
    this->products[this->productCount] = pProduct;
    this->productCount++;
  }

  return retval;
}

bool
Project1::ProductRack::deliverProduct()
{
  bool retval = true;

  if (this->isEmpty()) {
    retval = false;
    this->statusPanel.displayMessage(this->statusPanel.MESSAGECODE_SOLD_OUT);
  }

  if (retval == true) {
    retval = this->deliveryChute.insertProduct(this->products[this->productCount - 1]);
    if (retval == true) {
      delete this->products[this->productCount - 1];
      this->productCount--;
    }
  }

  return retval;
}

unsigned
Project1::ProductRack::getNumProductsInRack() const
{
  return this->productCount;
}

unsigned
Project1::ProductRack::getProductPriceCents() const
{
  return this->productPriceCents;
}
