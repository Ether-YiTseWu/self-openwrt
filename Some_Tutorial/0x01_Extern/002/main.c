#include "lib.h"
#include <stdio.h>

int main(void)
{
	extern int counter;
	printf("[1] count is %d\n", counter);
	add();
	printf("[2] count is %d\n", counter);

	return 0;
}