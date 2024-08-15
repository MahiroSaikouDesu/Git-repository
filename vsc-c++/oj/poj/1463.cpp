#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstdlib>
using namespace std;
#define ll long long
typedef pair<int, int> Pii;
const int inf = (1 << 30) + 1;
const int N = 1510;
int dp[N][2], n, fa[N];
vector<int> edge[N];

void dfs(int u)
{
    dp[u][0] = 0;
    dp[u][1] = 1;
    for (int i = 0; i < edge[u].size(); i++)
    {
        int v = edge[u][i];
        dfs(v);
        dp[u][0] += dp[v][1];
        dp[u][1] += min(dp[v][0], dp[v][1]);
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    char tmp[10];
    while (cin >> n)
    {
        for (int i = 0; i <= n; i++)
        {
            fa[i] = -1;
            edge[i].clear();
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> tmp;
            int a, b, c;
            sscanf(tmp, "%d:(%d)", &a, &b);
            while (b--)
            {
                cin >> c;
                edge[a].push_back(c);
                fa[c] = a;
            }
        }
        int root = 0;
        while (fa[root] != -1)
            root = fa[root];
        dfs(root);
        cout << min(dp[root][0], dp[root][1]) << '\n';
    }
    return 0;
}