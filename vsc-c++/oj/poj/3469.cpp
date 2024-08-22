#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
#define ll long long
typedef pair<int, int> Pii;
const int inf = 0x3f3f3f3f;
const int N = 2e4 + 10, M = 2e5 + 10;

struct dinic
{
    int cap, flow, t, nxt;
} e[M << 1];
int n, m, head[N], d[N], idx, a, b, c;
void add(int u, int v, int flow)
{
    e[idx].t = v;
    e[idx].cap = flow;
    e[idx].flow = 0;
    e[idx].nxt = head[u];
    head[u] = idx++;

    e[idx].t = u;
    e[idx].cap = 0;
    e[idx].flow = 0;
    e[idx].nxt = head[v];
    head[v] = idx++;
}
bool bfs(int s, int t) // 分层
{
    memset(d, 0, sizeof d);
    queue<int> q;
    d[s] = 1;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = head[u]; ~i; i = e[i].nxt)
        {
            int v = e[i].t;
            if (!d[v] && e[i].cap > e[i].flow)
            {
                d[v] = d[u] + 1;
                q.push(v);
                if (v == t)
                    return 1;
            }
        }
    }
    return 0;
}
int dfs(int u, int flow, int t) // 分层基础上dfs || 返回u点的增流
{
    if (u == t)
        return flow;
    int rest = flow;
    for (int i = head[u]; ~i && rest; i = e[i].nxt)
    {
        int v = e[i].t;
        if (d[v] == d[u] + 1 && e[i].cap > e[i].flow)
        {
            int k = dfs(v, min(rest, e[i].cap - e[i].flow), t);
            if (!k)
                d[v] = 0;
            e[i].flow += k;
            e[i ^ 1].flow -= k;
            rest -= k;
        }
    }
    return flow - rest;
}
int dinic(int s, int t)
{
    int maxflow = 0;
    while (bfs(s, t))
    {
        maxflow += dfs(s, inf, t);
    }
    return maxflow;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    memset(head, -1, sizeof head);
    int s = 0, t = n + 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> a >> b;
        add(s, i, b);
        add(i, t, a);
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> a >> b >> c;
        add(a, b, c);
        add(b, a, c);
    }

    cout << dinic(s, t) << '\n';
    return 0;
}