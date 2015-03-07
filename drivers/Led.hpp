#ifndef __LED_HPP
#define __LED_HPP

#include <stdint.h>

class Led
{
	public:
	Led(uint32_t baseAddress, uint8_t pin);
	~Led();
	void on(uint32_t time);
	void off(uint32_t time);
	private:
	uint32_t baseAddress;
	uint8_t pin;
};

#endif
