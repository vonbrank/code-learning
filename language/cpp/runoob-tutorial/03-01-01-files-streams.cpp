#include <iostream>
#include <fstream>
#include <cstdio>

using namespace std;

int main()
{
    char data[100];

    // ofstream outfile;
    // outfile.open("test.dat");

    // scanf("%s", data);

    // outfile << data;

    // outfile.close();

    ifstream infile;
    infile.open("test.dat");
    infile >> data;

    printf("%s", data);

    return 0;
}