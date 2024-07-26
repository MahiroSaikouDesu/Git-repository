#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;
const int N = 1e5;

int siz[N], del[N], mxs, tot, root; // ruuto
int dis[N], d[N], cnt;              // kyori
int n, m, ask[N], ans[N];           // mondai
vector<Pii> mp[N];
void add(int u, int v, int w)
{
    mp[u].push_back(make_pair(v, w));
    mp[v].push_back(make_pair(u, w));
}
void getroot(int u, int fa)
{
    siz[u] = 1;
    int s = 0, limit = mp[u].size();
    for (int i = 0; i < limit; i++)
    {
        int v = mp[u][i].first;
        if (v = fa || del[v])
            continue;
        getroot(v, u);
        siz[u] += siz[v];
        s = max(s, siz[v]);
    }
    s = max(s, tot - siz[u]);
    if (s < mxs)
        mxs = s, root = u;
}
void getdis(int u, int fa)
{
    dis[++cnt] = d[u];
    int limit = mp[u].size();
    for (int i = 0; i < limit; i++)
    {
        int v = mp[u][i].first, w = mp[u][i].second;
        if (v == fa || del[v])
            continue;
        d[v] = d[u] + w;
        getdis(v, u);
    }
}
void calc(int u, int w, int sign)
{
    cnt = 0, d[u] = w;
    getdis(u, 0);
    sort(dis + 1, dis + 1 + cnt);
    for (int i = 1; i <= m; i++)
    {
        int l = 1, r = cnt;
        while (l < r)
            if (dis[l] + dis[r] <= ask[i])
            {
                ans[i] += sign * (r - l);
                ++l;
            }
            else
                --r;
    }
}
void divide(int u)
{
    calc(u, 0, 1); // 求答案
    del[u] = 1;
    int limit = mp[u].size();
    for (int i = 0; i < limit; i++)
    {
        int v = mp[u][i].first;
        if (del[v])
            continue;
        calc(v, mp[u][i].second, -1); // 容斥
        mxs = tot = siz[v];
        getroot(v, u); // 求根
        divide(root);  // 分治
    }
}
void work()
{
    mxs = tot = n;
    getroot(1, 0);
    getroot(root, 0);
    divide(root);
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    int u, v, w;
    for (int i = 2; i <= n; i++)
    {
        cin >> u >> v >> w;
        add(u, v, w);
    }
    m = 1;
    cin >> ask[1];
    work();
    cout << ans[1];
    return 0;
}