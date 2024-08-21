#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> Pii;
const int inf = 0x3f3f3f3f;
const int N = 210;

int n, vis[N], match[N], mp[N][N];
bool dfs(int u)
{
    for (int v = 1; v <= n; v++)
    {
        if (vis[v] || !mp[u][v])
            continue;
        vis[v] = 1;
        if (!match[v] || dfs(match[v]))
        {
            match[v] = u;
            return 1;
        }
    }
    return 0;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        memset(match, 0, sizeof match);
        cin >> n;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                cin >> mp[i][j];

        bool flag = 1;
        for (int i = 1; i <= n; i++)
        {
            memset(vis, 0, sizeof vis);
            if (!dfs(i))
            {
                flag = 0;
                break;
            }
        }
        if (flag)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}