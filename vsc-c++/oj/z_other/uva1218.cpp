#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> Pii;
const int inf = (1 << 30) + 1;
const int N = 1e4 + 10;
int n, dp[N][3];
vector<int> edge[N];

void dfs(int u, int fa)
{
    dp[u][0] = 1;
    dp[u][1] = 0;
    dp[u][2] = n;
    if (edge[u].size() == 1 && fa != 0)
        return;
    for (auto v : edge[u])
    {
        if (v == fa)
            continue;
        dfs(v, u);
        dp[u][0] += min(dp[v][0], dp[v][1]);
        dp[u][1] += dp[v][2];
    }
    for (auto v : edge[u])
        if (v != fa)
            dp[u][2] = min(dp[u][2], dp[u][1] - dp[v][2] + dp[v][0]);
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    while (cin >> n)
    {
        for (int i = 0; i <= n; i++)
            edge[i].clear();
        int a, b, op;
        for (int i = 1; i < n; i++)
        {
            cin >> a >> b;
            edge[a].push_back(b);
            edge[b].push_back(a);
        }

        dfs(1, 0);
        cout << min(dp[1][0], dp[1][2]) << '\n';
        cin >> op;
        if (op == -1)
            break;
    }
    return 0;
}