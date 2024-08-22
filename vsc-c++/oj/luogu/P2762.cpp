#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> Pii;
const int inf = 0x3f3f3f3f;
const int N = 110, M = N * N;

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
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    memset(head, -1, sizeof head);
    cin >> m >> n;
    int s = 0, t = m + n + 1, tot = 0;
    for (int i = 1; i <= m; i++)
    {
        cin >> a;
        add(s, i, a);
        tot += a;
        char tools[10000];
        memset(tools, 0, sizeof tools);
        cin.getline(tools, 10000);
        int ulen = 0, tool;
        while (sscanf(tools + ulen, "%d", &tool) == 1) // 之前已经用scanf读完了赞助商同意支付该实验的费用
        {                                              // tool是该实验所需仪器的其中一个
            // 这一行，你可以将读进来的编号进行储存、处理，如连边。
            add(i, tool + m, inf);
            if (tool == 0)
                ulen++;
            else
            {
                while (tool)
                {
                    tool /= 10;
                    ulen++;
                }
            }
            ulen++;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        add(i + m, t, a);
    }
    tot -= dinic(s, t);

    for (int i = 1; i <= m; i++)
        if (d[i])
            cout << i << ' ';
    cout << '\n';

    for (int i = 1; i <= n; i++)
        if (d[i + m])
            cout << i << ' ';
    cout << '\n';
    cout << tot;

    return 0;
}