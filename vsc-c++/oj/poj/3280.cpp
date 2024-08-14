#include <iostream>
using namespace std;
const int N = 2e3 + 10;
string s;
int n, m, w[50], dp[N][N];

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m >> s;
    for (int i = 1; i <= n; i++)
    {
        char c;
        int w1, w2;
        cin >> c >> w1 >> w2;
        w[c - 'a'] = min(w1, w2);
    }

    for (int i = m - 1; i >= 0; i--)
        for (int j = i + 1; j < m; j++)
        {
            if (s[i] == s[j])
                dp[i][j] = dp[i + 1][j - 1];
            else
                dp[i][j] = min(dp[i + 1][j] + w[s[i] - 'a'], dp[i][j - 1] + w[s[j] - 'a']);
        }
    cout << dp[0][m - 1];
    return 0;
}