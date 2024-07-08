#include <stdio.h>

void test()
{
	char *buffer = "test";
	
	printf("IN FUNCTION : START\n");
	buffer[0] = 'A';
	printf("IN FUNCTION : FINISH\n");
}

int main(void)
{
	char *buffer = "MAIN";
	
	printf("START\n");
	buffer[0] = 'A';
	printf("FINISH\n");

	return 0;
}
