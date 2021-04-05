#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 100500;
int n, m;
long long a[maxn], tree[maxn << 2], lazy[maxn << 2];

void pushup(int rt)
{
    tree[rt] = tree[rt << 1] + tree[rt << 1 | 1];
}

void pushdown(int rt, int ln, int rn)
{
    if (lazy[rt])
    {
        lazy[rt << 1] += lazy[rt];
        lazy[rt << 1 | 1] += lazy[rt];
        tree[rt << 1] += ln * lazy[rt];
        tree[rt << 1 | 1] += rn * lazy[rt];
        lazy[rt] = 0;
    }
}

void build(int l, int r, int rt)
{
    if (l == r)
    {
        tree[rt] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, rt << 1);
    build(mid + 1, r, rt << 1 | 1);
    pushup(rt);
}
void add(int L, int R, int l, int r, int rt, int k)
{
    if (L <= l && R >= r)
    {
        tree[rt] += (r - l + 1) * k;
        lazy[rt] += k;
        return;
    }
    int mid = (l + r) >> 1;
    pushdown(rt, mid - l + 1, r - mid);
    if (L <= mid)
        add(L, R, l, mid, rt << 1, k);
    if (R > mid)
        add(L, R, mid + 1, r, rt << 1 | 1, k);
    pushup(rt);
}
long long query(int L, int R, int l, int r, int rt)
{
    if (L <= l && R >= r)
    {
        return tree[rt];
    }
    int mid = (l + r) >> 1;
    pushdown(rt, mid - l + 1, r - mid);
    long long ans = 0;
    if (L <= mid)
        ans += query(L, R, l, mid, rt << 1);
    if (R > mid)
        ans += query(L, R, mid + 1, r, rt << 1 | 1);
    return ans;
}
int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    build(1, n, 1);
    for (int i = 1; i <= m; i++)
    {
        int op, x, y, k;
        scanf("%d", &op);
        if (op == 1)
        {
            scanf("%d %d %d", &x, &y, &k);
            add(x, y, 1, n, 1, k);
        }
        if (op == 2)
        {
            scanf("%d %d", &x, &y);
            printf("%lld\n", query(x, y, 1, n, 1));
        }
    }
    return 0;
}