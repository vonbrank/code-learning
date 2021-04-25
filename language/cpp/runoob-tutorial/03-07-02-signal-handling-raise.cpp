#include <iostream>
#include <cstdio>
#include <csignal>
#include <windows.h>
using namespace std;
void signalHandle(int signum)
{
    printf("Interrupt signal (%d) received.\n", signum);
    exit(signum);
}
int main()
{
    int i = 0;
    signal(SIGINT, signalHandle);
    while (++i)
    {
        printf("Going to sleep....\n");
        sleep(1);
        if (i == 3)
        {
            raise(SIGINT);
        }
    }

    return 0;
}