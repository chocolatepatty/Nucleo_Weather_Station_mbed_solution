/* mbed Microcontroller Library
* Copyright (c) 2006-2013 ARM Limited
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#include "hal_types.h"
#include "mbed.h"

// utility functions

#ifndef __UTIL_H__
#define __UTIL_H__

#define NEED_CONSOLE_OUTPUT 1 /* Set this if you need debug messages on the console;
                            * it will have an impact on code-size and power consumption. */

#if NEED_CONSOLE_OUTPUT
//Serial usb(USBTX, USBRX); // tx, rx
extern Serial  pc;
#define DEBUG(...) { pc.printf(__VA_ARGS__); }
#else
#define DEBUG(...) /* nothing */
#endif /* #if NEED_CONSOLE_OUTPUT */

#define STORE_LE_16(buf, val)    ( ((buf)[0] =  (tHalUint8) (val)    ) , \
    ((buf)[1] =  (tHalUint8) (val>>8) ) )

#define STORE_LE_32(buf, val)    ( ((buf)[0] =  (tHalUint8) (val)     ) , \
    ((buf)[1] =  (tHalUint8) (val>>8)  ) , \
    ((buf)[2] =  (tHalUint8) (val>>16) ) , \
    ((buf)[3] =  (tHalUint8) (val>>24) ) ) 

#define COPY_UUID_128(uuid_struct, uuid_15, uuid_14, uuid_13, uuid_12, uuid_11, uuid_10, uuid_9, uuid_8, uuid_7, uuid_6, uuid_5, uuid_4, uuid_3, uuid_2, uuid_1, uuid_0) \
    do {\
        uuid_struct[0] = uuid_0; uuid_struct[1] = uuid_1; uuid_struct[2] = uuid_2; uuid_struct[3] = uuid_3; \
        uuid_struct[4] = uuid_4; uuid_struct[5] = uuid_5; uuid_struct[6] = uuid_6; uuid_struct[7] = uuid_7; \
        uuid_struct[8] = uuid_8; uuid_struct[9] = uuid_9; uuid_struct[10] = uuid_10; uuid_struct[11] = uuid_11; \
        uuid_struct[12] = uuid_12; uuid_struct[13] = uuid_13; uuid_struct[14] = uuid_14; uuid_struct[15] = uuid_15; \
    }while(0)


double getHighPowerAndPALevelValue(int8_t dBMLevel, int8_t& EN_HIGH_POWER, int8_t& PA_LEVEL);

#endif // __UTIL_H__
