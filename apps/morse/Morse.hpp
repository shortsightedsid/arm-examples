#ifndef __MORSE_HPP
#define __MORSE_HPP

#include <stdint.h>
#include "Led.hpp"

const uint32_t MORSE_UNIT = 100000;

class Morse
{
	public:
	Morse(uint32_t ledBaseAddress, uint8_t ledPin);
	~Morse();
	void blinkMessage(const char *message);
	void space();

	protected:
	void next();
	void dot();
	void dash();

	private:
	Led l;
};

#endif
