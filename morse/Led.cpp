#include "Led.hpp"
#include "inc/tm4c1294ncpdt.h"
#include <stdint.h>

//
// Enable the GPIO port that is used for the on-board LED.
// Do a dummy read to insert a few cycles after enabling the peripheral.
// Enable the GPIO pin for the LED (PN0).  
// Set the direction as output, and
// enable the GPIO pin for digital function.
//
Led::Led()
{
    volatile uint32_t dummy;

    SYSCTL_RCGCGPIO_R = SYSCTL_RCGCGPIO_R12;

    dummy = SYSCTL_RCGCGPIO_R;

    GPIO_PORTN_DIR_R = 0x01;
    GPIO_PORTN_DEN_R = 0x01;
}

Led::~Led()
{
}

//
// Turn on the LED.
// Delay for a bit.
//
void Led::on(uint32_t time)
{
        GPIO_PORTN_DATA_R |= 0x01;

        for(volatile uint32_t i(0); i < time; i++) {}
}

//
// Turn off the LED.
// Delay for a bit.
//
void Led::off(uint32_t time)
{
        GPIO_PORTN_DATA_R &= ~(0x01);

        for(volatile uint32_t i(0); i < time; i++) {}
}

