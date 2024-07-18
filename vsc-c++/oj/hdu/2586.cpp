#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;
const int N = 4e4 + 10, K = 15;

int pos[N], seq[2 * N - 1], dep[2 * N - 1], F[2 * N - 1][K], tot, n, m, dis[N];
//|| pos - first time meet || seq - Euler list || F - ST // the deepest index || dep - depth
bool vis[N];
vector<vector<Pii>> mp; // (int -> Pii) => + distance
void dfs(int u, int d)
{
    vis[u] = true;
    pos[u] = ++tot;
    seq[tot] = u;
    dep[tot] = d;
    for (auto i : mp[u])
    {
        if (vis[i.first])
            continue;
        dis[i.first] = dis[u] + i.second;
        dfs(i.first, d + 1);
        seq[++tot] = u;
        dep[tot] = d;
    }
}
void stCreate()
{
    for (int i = 1; i <= tot; i++)
        F[i][0] = i;
    int k = log2(tot);
    for (int j = 1; j <= k; j++)
        for (int i = 1; i <= tot - (1 << j) + 1; i++)
            F[i][j] = dep[F[i][j - 1]] < dep[F[i + (1 << (j - 1))][j - 1]] ? F[i][j - 1] : F[i + (1 << (j - 1))][j - 1];
}
int RMQ_query(int l, int r)
{
    int k = log2(r - l + 1);
    return dep[F[l][k]] < dep[F[r - (1 << k) + 1][k]] ? F[l][k] : F[r - (1 << k) + 1][k];
}
int LCA(int x, int y)
{
    int l = pos[x], r = pos[y]; // l <= r
    if (l > r)
        swap(l, r);
    return seq[RMQ_query(l, r)];
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n >> m;
        memset(vis, false, sizeof vis);
        mp.clear();
        mp.resize(n + 10);
        tot = 0;
        dis[0] = 0;
        int flag = 1;
        for (int i = 1; i < n; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            if (flag)
            {
                mp[0].push_back({a, 0});
                flag = 0;
            }
            mp[a].push_back({b, c});
            mp[b].push_back({a, c});
        }
        dfs(0, 0);
        stCreate();

        while (m--)
        {
            int a, b;
            cin >> a >> b;
            cout << dis[a] + dis[b] - 2 * dis[LCA(a, b)] << '\n';
        }
    }
    return 0;
}