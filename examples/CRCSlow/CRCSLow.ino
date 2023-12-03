#include "CRCSlow.h"

using namespace ootb;

CRCSlow crcMethod(0x31, 0xFF, 0x00);

void setup() 
{
  Serial.begin(MONITOR_SPEED);
  Serial.println();
}

void loop()
{
    uint8_t data[2] = {0xBE, 0xEF};
    int crc = crcMethod.crc(data, 2);
    Serial.print("Calculated:0x");
    Serial.print(crc, HEX);
    Serial.println();
    Serial.print("Expected  :0x");
    Serial.print(0x92, HEX);
    Serial.println();
}
