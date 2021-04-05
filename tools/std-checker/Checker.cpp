#include <iostream>
#include <cstdio>
#include <string>
#include <windows.h>
using namespace std;

int main()
{
    int type;
    printf("input random generator type:\n");
    printf("1: naive\n");
    printf("2: cmdRandom\n");
    printf("3: WinRandom\n");
    scanf("%d", &type);

    int t = 100000;
    string Std = R"("D:\Users\VonBrank\Documents\GitHub\code-learning\practise\luogu\contest\LGR-084\A.T173579-StickSuger-violent.exe")";
    string Mtd = R"("D:\Users\VonBrank\Documents\GitHub\code-learning\practise\luogu\contest\LGR-084\A.T173579-StickSuger.exe")";
    string DataGenerator;
    if (type == 3)
        DataGenerator = R"("D:\Users\VonBrank\Documents\GitHub\code-learning\tools\std-checker\DataGenerator_WR.exe")";
    else
        DataGenerator = R"("D:\Users\VonBrank\Documents\GitHub\code-learning\tools\std-checker\DataGenerator_cmd.exe")";
    string in_txt = "in.txt";
    string mtd_out_txt = "mtd-out.txt";
    string std_out_txt = "std-out.txt";
    while (t--)
    {
        if (type == 2)
            system((DataGenerator + " %random%" + " > " + in_txt).data());
        else
            system((DataGenerator + " > " + in_txt).data());
        // printf("%s\n", (in_txt + " < " + Mtd + " > " + mtd_out_txt).data());
        system((Mtd + " < " + in_txt + " > " + mtd_out_txt).data());
        system((Std + " < " + in_txt + " > " + std_out_txt).data());
        if (system(("fc " + mtd_out_txt + " " + std_out_txt).data()))
            system("pause");
    }
    return 0;
}