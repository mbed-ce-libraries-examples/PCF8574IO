/* mbed PCF8574 Library, for driving the I2C I/O Expander
 * Copyright (c) 2008-2010, cstyles, sford
 *               2022, 001: JohnnyK, Reworked Constructor to I2C object instead of I2C pins. I can be usefull with anoter I2C slave on same bus
 *               2022, 002: JohnnyK, Changed class name for compatibility with TextLCD library
 *               2024, 003: JohnnyK, Release for MbedCE
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include "mbed.h"

#ifndef MBED_PCF8574IO_H
#define MBED_PCF8574IO_H

/** Interface to the popular PCF8574 I2C 8 Bit IO expander */
class PCF8574IO {
    public:
        /** Create an instance of the PCF8574 connected I2C object, with the specified address.
         *
         * @param Mbed I2C object
         * @param address The I2C address for this PCF8574
         */
        PCF8574IO(I2C *i2c, int address = 0x40);
            
        /** Read the IO pin level
         *
         * @return The byte read
         */
        int read();
                
        /** Write to the IO pins
         * 
         * @param data The 8 bits to write to the IO port
         */
        void write(int data);
        
    private:
        I2C *_i2c;
        int _address;
};

#endif
