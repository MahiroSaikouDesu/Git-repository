#include <iostream>
using namespace std;
const int N = 110;
int a[N], dp[N][N];

void solve(int n)
{
    for (int len = 2; len <= n; len++)
    {
        for (int i = 1; i + len <= 1 + n; i++)
        {
            int j = i + len - 1;
            dp[i][j] = dp[i + 1][j] + a[i - 1] * a[i] * a[j];
            for (int k = i + 1; k < j; k++)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + a[i - 1] * a[k] * a[j]);
            }
        }
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    solve(n - 1);
    cout << dp[1][n - 1];
    return 0;
}