/**
 * @file mcp23008.h
 * 
 * This library was built based on the Datasheet "MCP23008/MCP23S08 8-Bit I/O Expander with Serial Interface" from Microchip
 * 
 * @author Ricardo LIma Caratti (pu2clr@gmail.com)
 * @brief It is a Library to control the MCP23008 device.
 * @version 1.0.0
 * @date 2020-08-07
 * 
 * This library can be freely distributed using the MIT Free Software model.
 * 
 * @copyright Copyright (c) 2020 Ricardo Lima Caratti
 */

#include <Arduino.h>

// registers
#define REG_IODIR 0x00   //!< Controls the direction of the data I/O. When  a  bit  is  set,  the  corresponding  pin  becomes  an input.  When  a  bit  is  clear,  the  corresponding  pin becomes an output.
#define REG_IPOL 0x01    //!< The IPOL  register  allows  the  user  to  configure  thepolarity on the corresponding GPIO port bits.
#define REG_GPINTEN 0x02 //!< The GPINTEN register controls the interrupt-on-change feature for each pin.
#define REG_DEFVAL 0x03  //!< The default  comparison  value  is  configured  in  the DEFVAL register.
#define REG_INTCON 0x04  //!< The INTCON register controls how the associated pin value is compared for the interrupt-on-change feature
#define REG_IOCON 0x05   //!< The IOCON register contains several bits for configuring the device
#define REG_GPPU 0x06    //!< The GPPU register controls the pull-up resistors for the port  pins.
#define REG_INTF 0x07    //!< The INTF register reflects the interrupt condition on the port pins of any pin that is enabled for interrupts via the GPINTEN register.
#define REG_INTCAP 0x08  //!< The INTCAP register captures the GPIO port value at the  time  the  interrupt  occurred.
#define REG_GPIO 0x09    //!< The GPIO  register  reflects  the  value  on  the  port.
#define REG_OLAT 0x0A    //!< The OLAT  register  provides  access  to  the  output latches.

#define GPIO_INPUT  0xFF
#define GPIO_OUTPUT 0x00


class MCP {

   protected:

    uint8_t i2cAddress = 0x20; // Default i2c address
    uint8_t gpios = 0; // REG_GPIO shadow register

 public:
    void setup(uint8_t i2c = 0x20, uint8_t io = GPIO_OUTPUT);
    void setGPIOS(uint8_t value);
    uint8_t getRegister(uint8_t reg);
    void setRegister(uint8_t reg, uint8_t value);
    void turnGpioOn(uint8_t gpio);
    void turnGpioOff(uint8_t gpio);
    void pullUpGpioOn(uint8_t gpio);
    void pullUpGpioOff(uint8_t gpio);

    /**
     * @brief Return the current MCP GPIO pin levels 
     * 
     * @return uint8_t 
     */
    inline uint8_t getGPIOS() { return this->gpios; };

};
