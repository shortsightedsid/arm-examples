/* Derived from the blinky example */

#include <stdint.h>
#include "Morse.hpp"
#include "Led.hpp"

int main(void)
{
	Morse m;

	while(1)
	{
		m.blinkMessage("Hello World");
		m.space();
	}
}
