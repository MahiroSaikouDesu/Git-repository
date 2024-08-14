#include <iostream>
#include <cstring>
using namespace std;
const int N = 120;
int dp[N][N];

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
        int m = s.length();
        for (int i = m - 1; i >= 0; i--)
            for (int j = i + 1; j < m; j++)
            {
                if (match(s[i], s[j]))
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                for (int k = i + 1; k < j; k++)
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j]);
            }
        cout << dp[0][m - 1] << '\n';
    }
    return 0;
}