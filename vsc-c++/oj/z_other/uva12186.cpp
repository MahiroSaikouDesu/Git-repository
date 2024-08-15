#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> Pii;
const int inf = (1 << 30) + 1;
const int N = 1e5 + 10;
int n, T, dp[N];
double t;
vector<int> edge[N];

void dfs(int u)
{
    if (edge[u].size() == 0)
        dp[u] = 1;
    else
    {
        for (auto v : edge[u])
            dfs(v);
        vector<int> q;
        for (auto v : edge[u])
            q.push_back(dp[v]);
        sort(q.begin(), q.end());
        int limit = ceil(edge[u].size() * t);
        for (int i = 0; i < limit; i++)
            dp[u] += q[i];
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    while (cin >> n >> T && n && T)
    {
        t = T * 1.0 / 100;
        for (int i = 0; i <= n; i++)
        {
            edge[i].clear();
            dp[i] = 0;
        }

        for (int i = 1; i <= n; i++)
        {
            int tmp;
            cin >> tmp;
            edge[tmp].push_back(i);
        }
        dfs(0);
        cout << dp[0] << '\n';
    }
    return 0;
}