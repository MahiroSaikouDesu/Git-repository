#include <bits/stdc++.h>
using namespace std;
const int N = 100, M = 1e5;
int n, m;
vector<int> v(N + 10), c(N + 10);
bool dp[M + 10];
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    while (cin >> n >> m && n && m)
    {
        memset(dp, false, sizeof dp);
        for (int i = 1; i <= n; i++)
            cin >> v[i]; // val
        for (int i = 1; i <= n; i++)
            cin >> c[i]; // count
        dp[0] = true;
        for (int i = 1; i <= n; i++)
        {
            if (c[i] * v[i] >= m)
                for (int j = v[i]; j <= m; j++)
                    dp[j] = dp[j] || dp[j - v[i]] ? true : false;
            else
            {
                for (int k = 1; c[i] > 0; k <<= 1)
                {
                    int p = min(k, c[i]);
                    for (int j = m; j >= v[i] * p; j--) // 01
                        dp[j] = dp[j] || dp[j - p * v[i]] ? true : false;
                    c[i] -= p;
                }
            }
        }
        int cnt = 0;
        for (int j = 1; j <= m; j++)
            cnt += dp[j] ? 1 : 0;
        cout << cnt << '\n';
    }
    return 0;
}