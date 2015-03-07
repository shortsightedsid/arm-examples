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
Led::Led(uint32_t baseAddress, uint8_t pin)
{
	pin++; // Store Pins 0 to 7 as 1 to 8.

    HWREG((baseAddress + GPIO_O_DIR)) |= pin;
    HWREG((baseAddress + GPIO_O_DEN)) |= pin;

    this->baseAddress = baseAddress;
    this->pin = pin;
}

Led::~Led()
{
    HWREG((baseAddress + GPIO_O_DEN)) &= ~pin;
    HWREG((baseAddress + GPIO_O_DIR)) &= ~pin;
}

//
// Turn on the LED.
// Delay for a bit.
//
void Led::on(uint32_t time)
{
        HWREG((baseAddress + GPIO_O_DATA + (pin << 0x2))) |= (0xFFu);

        for(volatile uint32_t i(0); i < time; i++) {}
}

//
// Turn off the LED.
// Delay for a bit.
//
void Led::off(uint32_t time)
{
        HWREG((baseAddress + GPIO_O_DATA + (pin << 0x2))) &= ~(0xFFu);

        for(volatile uint32_t i(0); i < time; i++) {}
}

