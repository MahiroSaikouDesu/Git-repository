#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> Pii;
const int inf = 0x3f3f3f3f;
const int N = 1e5 + 10, M = N * 2;

struct node
{
    int t, nxt, cap, flow;
} edge[M << 1];
int n, m, idx, h[N], g[N], head[N], pre[N];
void add(int x, int y, int z)
{
    edge[idx].t = y;
    edge[idx].cap = z;
    edge[idx].flow = 0;
    edge[idx].nxt = head[x];
    head[x] = idx++;

    edge[idx].t = x;
    edge[idx].cap = 0;
    edge[idx].flow = 0;
    edge[idx].nxt = head[y];
    head[y] = idx++;
}
void set_h(int t, int n)
{
    memset(h, -1, sizeof h);
    memset(g, 0, sizeof g);
    queue<int> q;
    h[t] = 0;
    q.push(t);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        g[h[u]]++; // 当前节点的高度的个数++
        for (int i = head[u]; ~i; i = edge[i].nxt)
        {
            int v = edge[i].t;
            if (h[v] == -1)
            {
                h[v] = h[u] + 1;
                q.push(v);
            }
        }
    }
}
int ISAP(int s, int t, int n)
{
    set_h(t, n);
    int ans = 0, u = s, d;
    while (h[s] < n)
    {
        int i = head[u];
        if (u == s)
            d = inf;
        for (; ~i; i = edge[i].nxt)
        {
            int v = edge[i].t;
            if (h[u] == h[v] + 1 && edge[i].cap > edge[i].flow)
            {
                u = v;
                pre[v] = i;
                d = min(d, edge[i].cap - edge[i].flow);
                if (u == t)
                {
                    while (u != s)
                    {
                        int j = pre[u];
                        edge[j].flow += d;
                        edge[j ^ 1].flow -= d;
                        u = edge[j ^ 1].t;
                    }
                    ans += d;
                    d = inf;
                }
                break;
            }
        }
        if (i == -1)
        {
            if (--g[h[u]] == 0)
                break;
            int hmin = n - 1;
            for (int j = head[u]; ~j; j = edge[j].nxt)
                if (edge[j].cap > edge[j].flow)
                    hmin = min(hmin, h[edge[j].t]);
            h[u] = hmin + 1;
            ++g[h[u]];
            u = u == s ? u : edge[pre[u] ^ 1].t;
        }
    }
    return ans;
}
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

signed main()
{
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T = read();
    while (T--)
    {
        idx = 0;
        memset(head, -1, sizeof head);
        int s, t, minn = inf, maxx = -inf, x, y, z;
        n = read(), m = read();
        for (int i = 1; i <= n; i++)
        {
            x = read(), y = read();
            if (x < minn)
                minn = x, s = i;
            if (x > maxx)
                maxx = x, t = i;
        }
        while (m--)
        {
            x = read(), y = read(), z = read();
            add(x, y, z);
            add(y, x, z);
        }
        printf("%d\n", ISAP(s, t, n));
    }
    return 0;
}