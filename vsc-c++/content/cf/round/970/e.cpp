#include <bits/stdc++.h>
using namespace std;
const int N = 30, M = 2e5 + 10;
int pre1[M][N], pre2[M][N], su1[M][N], su2[M][N];
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
            vector<int> mp1(N), mp2(N);
            for (int i = 0; i < s.length(); i += 2)
            {
                mp1[s[i] - 'a']++;
                maxx1 = max(maxx1, mp1[s[i] - 'a']);
            }
            for (int i = 1; i < s.length(); i += 2)
            {
                mp2[s[i] - 'a']++;
                maxx2 = max(maxx2, mp2[s[i] - 'a']);
            }
            ans = n - maxx1 - maxx2;
            cout << ans << '\n';
        }
        else
        {
            for (int i = 0; i < n; i++)
                for (int j = 0; j < 26; j++)
                    pre1[i][j] = pre2[i][j] = su1[i][j] = su2[i][j] = 0;

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < i; j += 2)
                    pre1[i][s[j] - 'a']++;
                for (int j = 1; j < i; j += 2)
                    pre2[i][s[j] - 'a']++;

                for (int j = i + 1; j < n; j += 2)
                    (i % 2 ? su2[i][s[j] - 'a'] : su1[i][s[j] - 'a'])++;
                for (int j = i + 2; j < n; j += 2)
                    (i % 2 ? su1[i][s[j] - 'a'] : su2[i][s[j] - 'a'])++;
            }

            int ans = 0x3f3f3f3f << 1, cnt1, cnt2, maxx1, maxx2;
            for (int i = 0; i < n; i++)
            {
                cnt1 = cnt2 = maxx1 = maxx2 = 0;
                for (int c = 0; c < 26; c++)
                {
                    cnt1 += pre1[i][c] + su1[i][c];
                    maxx1 = max(maxx1, pre1[i][c] + su1[i][c]);
                    cnt2 += pre2[i][c] + su2[i][c];
                    maxx2 = max(maxx2, pre2[i][c] + su2[i][c]);
                }
                ans = min(ans, cnt1 + cnt2 - maxx1 - maxx2 + 1);
            }
            cout << ans << '\n';
        }
    }
    return 0;
}