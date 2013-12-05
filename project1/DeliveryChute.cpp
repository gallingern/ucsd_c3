/*
 * Vending Machine Project
 * CSE-40477
 *
 * DeliveryChute.cpp
 * YOU MUST IMPLEMENT THE FUNCTIONS IN THIS FILE.
 */
#include "DeliveryChute.h"

Project1::DeliveryChute::DeliveryChute(StatusPanel &statusPanel)
: statusPanel(statusPanel),
  pProduct(0)
{
  // Empty Constructor
}

Project1::DeliveryChute::~DeliveryChute()
{
}

bool
Project1::DeliveryChute::insertProduct(Product *pProduct)
{
  bool retval = false;

  if (this->containsProduct()) {
    this->statusPanel.displayMessage(statusPanel.MESSAGECODE_CHUTE_FULL);
  }
  else {
    this->pProduct = pProduct;
    retval = true;
  }

  return retval;
}

Project1::Product *
Project1::DeliveryChute::retrieveProduct()
{
  Product *retval = NULL;

  if (this->containsProduct()) {
    retval = new Product(this->pProduct->getBrand(),
                         this->pProduct->getName(),
                         this->pProduct->getSize());
    this->pProduct = NULL;
  }

  return retval;
}

bool
Project1::DeliveryChute::containsProduct() const
{
  bool retval = false;

  if (this->pProduct != NULL)
    retval = true;

  return retval;
}
