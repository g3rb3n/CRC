#ifndef _CRCSlow_H_
#define _CRCSlow_H_

#include <stdint.h>

typedef uint8_t crc_t;

#define WIDTH  (8 * sizeof(crc_t))
#define TOPBIT (1 << (WIDTH - 1))

namespace ootb
{
    class CRCSlow
    {
    private:
        uint8_t polynomial;
        uint8_t initial;
        uint8_t finalXor;

    public:
        CRCSlow(uint8_t polynomial, uint8_t initial = 0, uint8_t finalXor = 0);
        ~CRCSlow();

        crc_t crc(uint8_t const *data, uint16_t length);
    };

}

#endif