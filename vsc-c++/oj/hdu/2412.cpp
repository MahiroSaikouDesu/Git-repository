#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> Pii;
const int inf = (1 << 30) + 1;
const int N = 210;
int dp[N][2], f[N][2], n;
map<string, int> mp;
vector<int> edge[N];

void dfs(int u)
{
    dp[u][0] = 0;
    dp[u][1] = 1;
    for (auto v : edge[u])
    {
        dfs(v);
        if(dp[v][0]==dp[v][1])
        {
            dp[u][0] += dp[v][0];
            f[u][0] = 0;
        }
        else if(dp[v][0]>dp[v][1])
        {
            dp[u][0] += dp[v][0];
            f[u][0] = f[u][0] && f[v][0] ? 1 : 0;
        }
        else
        {
            dp[u][0] += dp[v][1];
            f[u][0] = f[u][0] && f[v][1] ? 1 : 0;
        }
        dp[u][1] += dp[v][0];
        f[u][1] = f[u][1] && f[v][0] ? 1 : 0;
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    while (cin >> n && n)
    {
        int idx = 0;
        string a, b;
        mp.clear();
        for (int i = 0; i <= n; i++)
            edge[i].clear();
        memset(f, 1, sizeof f);
        cin >> b;
        mp[b] = ++idx;
        edge[0].push_back(1);

        for (int i = 1; i < n; i++)
        {
            cin >> a >> b;
            if (mp[a] == 0)
                mp[a] = ++idx;
            if (mp[b] == 0)
                mp[b] = ++idx;
            edge[mp[b]].push_back(mp[a]);
        }

        dfs(0);

        cout << dp[0][0] << " ";
        if(f[0][0])
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}