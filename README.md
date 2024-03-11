# PCF8574IO library for MbedCE

Library for interfacing 8bit (8 pins) [PCF8574](https://www.ti.com/product/PCF8574) GPIO expender under MbedCE.

## How to start
1. Create a new project according to [MbedCE instructions](https://github.com/mbed-ce/mbed-os/wiki)
2. Add this as submodule to your project via `git submodule add --depth 1 https://github.com/mbed-ce-libraries-examples/PCF8574IO PCF8574IO`
3. The top level `CMakeList.txt` (in root of your project) should be modified according to [this wiki page](https://github.com/mbed-ce/mbed-os/wiki/MbedOS-configuration#libraries-in-your-application)
4. Create your main.cpp file and copy & Paste example code below.
5. Build the project

## Example code
```
#include "mbed.h"
#include "PCF8574IO.h"

I2C i2c(I2C_SDA,I2C_SCL);
PCF8574IO io(&i2c, 0x40);
 
int main() {
    printf("MbedCE_lib_example_PCF8574IO\r\n");
    while(1) {
        io.write(0xF); // all 8 GPIO set to 1
        thread_sleep_for(300);
        io.write(0x0); // all 8 GPIO set to 0
        thread_sleep_for(300);
    }
}
```
## Description
This library is very simple, just write number 0-255 to change state of 8 GPIO pins.
 - 0xf = 1111 1111
 - 0x0 = 0000 0000
 - 0x1 = 0000 0001 
 - and so on...

### Status:
Library was not tested on real hardware but it was working with regular Mbed in the past. 
