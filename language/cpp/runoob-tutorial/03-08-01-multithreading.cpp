//https://zhuanlan.zhihu.com/p/194198073
#include <iostream>
#include <cstdio>
#include <thread>
#include <windows.h>
using namespace std;

void proc(int &a)
{
    printf("This is the thread_2 and the parameter is: %d\n", a);
    printf("(Thread_2)The id of the thread_2 is: %d\n", this_thread::get_id());
}

int main()
{
    printf("This is the main thread.\n");
    int a = 123;
    thread th2(proc, ref(a));
    Sleep(5000);
    printf("(Main thread)The id of the thread_2 is: %d\n", th2.get_id());
    th2.join();
    return 0;
}