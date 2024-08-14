#include <iostream>
#include <cstring>
using namespace std;
const int N = 120;
int dp[N][N], ss[N][N];

bool match(char a, char b)
{
    if (a == '[' && b == ']')
        return true;
    if (a == '(' && b == ')')
        return true;
    return false;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s;
    while (cin >> s && s != "end")
    {
        memset(dp, 0, sizeof dp);
        memset(ss, 0, sizeof ss);
        int m = s.length();

        for (int i = 0; i < m; i++)
            ss[i][i] = i;

        for (int d = 1; d < m; d++)
            for (int i = 0; i + d < m; i++)
            {
                int j = i + d, limit = ss[i + 1][j] ? ss[i + 1][j] : j - 1;
                if (match(s[i], s[j]))
                {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                }

                for (int k = ss[i][j - 1] ? ss[i][j - 1] : i; k <= limit; k++)
                {
                    if (dp[i][j] <= dp[i][k] + dp[k + 1][j])
                    {
                        dp[i][j] = dp[i][k] + dp[k + 1][j];
                        ss[i][j] = k;
                    }
                }

                // for (int k = i + 1; k < j; k++)
                //     dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j]);
            }

        cout << dp[0][m - 1] << '\n';
    }
    return 0;
}