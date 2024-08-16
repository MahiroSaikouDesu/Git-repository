#include <iostream>
#include <cstdio>
using namespace std;
#define ll long long
typedef pair<int, int> Pii;
const int inf = (1 << 30) + 1;
const int N = 2e5 + 10;
int d[N], dp[N], n, deg[N], head[N], idx;
struct node
{
    int w, n, v;
} edge[N * 2];

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

void add(int u, int v, int w)
{
    idx++;
    edge[idx].n = head[u];
    edge[idx].w = w;
    edge[idx].v = v;
    head[u] = idx;
}

void dfs1(int u, int fa)
{
    for (int i = head[u]; ~i; i = edge[i].n)
    {
        int v = edge[i].v, w = edge[i].w;
        if (v == fa)
            continue;
        dfs1(v, u);
        if (deg[v] == 1)
            d[u] += w;
        else
            d[u] += min(d[v], w);
    }
}

void dfs2(int u, int fa)
{
    for (int i = head[u]; ~i; i = edge[i].n)
    {
        int v = edge[i].v, w = edge[i].w;
        if (v == fa)
            continue;
        if (deg[u] == 1)
            dp[v] = d[v] + w;
        else
        {
            int t = dp[u] - min(d[v], w); // u流向v以外的最大流量
            dp[v] = d[v] + min(t, w);
        }
        dfs2(v, u);
    }
}

signed main()
{
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T = read();
    while (T--)
    {
        int x, y, z, ans = 0;
        idx = 0;
        n = read();
        for (int i = 0; i <= n; i++)
        {
            d[i] = 0;
            dp[i] = 0;
            deg[i] = 0;
            head[i] = -1;
        }
        // memset(edge, 0, sizeof edge);
        for (int i = 1; i < n; i++)
        {
            x = read(), y = read(), z = read();
            add(x, y, z);
            add(y, x, z);
            deg[x]++, deg[y]++;
        }

        dfs1(1, -1);
        dp[1] = d[1];
        dfs2(1, -1);

        for (int i = 1; i <= n; i++)
            ans = max(ans, dp[i]);
        printf("%d\n", ans);
    }
    return 0;
}