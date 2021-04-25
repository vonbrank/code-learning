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
    signal(SIGINT, signalHandle);
    while (true)
    {
        printf("Going to sleep....\n");
        sleep(1);
    }

    return 0;
}