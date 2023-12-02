#include "CRCFast.h"

using namespace ootb;

CRCFast::CRCFast(uint8_t polynomial, uint8_t initial, uint8_t finalXor)
:
    polynomial(polynomial),
    initial(initial),
    finalXor(finalXor)
{
}

CRCFast::~CRCFast()
{
}

void CRCFast::init()
{
    crc_t  remainder;

    /*
     * Compute the remainder of each possible dividend.
     */
    for (int dividend = 0; dividend < 256; ++dividend)
    {
        /*
         * Start with the dividend followed by zeros.
         */
        remainder = dividend << (WIDTH - 8);

        /*
         * Perform modulo-2 division, a bit at a time.
         */
        for (uint8_t bit = 8; bit > 0; --bit)
        {
            /*
             * Try to divide the current data bit.
             */			
            if (remainder & TOPBIT)
            {
                remainder = (remainder << 1) ^ polynomial;
            }
            else
            {
                remainder = (remainder << 1);
            }
        }

        /*
         * Store the result into the table.
         */
        crcTable[dividend] = remainder;
    } 
}

crc_t CRCFast::crc(uint8_t const *message, uint16_t length)
{
    uint8_t data;
    crc_t remainder = initial;

    /*
     * Divide the message by the polynomial, a byte at a time.
     */
    for (int byte = 0; byte < length; ++byte)
    {
        data = message[byte] ^ (remainder >> (WIDTH - 8));
        remainder = crcTable[data] ^ (remainder << 8);
    }

    /*
     * The final remainder is the CRC.
     */
    return remainder ^ finalXor;

}