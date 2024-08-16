#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> Pii;
const int inf = (1 << 30) + 1;
const int N = 1e4 + 10;
int dp[N][3], n, idx[N];
vector<Pii> edge[N];

void dfs1(int u, int fa)
{
    int mx1 = 0, mx2 = 0;
    for (auto t : edge[u])
    {
        int v = t.first;
        if (v == fa)
            continue;
        dfs1(v, u);
        int tmp = dp[v][0] + t.second;
        if (mx1 <= tmp)
            mx2 = mx1, mx1 = tmp, idx[u] = v;
        else
            mx2 = max(mx2, tmp);
    }
    dp[u][0] = mx1, dp[u][1] = mx2;
}

void dfs2(int u, int fa)
{
    for (auto t : edge[u])
    {
        int v = t.first;
        if(v==fa) continue;
        dp[v][2] = t.second + max(dp[u][2], idx[u] == v ? dp[u][1] : dp[u][0]);
        dfs2(v, u);
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    while (cin >> n)
    {
        int v, w;
        for (int i = 0; i <= n; i++)
        {
            idx[i] = dp[i][0] = dp[i][1] = dp[i][2] = 0;
            edge[i].clear();
        }
        for (int i = 2; i <= n; i++)
        {
            cin >> v >> w;
            edge[i].push_back({v, w});
            edge[v].push_back({i, w});
        }

        dfs1(1, -1);
        dfs2(1, -1);

        for (int i = 1; i <= n;i++)
            cout << max(dp[i][0], dp[i][2]) << '\n';
    }
    return 0;
}