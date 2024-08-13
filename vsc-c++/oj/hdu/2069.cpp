#include <bits/stdc++.h>
using namespace std;
vector<int> ask;
int maxx, dp[500][120], ans[500];
int type[5] = {1, 5, 10, 25, 50};

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tmp;
    while (cin >> tmp)
    {
        ask.push_back(tmp);
        maxx = max(maxx, tmp);
    }

    dp[0][0] = 1;
    for (int i = 0; i < 5; i++)        // type
        for (int j = 1; j <= 100; j++) // coins
            for (int k = type[i]; k <= maxx; k++)
                dp[k][j] += dp[k - type[i]][j - 1];

    for (auto i : ask)
    {
        if (!ans[i])
            for (int j = 0; j <= 100; j++)
                ans[i] += dp[i][j];
        cout << ans[i] << '\n';
    }
    return 0;
}