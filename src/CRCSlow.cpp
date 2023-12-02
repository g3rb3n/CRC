#include "CRCSlow.h"

using namespace ootb;

CRCSlow::CRCSlow(uint8_t polynomial, uint8_t initial, uint8_t finalXor)
:
    polynomial(polynomial),
    initial(initial),
    finalXor(finalXor)
{
}

CRCSlow::~CRCSlow()
{
}

crc_t CRCSlow::crc(uint8_t const *message, uint16_t length)
{
    crc_t remainder = initial;	
 
    /*
     * Perform modulo-2 division, a byte at a time.
     */
    for (int byte = 0; byte < length; ++byte)
    {
        /*
         * Bring the next byte into the remainder.
         */
        remainder ^= (message[byte] << (WIDTH - 8));

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
    }

    /*
     * The final remainder is the CRC result.
     */
    return remainder ^ finalXor;
}