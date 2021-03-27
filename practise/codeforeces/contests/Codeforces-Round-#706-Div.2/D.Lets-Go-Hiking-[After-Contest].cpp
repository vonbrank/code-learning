#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 100500;
int n, ls, qingshan_spawn, direction, daniel_spawn;
int a[maxn], left_path_length[maxn], right_path_length[maxn];
int dfs(int loc, int pace)
{
    int *p = pace == -1 ? &left_path_length[loc] : &right_path_length[loc];
    if (loc + pace == 0 || loc + pace == n + 1)
        return *p = 0;
    if (a[loc] < a[loc + pace])
        return *p = 0;
    return *p = dfs(loc + pace, pace) + 1;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        if (i == 1 && a[i] > a[i + 1])
            dfs(i, 1);
        else if (i == n && a[i - 1] < a[i])
            dfs(i, -1);
        else if (a[i] > a[i - 1] && a[i] > a[i + 1])
        {
            dfs(i, -1);
            dfs(i, 1);
        }
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     printf("%d ", left_path_length[i]);
    // }
    // puts("");
    // for (int i = 1; i <= n; i++)
    // {
    //     printf("%d ", right_path_length[i]);
    // }
    // puts("");

    bool flag = true;
    for (int i = 1; i <= n; i++)
    {
        if (left_path_length[i] == 0 || right_path_length[i] == 0)
            continue;
        if (left_path_length[i] > ls)
        {
            ls = left_path_length[i];
            qingshan_spawn = i;
            direction = -1;
        }
        if (right_path_length[i] > ls)
        {
            ls = right_path_length[i];
            qingshan_spawn = i;
            direction = 1;
        }
        flag = false;
    }
    if (flag)
    {
        printf("0");
        return 0;
    }

    if (direction == -1)
    {
        for (int i = 1; i <= n; i++)
        {
            if (i == qingshan_spawn)
                continue;
            if (left_path_length[i] == left_path_length[qingshan_spawn] || right_path_length[i] == left_path_length[qingshan_spawn])
            {
                printf("0");
                return 0;
            }
        }

        daniel_spawn = left_path_length[qingshan_spawn] % 2 == 0 ? qingshan_spawn - left_path_length[qingshan_spawn] + 1 : qingshan_spawn - left_path_length[qingshan_spawn];
        direction = 1;
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (i == qingshan_spawn)
                continue;
            if (left_path_length[i] == right_path_length[qingshan_spawn] || right_path_length[i] == right_path_length[qingshan_spawn])
            {
                printf("0");
                return 0;
            }
        }

        daniel_spawn = right_path_length[qingshan_spawn] % 2 == 0 ? qingshan_spawn + right_path_length[qingshan_spawn] - 1 : qingshan_spawn + right_path_length[qingshan_spawn];
        direction = -1;
    }

    // printf("%d %d\n", qingshan_spawn, daniel_spawn);

    if (direction == -1)
    {
        printf("%d", left_path_length[qingshan_spawn] > daniel_spawn - qingshan_spawn);
    }
    else
    {
        printf("%d", right_path_length[qingshan_spawn] > qingshan_spawn - daniel_spawn);
    }

    return 0;
}