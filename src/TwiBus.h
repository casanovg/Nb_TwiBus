/*
 *  TWI Bus Master Library
 *  Author: Gustavo Casanova
 *  ...........................................
 *  File: TwiBus.h (Header)
 *  ........................................... 
 *  Version: 1.0.1 / 2020-05-07
 *  gustavo.casanova@gmail.com
 *  ...........................................
 *  This library allows scanning the TWI (I2C) bus in search
 *  of connected devices addresses and data. If a device found
 *  is running Timonel, it returns its version number.
 */

#ifndef _TWIBUS_H_
#define _TWIBUS_H_

#include <Arduino.h>
#include <TimonelTwiM.h>

#include "libconfig.h"

// Class TwiBus: Represents a Two Wire Interfase (I2C) bus
class TwiBus {
   public:
    typedef struct device_info_ {
        byte addr = 0;
        String firmware = "";
        byte version_major = 0;
        byte version_minor = 0;
    } DeviceInfo;
    TwiBus(byte sda = 0, byte scl = 0);
    ~TwiBus();
    byte ScanBus(bool *p_app_mode = nullptr);
    byte ScanBus(DeviceInfo dev_info_arr[],
                 byte arr_size = HIG_TWI_ADDR + 1,
                 byte start_twi_addr = LOW_TWI_ADDR);

   private:
    byte sda_ = 0, scl_ = 0;
    bool reusing_twi_connection_ = true;
};

#endif /* _TWIBUS_H_ */
