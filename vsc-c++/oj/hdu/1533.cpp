#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> Pii;
const int inf = 0x3f3f3f3f;
const int N = 2e4 + 10, M = 4 * N;

int idx, head[N], d[N], pre[N], n, m, s, t;
int mp[110][110];
bool vis[N];
struct node
{
    int v, nxt, cap, flow, cost;
} e[M << 1];
void adde(int u, int v, int c, int cost)
{
    e[idx].v = v;
    e[idx].cap = c;
    e[idx].flow = 0;
    e[idx].cost = cost;
    e[idx].nxt = head[u];
    head[u] = idx++;
}
void add(int u, int v, int c, int cost)
{
    adde(u, v, c, cost);
    adde(v, u, 0, -cost);
}
bool SPFA(int s, int t)
{
    queue<int> q;
    memset(vis, false, sizeof vis);
    memset(pre, -1, sizeof pre);
    memset(d, 0x3f, sizeof d);
    vis[s] = 1;
    d[s] = 0;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for (int i = head[u]; ~i; i = e[i].nxt)
        {
            int v = e[i].v;
            if (e[i].cap > e[i].flow && d[v] > d[u] + e[i].cost)
            {
                d[v] = d[u] + e[i].cost;
                pre[v] = i;
                if (!vis[v])
                {
                    q.push(v);
                    vis[v] = 1;
                }
            }
        }
    }
    return pre[t] != -1;
}
int MCMF(int s, int t)
{
    int dis = 0, mincost = 0, maxflow = 0;
    while (SPFA(s, t))
    {
        dis = inf;
        for (int i = pre[t]; ~i; i = pre[e[i ^ 1].v])
            dis = min(dis, e[i].cap - e[i].flow);
        for (int i = pre[t]; ~i; i = pre[e[i ^ 1].v])
            e[i].flow += dis, e[i ^ 1].flow -= dis;
        maxflow += dis;
        mincost += d[t] * dis;
    }
    return mincost;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string line;
    while (cin >> n >> m && n && m)
    {
        s = 0, t = n * m + 3, idx = 0;
        memset(head, -1, sizeof head);
        for (int i = 0; i < n; i++)
        {
            cin >> line;
            for (int j = 0; j < line.size(); j++)
            {
                int now = i * m + j + 1;
                if (line[j] == '.')
                    mp[i][j] = 0;
                if (line[j] == 'H')
                {
                    mp[i][j] = 1;
                    add(now, t, 1, 0);
                }
                if (line[j] == 'm')
                {
                    mp[i][j] = 2;
                    add(s, now, 1, 0);
                }
            }
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                int now = i * m + j + 1;
                // up
                if (i)
                    add(now, now - m, inf, 1);
                // down
                if (i + 1 < n)
                    add(now, now + m, inf, 1);
                // left
                if (j)
                    add(now, now - 1, inf, 1);
                // right
                if (j + 1 < m)
                    add(now, now + 1, inf, 1);
            }

        cout << MCMF(s, t) << '\n';
    }
    return 0;
}