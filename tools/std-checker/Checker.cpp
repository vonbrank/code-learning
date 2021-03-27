#include <iostream>
#include <cstdio>
#include <string>
#include <windows.h>
using namespace std;

int main()
{
    int t = 100000;
    string Std = R"("D:\Users\VonBrank\Documents\GitHub\code-learning\practise\codeforeces\contests\Codeforces-Round-#706-Div.2\D.Lets-Go-Hiking-[std].exe")";
    string Mtd = R"("D:\Users\VonBrank\Documents\GitHub\code-learning\practise\codeforeces\contests\Codeforces-Round-#706-Div.2\D.Lets-Go-Hiking-[After-Contest].exe")";
    string DataGenerator = R"("D:\Users\VonBrank\Documents\GitHub\code-learning\tools\std-checker\DataGenerator.exe")";
    string in_txt = "in.txt";
    string mtd_out_txt = "mtd-out.txt";
    string std_out_txt = "std-out.txt";
    while (t--)
    {
        system((DataGenerator + " > " + in_txt).data());
        // printf("%s\n", (in_txt + " < " + Mtd + " > " + mtd_out_txt).data());
        system((Mtd + " < " + in_txt + " > " + mtd_out_txt).data());
        system((Std + " < " + in_txt + " > " + std_out_txt).data());
        if (system(("fc " + mtd_out_txt + " " + std_out_txt).data()))
            system("pause");
    }
    return 0;
}