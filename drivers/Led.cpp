#include <stdint.h>
#include "inc/hw_types.h"
#include "inc/hw_gpio.h"

#include "Led.hpp"

//
// Enable the GPIO port that is used for the on-board LED.
// Enable the GPIO pin for the LED (PN0).  
// Set the direction as output, and
// enable the GPIO pin for digital function.
//
Led::Led(uint32_t baseAddress)
{
    HWREG((baseAddress + GPIO_O_DIR)) |= (0x01u);
    HWREG((baseAddress + GPIO_O_DEN)) |= (0x01u);

    this->baseAddress = baseAddress;
}

Led::~Led()
{
    HWREG((baseAddress + GPIO_O_DEN)) &= ~(0x01u);
    HWREG((baseAddress + GPIO_O_DIR)) &= ~(0x01u);
}

//
// Turn on the LED.
// Delay for a bit.
//
void Led::on(uint32_t time)
{
        HWREG((baseAddress + GPIO_O_DATA + 0x4u)) |= (0x01u);

        for(volatile uint32_t i(0); i < time; i++) {}
}

//
// Turn off the LED.
// Delay for a bit.
//
void Led::off(uint32_t time)
{
        HWREG((baseAddress + GPIO_O_DATA + 0x4u)) &= ~(0x01u);

        for(volatile uint32_t i(0); i < time; i++) {}
}

