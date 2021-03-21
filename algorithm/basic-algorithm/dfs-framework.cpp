#include <cstdio>
using namespace std;
const int maxn = 100;
int n;

bool CheckEdge(...) // 边界条件和约束条件的判断
{
    if (...) // 满足条件
        return 1;
    else // 与约束条件冲突
        return 0;
}

void dfs(int depth)
{
    if (depth > n) // 出现目标态G
    {
        ...... // 做相应处理
        return;
    }
    for (int i = 1; i < n; i++) // 按照规则生成下一个节点
    {
        if (!CheckEdge(...)) continue; //如果不满足条件则跳过
        vst[] = 1;      // 标记该节点被访问过
        dfs(depth + 1);
        vst[] = 0;      // 回溯
    }
}
int main()
{
    ...... 
    return 0;
}