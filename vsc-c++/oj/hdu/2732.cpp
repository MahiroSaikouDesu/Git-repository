#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> Pii;
const int inf = 0x3f3f3f3f;
const int N = 1e3 + 10, M = N * N;

struct node
{
    int t, nxt, cap, flow;
} edge[M << 1];
int n, m, idx, h[N], g[N], head[N], pre[N], d, s, t;
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

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T, tot, cas = 0;
    string line;
    cin >> T;
    while (T--)
    {
        memset(head, -1, sizeof head);
        idx = 0, tot = 0;
        cin >> n >> d;
        for (int i = 0; i < n; i++)
        {
            cin >> line;
            if (i == 0)
            {
                m = line.length();
                t = 2 * n * m + 1;
            }
            for (int j = 0; j < line.size(); j++)
            {
                int id = i * m + j + 1;
                add(id, id + n * m, line[j] - '0');
                if (i < d || i + d >= n || j < d || j + d >= m) // 安全
                    add(id + n * m, t, inf);
                else
                    for (int k = 0; k < n; k++)
                        for (int h = 0; h < m; h++)
                        {
                            int id2 = k * m + h + 1;
                            if (id == id2)
                                continue;
                            if (abs(i - k) + abs(j - h) <= d)
                                add(id + n * m, id2, inf);
                        }
            }
        }
        for (int i = 0; i < n; i++)
        {
            cin >> line;
            for (int j = 0; j < line.size(); j++)
                if (line[j] == 'L')
                {
                    int id = i * m + j + 1;
                    add(s, id, 1);
                    tot++;
                }
        }
        int ans = tot - ISAP(s, t, t + 1);
        if (ans == 0)
            printf("Case #%d: no lizard was left behind.\n", ++cas);
        else if (ans == 1)
            printf("Case #%d: 1 lizard was left behind.\n", ++cas);
        else
            printf("Case #%d: %d lizards were left behind.\n", ++cas, ans);
    }
    return 0;
}