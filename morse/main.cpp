/* Derived from the blinky example */

#include <stdint.h>
#include "Morse.hpp"
#include "Led.hpp"
#include "inc/hw_types.h"
#include "inc/hw_sysctl.h"
#include "inc/hw_memmap.h"

int main(void)
{
	/* Enable GPIO Bank R Clock */
	/* Do a dummy read to insert a few cycles after enabling the peripheral. */
	volatile uint32_t dummy;
    HWREG(SYSCTL_RCGCGPIO) |= SYSCTL_RCGCGPIO_R12;
    dummy = HWREG(SYSCTL_RCGCGPIO);

	Morse m(GPIO_PORTN_BASE);

	while(1)
	{
		m.blinkMessage("SOS");
		m.space();
	}


	/* Should never reach here */
    /* HWREG(SYSCTL_RCGCGPIO) &= ~(0x000001000u); */
}
