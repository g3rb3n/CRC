#include "../src/CRCSlow.h"
#include <iostream>

using namespace ootb;

int main()
{
    CRCSlow crcMethod(0x31, 0xFF, 0x00);
    uint8_t data[2] = {0xBE, 0xEF};
    int crc = crcMethod.crc(data, 2);
    //int crc1 = 0xBE;
    std::cout << "result: " << std::hex << crc << std::endl;
    return 0;
}