#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> Pii;
const int inf = (1 << 30) + 1;
const int N = 1e3 + 20;
int n, a[2 * N], s[2 * N][2 * N], sum[2 * N], dp[2 * N][2 * N];

void solve()
{
    for (int d = 2; d <= n; d++)
        for (int i = 1; i + d <= 2 * n; i++)
        {
            int j = i + d - 1;
            int nowsum = sum[j] - sum[i - 1];
            dp[i][j] = inf;

            for (int k = s[i][j - 1]; k <= s[i + 1][j]; k++)
                if (dp[i][k] + dp[k + 1][j] + nowsum < dp[i][j])
                {
                    dp[i][j] = dp[i][k] + dp[k + 1][j] + nowsum;
                    s[i][j] = k;
                }
        }

    int ans = inf;
    for (int i = 1; i <= n; i++)
        ans = min(ans, dp[i][i + n - 1]);
    cout << ans << '\n';
}

void init()
{
    sum[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum[i] = a[i] + sum[i - 1];
        s[i][i] = i;
        dp[i][i] = 0;
    }
    for (int i = 1; i < n; i++)
    {
        a[n + i] = a[i];
        sum[i + n] = a[i + n] + sum[i + n - 1];
        s[i + n][i + n] = i + n;
        dp[i + n][i + n] = 0;
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    while (cin >> n)
    {
        init();
        solve();
    }
    return 0;
}