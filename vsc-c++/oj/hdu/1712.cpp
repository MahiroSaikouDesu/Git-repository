#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int a[N][N], n, m, dp[N];

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    while (cin >> n >> m && n && m)
    {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cin >> a[i][j];
        memset(dp, 0, sizeof dp);
        for (int i = 1; i <= n; i++)
            for (int j = m; j; j--)
                for (int k = 1; k <= j; k++)
                    dp[j] = max(dp[j], a[i][k] + dp[j - k]);
        cout << dp[m] << "\n";
    }
    return 0;
}