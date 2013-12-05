/*
* Vending Machine Project
* CSE-40477
*
* StatusPanel.cpp
* YOU MUST NOT CHANGE THIS FILE.
*/
#include "StatusPanel.h"

const char *Project1::StatusPanel::messages[MESSAGECODE_ERRORS_END] =
{
    "No rack designated for the named product\n",
    "The rack for the named product is full\n",
    "Product name does not match product rack allowed name\n",
    "Bad coin inserted\n",
    "Product sold out\n",
    "Cannot purchase product; a product is already in delivery chute\n",
    "You're pressing a nasty old chewing gum wad, not a button!\n",
    "Insufficient money to make purchase, insert more money then try again\n"
};

Project1::StatusPanel::StatusPanel(ostream &outputStream)
    : outputStream(outputStream)
{
}

void
Project1::StatusPanel::displayMessage(MessageCode messageCode)
{
    outputStream << StatusPanel::messages[messageCode];
}
