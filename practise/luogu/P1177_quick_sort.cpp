#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 100500;
int n;
int a[maxn];
void quick_sort(int a_[], int l, int r)
{
    int mid = a_[(l + r) >> 1]; //取区间中点的数，也可以随机化取数
    int i = l;
    int j = r;
    do
    {
        while (a_[i] < mid) //如果合法，就继续遍历
            i++;
        while (a_[j] > mid)
            j--;
        if (i <= j) //找到一对不合法的数，将其交换
        {
            swap(a_[i], a_[j]);
            i++;
            j--;
        }
    } while (i <= j); //最终的效果是[l, j]内的数都≤mid，[i, r]内的数都≥mid，与初始mid的位置无关
    if (l < j)        //如果[l, j]是一个合法区间，则继续排序
        quick_sort(a_, l, j);
    if (r > i) //如果[i, r]是一个合法区间，则继续排序
        quick_sort(a_, i, r);
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    quick_sort(a, 1, n);
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}
