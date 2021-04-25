#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
template <class T>
class segment_tree
{
private:
    vector<T> elems;

public:
    void push_back(T k)
    {
        elems.push_back(k);
    }
    void add(int l, int r, T k);
    T query(T l, T r);
};
template <class T>
void segment_tree<T>::add(int l, int r, T k)
{
    for (int i = l; i <= r; i++)
    {
        elems[i] += k;
    }
}
template <class T>
T segment_tree<T>::query(T l, T r)
{
    T ans;
    for (int i = l; i <= r; i++)
    {
        ans += elems[i];
    }
    return ans;
}
int main()
{
    int n;
    segment_tree<int> SGT;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int k;
        scanf("%d", &k);
        SGT.push_back(k);
    }
    printf("%d", SGT.query(0, n - 1));
    return 0;
}