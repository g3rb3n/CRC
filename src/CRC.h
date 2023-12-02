#ifndef _CRC_H_
#define _CRC_H_

namespace ootb
{
  class CRC
  {
    public:
      virtual uint8_t crc(uint8_t const *data, uint8_t length);
  };

}

#endif