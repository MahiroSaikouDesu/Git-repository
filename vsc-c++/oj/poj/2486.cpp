#include <iostream>
#include <vector>
using namespace std;
#define ll long long
typedef pair<int, int> Pii;
const int inf = (1 << 30) + 1;
const int N = 110, M = 210;
int dp[N][M][2], val[N], n, m;
vector<int> edge[N];


void dfs(int u, int fa)
{
    for (int i = 0; i <= m; i++)
        dp[u][i][0] = dp[u][i][1] = val[u];

    for (int t = 0; t < edge[u].size(); t++)
    {
        int v = edge[u][t];
        if (v == fa)
            continue;
        dfs(v, u);

        for (int j = m; j >= 1; j--)     // tot
            for (int i = 1; i <= j; i++) // k
            {
                if (i >= 2)
                {
                    dp[u][j][1] = max(dp[v][i - 2][1] + dp[u][j - i][1], dp[u][j][1]);
                    dp[u][j][0] = max(dp[v][i - 2][1] + dp[u][j - i][0], dp[u][j][0]);
                }
                dp[u][j][0] = max(dp[v][i - 1][0] + dp[u][j - i][1], dp[u][j][0]);
            }
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    while (cin >> n >> m)
    {
        int a, b;
        for (int i = 1; i <= n; i++)
            cin >> val[i];
        for (int i = 0; i <= n; i++)
            edge[i].clear();
        for (int i = 1; i < n; i++)
        {
            cin >> a >> b;
            edge[a].push_back(b);
            edge[b].push_back(a);
        }

        dfs(1, -1);
        cout << max(dp[1][m][0], dp[1][m][1]) << '\n';
    }
    return 0;
}