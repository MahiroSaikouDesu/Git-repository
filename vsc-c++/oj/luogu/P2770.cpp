#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> Pii;
const int inf = 0x3f3f3f3f;
const int N = 220, M = 1e4;

int idx, head[N], d[N], pre[N], n, m, s, t;
bool vis[N];
map<string, int> mp;
vector<string> mp2;
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
vector<int> ans[2];
int dis, mincost, maxflow;
int MCMF(int s, int t)
{
    while (SPFA(s, t))
    {
        dis = 1;
        for (int i = pre[t]; ~i; i = pre[e[i ^ 1].v])
        {
            e[i].flow += dis, e[i ^ 1].flow -= dis;
        }
        maxflow += dis;
        mincost += d[t] * dis;
    }
    return maxflow;
}
void print(int s, int t)
{
    int v;
    vis[s] = 1;
    for (int i = head[s]; ~i; i = e[i].nxt)
    {
        v = e[i].v;
        if (!vis[v] && ((e[i].flow > 0 && e[i].cost <= 0) || (e[i].flow < 0 && e[i].cost >= 0)))
        {
            print(v, t);
            if (v <= t)
                cout << mp2[v] << endl;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    memset(head, -1, sizeof head);
    mp2.resize(n + 10);
    string name, name2;
    s = 1, t = 2 * n;
    for (int i = 1; i <= n; i++)
    {
        cin >> name;
        mp[name] = i;
        mp2[i] = name;
        add(i, i + n, i == n || i == 1 ? 2 : 1, 0);
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> name >> name2;
        int u = mp[name], v = mp[name2];
        if (u > v)
            swap(u, v);
        add(n + u, v, v == n && u == 1 ? 2 : 1, -1);
    }
    if (MCMF(s, t) >= 2)
    {
        cout << -mincost << "\n";
        memset(vis, 0, sizeof vis);
        cout << mp2[1] << '\n';
        print(1, n);
        cout << mp2[1] << '\n';
    }
    else
        cout << "No Solution!\n";
    return 0;
}