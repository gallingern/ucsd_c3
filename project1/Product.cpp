/*
 * Vending Machine Project
 * CSE-40477
 *
 * Product.cpp
 * YOU MUST IMPLEMENT THE FUNCTIONS IN THIS FILE.
 */
#include <cstring>
using std::strcpy;

#include "Product.h"

Project1::Product::Product(const char *brand, const char *name,
    const char *size)
{
  strcpy(this->brand, brand);
  strcpy(this->name, name);
  strcpy(this->size, size);
}

const char *
Project1::Product::getBrand() const
{
  return this->brand;
}

void
Project1::Product::setBrand(const char *value)
{
  strcpy(this->brand, value);
}

const char *
Project1::Product::getName() const
{
  return this->name;
}

void
Project1::Product::setName(const char *value)
{
  strcpy(this->name, value);
}

const char *
Project1::Product::getSize() const
{
  return this->size;
}

void
Project1::Product::setSize(const char *value)
{
  strcpy(this->size, value);
}
