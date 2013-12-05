/*
* Vending Machine Project
* CSE-40477
*
* StatusPanel.h
* YOU MUST NOT CHANGE THIS FILE.
*/
#ifndef PROJECT1_STATUSPANEL_H
#define PROJECT1_STATUSPANEL_H

#include <ostream>
using std::ostream;

namespace Project1
{
    //=========================================================================
    // SUMMARY
    //      A status panel that will display messages.  A status panel is
    //      associated with an ostream (e.g. cout); the messages displayed by
    //      the status panel are sent to this ostream.
    // 
    // RESOURCES
    //      A status panel does not own any resources.
    //=========================================================================
    class StatusPanel
    {
    public:
        //---------------------------------------------------------------------
        // Codes for messages that can be displayed by a status panel.  Each
        // enumerator's value is an index into an array of associated error
        // messages.
        //---------------------------------------------------------------------
        enum MessageCode
        {
            // There is no product rack for the given product
            MESSAGECODE_NO_RACK_FOR_PRODUCT,

            // The rack to which you are attempting to add a product is full
            MESSAGECODE_RACK_IS_FULL,

            // Attempt to insert product into a rack that expects a different
            // product name
            MESSAGECODE_PRODUCT_DOES_NOT_MATCH_PRODUCT_RACK,

            // The coin you've attempted to insert is not accepted by the
            // vending machine
            MESSAGECODE_BAD_COIN,

            // The product you've attempted to purchase is sold out
            MESSAGECODE_SOLD_OUT,

            // You tried to purchase a product but the delivery chute is full
            MESSAGECODE_CHUTE_FULL,

            // A button corresponding to the name you've provided does not
            // exist
            MESSAGECODE_WRONG_BUTTON,

            // You pressed a button but haven't inserted enough money for the
            // purchase
            MESSAGECODE_INSUFFICIENT_MONEY,

            // End of error code range (not a real message); used to size
            // array messages
            MESSAGECODE_ERRORS_END
        };

        //---------------------------------------------------------------------
        // SUMMARY
        //      Constructor.  Initializes the status panel's stream to the
        //      given ostream.  Messages output by the status panel will be
        //      sent to the ostream.
        //
        // RESOURCES
        //      None
        //
        // PARAMETERS
        //      outputStream
        //          The ostream to which messages will be sent.
        //
        // RETURNS
        //      Nothing
        //---------------------------------------------------------------------
        StatusPanel(ostream &outputStream);

        //---------------------------------------------------------------------
        // SUMMARY
        //      Sends the message string for the given message code to this
        //      status panel's output stream.
        //
        // RESOURCES
        //      None
        //
        // PARAMETERS
        //      messageCode
        //          The message code of the message that should be output to
        //          the status panel's output stream.
        //
        // RETURNS
        //      Nothing
        //---------------------------------------------------------------------
        void displayMessage(MessageCode messageCode);

    private:
        // Messages that can be displayed on the status panel.  This array
        // should be indexed using a MessageCode.
        static const char *messages[MESSAGECODE_ERRORS_END];

        ostream &outputStream;
    };
}

#endif
