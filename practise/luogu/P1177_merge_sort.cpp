#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 100500;
int n;
int a[maxn];
void merge_sort(int a_[], int l, int r)
{
    int mid = (l + r) >> 1; //取区间中点，左右子区间分别排序
    int len = r - l + 1;
    if (l < mid)
        merge_sort(a_, l, mid);
    if (r > mid + 1)
        merge_sort(a_, mid + 1, r);
    int tmp[len];
    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r) //将两个有序数组合并，保存在临时数组tmp中
        tmp[k++] = a_[i] < a_[j] ? a_[i++] : a_[j++];
    while (i <= mid)
        tmp[k++] = a_[i++];
    while (j <= r)
        tmp[k++] = a_[j++];
    for (i = 0; i < len; i++) //将tmp数组中的临时有序序列传回a_数组
    {
        a_[l + i] = tmp[i];
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    merge_sort(a, 1, n);
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}