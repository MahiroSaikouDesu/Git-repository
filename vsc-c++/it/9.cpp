#include <bits/stdc++.h>
using namespace std;
int n, m, M;
const int N = 9700;

void solve()
{
    vector<vector<int>> dp;
    dp.resize(m + 1, vector<int>(n + 1));
    dp[0][0] = 1;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (j - i >= 0)
                dp[i][j] = (dp[i - 1][j] + dp[i][j - i]) % M;
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    printf("%d\n", dp[m][n]);
}

int main()
{
    scanf("%d%d%d", &n, &m, &M);
    solve();
    return 0;
}