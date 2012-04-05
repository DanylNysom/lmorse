#include "led_morse.h"

#define TRUE 1
#define FALSE 0

int main(int argc, char *argv[])
{
	parse_options(argc, argv);
	close_driver();

	return 0;
}

