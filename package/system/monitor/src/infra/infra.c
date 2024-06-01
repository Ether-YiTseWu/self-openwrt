#include <stdio.h>

int main(int argc, const char **argv)
{
    printf("INFRA INIT\n");

    system("/app/monitor &");
    system("/app/upgrade &");
    
    return 0;
}
