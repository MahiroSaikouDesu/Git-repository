#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> Pii;
const int inf = 0x3f3f3f3f;
const int N = 1e3, M = 1e5 + 10;

struct dinic
{
    int cap, flow, t, nxt, id;
} e[M << 1];
int n, m, f, head[N], d[N], idx, cityval[N], maxval;
void add(int u, int v, int flow, int id)
{
    e[idx].t = v;
    e[idx].cap = flow;
    e[idx].flow = 0;
    e[idx].nxt = head[u];
    e[idx].id = id;
    head[u] = idx++;

    e[idx].t = u;
    e[idx].cap = 0;
    e[idx].flow = 0;
    e[idx].nxt = head[v];
    e[idx].id = id;
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
void dinic(int s, int t)
{
    int maxflow = 0;
    while (bfs(s, t))
    {
        maxflow += dfs(s, inf, t);
    }

    cout << maxval - maxflow << "\n";

    queue<int> ans;
    for (int i = 0; i < 2 * m; i += 2)
    {
        int u = e[i ^ 1].t, v = e[i].t;
        if (d[u] && !d[v])
            ans.push(i / 2 + 1);
    }
    cout << ans.size();
    while (!ans.empty())
    {
        int u = ans.front();
        ans.pop();
        cout << ' ' << u;
    }
    cout << '\n';
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T, kas = 0;
    cin >> T;
    while (T--)
    {
        maxval = idx = 0;
        memset(head, -1, sizeof head);
        memset(cityval, 0, sizeof cityval);

        cin >> n >> m >> f;
        int u, v, w;
        for (int i = 1; i <= m; i++)
        {
            cin >> u >> v >> w;
            add(u, v, w, i);
        }
        for (int i = 1; i <= f; i++)
        {
            cin >> u >> w;
            add(u, n + 1, w, 0);
            cityval[u] = w;
            maxval += w;
        }

        kas++;
        cout << "Case " << kas << ": ";
        dinic(1, n + 1);
    }
    return 0;
}