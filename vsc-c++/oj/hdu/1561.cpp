#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> Pii;
const int inf = (1 << 30) + 1;
const int N = 210;
int n, m, dp[N][N], val[N], siz[N];
vector<int> edge[N];

void dfs(int u, int cnt)
{
    dp[u][1] = val[u];
    siz[u] += edge[u].size();
    for (auto v : edge[u])
    {
        dfs(v, cnt - 1);
        siz[u] += siz[v];
    }
    for (auto v : edge[u])
        for (int j = cnt; j >= 1; j--)
            for (int k = 1; k < j && k <= siz[u]; k++)
                dp[u][j] = max(dp[u][j], dp[u][j - k] + dp[v][k]);
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    while (cin >> n >> m && n && m)
    {
        m++;
        val[0] = 0;
        memset(dp, 0, sizeof dp);
        memset(siz, 0, sizeof siz);
        for (int i = 0; i <= n; i++)
            edge[i].clear();

        int a;
        for (int i = 1; i <= n; i++)
        {
            cin >> a >> val[i];
            edge[a].push_back(i);
        }

        dfs(0, m);
        cout << dp[0][m] << '\n';
    }
    return 0;
}