/* Derived from the blinky example */

#include <stdint.h>
#include "Morse.hpp"
#include "Led.hpp"
#include "inc/hw_types.h"
#include "inc/hw_sysctl.h"
#include "inc/hw_memmap.h"

int main(void)
{
	/* Enable GPIO Bank R and Bank F Clocks */
	/* Do a dummy read to insert a few cycles after enabling the peripheral. */
	volatile uint32_t dummy;
    HWREG(SYSCTL_RCGCGPIO) |= (SYSCTL_RCGCGPIO_R12 | SYSCTL_RCGCGPIO_R5);
    dummy = HWREG(SYSCTL_RCGCGPIO);

	Morse m1(GPIO_PORTN_BASE, 0);
	Morse m2(GPIO_PORTN_BASE, 1);
	Morse m3(GPIO_PORTF_BASE, 0);
	Morse m4(GPIO_PORTF_BASE, 4);

	while(1)
	{
		m1.blinkMessage("SOS");
		m1.space();

		m2.blinkMessage("SOS");
		m2.space();

		m3.blinkMessage("SOS");
		m3.space();

		m4.blinkMessage("SOS");
		m4.space();
	}


	/* Should never reach here */
    /* HWREG(SYSCTL_RCGCGPIO) &= ~(0x000001000u); */
}
