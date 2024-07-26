#include <iostream>
#include <algorithm>
using namespace std;

const int N = 10005;
const int INF = 10000005;
struct node
{
    int v, w, ne;
} e[N << 1];
int h[N], idx;                      // 加边
int del[N], siz[N], mxs, sum, root; // 求根
int dis[N], d[N], cnt;              // 求距离
int ans[N];                         // 求路径
int n, m, ask[N];

void add(int u, int v, int w)
{
    e[++idx].v = v;
    e[idx].w = w;
    e[idx].ne = h[u];
    h[u] = idx;
}
void getroot(int u, int fa)
{
    siz[u] = 1;
    int s = 0;
    for (int i = h[u]; i; i = e[i].ne)
    {
        int v = e[i].v;
        if (v == fa || del[v])
            continue;
        getroot(v, u);
        siz[u] += siz[v];
        s = max(s, siz[v]);
    }
    s = max(s, sum - siz[u]);
    if (s < mxs)
        mxs = s, root = u;
}
void getdis(int u, int fa)
{
    dis[++cnt] = d[u];
    for (int i = h[u]; i; i = e[i].ne)
    {
        int v = e[i].v;
        if (v == fa || del[v])
            continue;
        d[v] = d[u] + e[i].w;
        getdis(v, u);
    }
}
void calc(int u, int w, int sign)
{
    cnt = 0, d[u] = w;
    getdis(u, 0); // 求距离
    sort(dis + 1, dis + cnt + 1);
    for (int i = 1; i <= m; i++)
    {
        int l = 1, r = cnt;
        while (l < r)
        {
            if (dis[l] + dis[r] <= ask[i])
            {
                if (dis[l] + dis[r] == ask[i])
                    ans[i] += sign;
                ++l;
            }
            else
                --r;
        }
    }
}
void divide(int u)
{
    calc(u, 0, 1); // 求答案
    del[u] = 1;
    for (int i = h[u]; i; i = e[i].ne)
    {
        int v = e[i].v;
        if (del[v])
            continue;
        calc(v, e[i].w, -1); // 容斥
        mxs = sum = siz[v];
        getroot(v, u); // 求根
        divide(root);  // 分治
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i < n; ++i)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        add(u, v, w);
        add(v, u, w);
    }
    for (int i = 1; i <= m; ++i)
        scanf("%d", &ask[i]);
    mxs = sum = n;
    getroot(1, 0);
    getroot(root, 0); // 重构siz[]
    cout << root << '\n';
    divide(root);
    for (int i = 1; i <= m; ++i)
        ans[i] ? puts("AYE") : puts("NAY");
    return 0;
}