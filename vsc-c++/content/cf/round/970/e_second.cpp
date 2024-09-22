#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f << 1;
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t, n;
    cin >> t;
    string s;
    while (t--)
    {
        cin >> n >> s;
        if (n == 1 || n == 2 || n == 3)
        {
            cout << (n % 2 ? 1 : 0) << '\n';
            continue;
        }

        if (n % 2 == 0)
        {
            int ans = 0, maxx1 = 0, maxx2 = 0;
            vector<int> mp1(26), mp2(26);
            for (int i = 0; i < n; i++)
                (i % 2 ? maxx2 : maxx1) = max((i % 2 ? maxx2 : maxx1), ++(i % 2 ? mp2[s[i] - 'a'] : mp1[s[i] - 'a']));
            ans = n - maxx1 - maxx2;
            cout << ans << '\n';
        }
        else
        {
            vector<int> su[2] = {vector<int>(26), vector<int>(26)},
                        pre[2] = {vector<int>(26), vector<int>(26)};
            for (int i = 0; i < n; i++)
                su[i % 2][s[i] - 'a']++;

            int res1 = inf, ans, mx;
            for (int i = 0; i < n; i++)
            {
                su[i % 2][s[i] - 'a']--;
                ans = n;
                for (int k = 0; k < 2; k++)
                {
                    mx = 0;
                    for (int j = 0; j < 26; j++)
                        mx = max(mx, pre[k][j] + su[1 - k][j]);
                    ans -= mx;
                }
                pre[i % 2][s[i] - 'a']++;
                res1 = min(res1, ans);
            }
            cout << res1 << '\n';
        }
    }
    return 0;
}