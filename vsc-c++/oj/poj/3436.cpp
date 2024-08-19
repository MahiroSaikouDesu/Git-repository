#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> Pii;
const int inf = 0x3f3f3f3f;
const int N = 110, M = N * N;

struct node
{
    int t, nxt, cap, flow;
} edge[M << 1];
int n, p, idx, h[N], g[N], head[N], pre[N], s, t;
int in[N][N], out[N][N];
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
    int q, tmp, tot;
    while (cin >> p >> n)
    {
        memset(head, -1, sizeof head);
        idx = 0, t = 2 * n + 1, tot = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> q;
            add(i, i + n, q);
            for (int j = 1; j <= p; j++)
                cin >> in[i][j];
            for (int j = 1; j <= p; j++)
                cin >> out[i][j];
            tmp = 1;
            for (int j = 1; j <= p; j++)
                if (in[i][j] != 0)
                    tmp = 0;
            if (tmp)
                add(0, i, q);
            tmp = 1;
            for (int j = 1; j <= p; j++)
                if (out[i][j] == 0)
                    tmp = 0;
            if (tmp)
                add(i + n, t, q);
        }
        cout << ISAP(s, t, t + 1) << ' ';
        vector<int> vec;
        for (int i = 1; i <= n; i++)
        {
            int j = head[i];
            while (edge[j].t != i + n)
                j = edge[j].nxt;
            if (edge[j].flow)
                vec.push_back(j);
        }
        cout << vec.size() << ' ';
        queue<int> ans;
        for (auto idx : vec)
        {
            int s1 = edge[idx ^ 1].t, s2 = s1 + n;
            for (int i = head[s2]; ~i; i = edge[i].nxt)
            {
                int v = edge[i].t;
                if (v == s1 || v == t)
                    continue;
                tot++;
                ans.push(s1);
                ans.push(v);
                ans.push(edge[i].flow);
            }
        }
        cout << tot << '\n';
        while (!ans.empty())
        {
            for (int i = 1; i <= 3; i++)
            {
                tmp = ans.front();
                ans.pop();
                cout << tmp << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}