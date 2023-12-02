#ifndef _CRCFast_H_
#define _CRCFast_H_

#include <stdint.h>

typedef uint8_t crc_t;

#define WIDTH  (8 * sizeof(crc_t))
#define TOPBIT (1 << (WIDTH - 1))

namespace ootb
{
    class CRCFast
    {
    private:
        uint8_t polynomial;
        uint8_t initial;
        uint8_t finalXor;
        crc_t crcTable[256];
    public:
        CRCFast(uint8_t polynomial, uint8_t initial, uint8_t finalXor);
        ~CRCFast();

        void init();
        crc_t crc(uint8_t const *data, uint16_t length);
    };

}

#endif