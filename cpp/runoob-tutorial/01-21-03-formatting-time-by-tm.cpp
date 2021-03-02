#include <iostream>
#include <cstdio>
#include <ctime>
using namespace std;

int main()
{
    // 基于当前系统的当前日期/时间
    time_t now = time(0);
    printf("The time elapsed from 1970 to the present: %d", now);
    tm *ltm = localtime(&now);

    // 基于当前系统的当前日期/时间
    printf("Year: %d\n", 1900 + ltm->tm_year);
    printf("Month: %d\n", 1 + ltm->tm_mon);
    printf("Day: %d\n", ltm->tm_mday);
    printf("Time: %d:%d:%d\n", ltm->tm_hour, ltm->tm_min, ltm->tm_sec);

    return 0;
}