#include "Morse.hpp"

Morse::Morse(uint32_t ledBaseAddress, uint8_t ledPin)
	: l(ledBaseAddress, ledPin)
{
}

Morse::~Morse()
{
}

void Morse::blinkMessage(const char* message)
{
	uint32_t i = 0;
	char c;

	while(c = message[i++]) {
		switch(c) {
			case 'A': case 'a':
			dot(); dash(); break;
			case 'B': case 'b':
			dash(); dot(); dot(); dot(); break;
			case 'C': case 'c':
			dash(); dot(); dash(); dot(); break;
			case 'D': case 'd':
			dash(); dot(); dot(); break;
			case 'E': case 'e':
			dot(); break;
			case 'F': case 'f':
			dot(); dot(); dash(); dot(); break;
			case 'G': case 'g':
			dash(); dash(); dot(); break;
			case 'H': case 'h':
			dot(); dot(); dot(); dot(); break;
			case 'I': case 'i':
			dot(); dot(); break;
			case 'J': case 'j':
			dot(); dash(); dash(); dash(); break;
			case 'K': case 'k':
			dash(); dot(); dash(); break;
			case 'L': case 'l':
			dot(); dash(); dot(); dot(); break;
			case 'M': case 'm':
			dash(); dash(); break;
			case 'N': case 'n':
			dash(); dot(); break;
			case 'O': case 'o':
			dash(); dash(); dash(); break;
			case 'P': case 'p':
			dot(); dash(); dash(); dot(); break;
			case 'Q': case 'q':
			dash(); dash(); dot(); dash(); break;
			case 'R': case 'r':
			dot(); dash(); dot(); break;
			case 'S': case 's':
			dot(); dot(); dot(); break;
			case 'T': case 't':
			dash(); break;
			case 'U': case 'u':
			dot(); dot(); dash(); break;
			case 'V': case 'v':
			dot(); dot(); dot(); dash(); break;
			case 'W': case 'w':
			dot(); dash(); dash(); break;
			case 'X': case 'x':
			dash(); dot(); dot(); dash(); break;
			case 'Y': case 'y':
			dash(); dot(); dash(); dash(); break;
			case 'Z': case 'z':
			dash(); dash(); dot(); dot(); break;
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case '0':
			case ' ':
			space(); break;
			default:
			break;
		}
		next();
	}
}

void Morse::next()
{
	l.off(MORSE_UNIT * 3);
}

void Morse::space()
{
	l.off(MORSE_UNIT * 7);
}

void Morse::dot()
{
	l.on(MORSE_UNIT);
	l.off(MORSE_UNIT);
}

void Morse::dash()
{
	l.on(MORSE_UNIT * 3);
	l.off(MORSE_UNIT);
}
