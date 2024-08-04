#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char input[64] = {0}, stdinBuf[1024] = {0};
    while(1)
    {
        fgets(stdinBuf, 1024, stdin);
        //scanf("%60s", input);

        sleep(2);
        printf("[%lld] %s\n", time(NULL), stdinBuf);
    }

    return 0;
}
