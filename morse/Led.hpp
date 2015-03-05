#ifndef __LED_HPP
#define __LED_HPP

#include <stdint.h>

class Led
{
	public:
	Led();
	~Led();
	void on(uint32_t time);
	void off(uint32_t time);
};

#endif
