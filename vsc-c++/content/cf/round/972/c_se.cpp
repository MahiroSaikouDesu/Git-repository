#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f << 1;
const string tar = "narek";

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, res = 0;
        cin >> n >> m;
        vector<int> dp(5, -inf), ndp;
        dp[0] = 0;

        vector<string> s(n);
        for (int i = 0; i < n; i++)
            cin >> s[i];

        for (auto i : s)
        {
            ndp = dp;

            for (int j = 0; j < 5; j++)
            {
                if (dp[j] == -inf)
                    continue;

                int nxt = j, cnt = 0;
                for (auto k : i)
                {
                    int now = tar.find(k);
                    if (now == -1)
                        continue;

                    now == nxt ? nxt = (now + 1) % 5, cnt++ : cnt--;
                }

                ndp[nxt] = max(ndp[nxt], dp[j] + cnt);
            }
            dp = ndp;
        }

        for (int i = 0; i < 5; i++)
            res = max(res, dp[i] - 2 * i);
        cout << res << "\n";
    }
    return 0;
}