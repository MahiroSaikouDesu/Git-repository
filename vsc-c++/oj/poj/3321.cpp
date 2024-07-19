#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = (x << 1) + (x << 3) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}
const int N = 1e5 + 100;

int c[N], n, l[N], r[N];
bool sti[N];

vector<int> mp[N];
#define lowbit(x) (x) & (-x)
int sum(int i) // a[1] + a[2] + ... + a[i]
{
    int res = 0;
    for (; i > 0; i -= lowbit(i))
        res += c[i];
    return res;
}
int sum(int i, int j) // a[i] + a[i+1] + ... + a[j-1] + a[j]
{
    return sum(j) - sum(i - 1);
}
void add(int i, int val) // a[i] += val
{
    for (; i <= n; i += lowbit(i))
        c[i] += val;
}
int cnt = 1;
void dfs(int p)
{
    l[p] = cnt++;
    for (int i = 0; i < mp[p].size(); i++)
    {
        int v = mp[p][i];
        dfs(v);
    }
    r[p] = cnt - 1;
}

signed main()
{
    n = read();
    memset(sti, true, sizeof sti);
    for (int i = 1; i <= n; i++)
        add(i, 1);
    for (int i = 1; i < n; i++)
    {
        int u = read(), v = read();
        mp[u].push_back(v);
    }
    dfs(1);
    int m = read(), op;
    while (m--)
    {
        char d[3];
        scanf("%s %d", d, &op);
        if (d[0] == 'Q')
            cout << sum(l[op], r[op]) << '\n';
        else
        {
            if (sti[l[op]]) // having
            {
                sti[l[op]] = false;
                add(l[op], -1);
            }
            else
            {
                sti[l[op]] = true;
                add(l[op], 1);
            }
        }
    }
    return 0;
}