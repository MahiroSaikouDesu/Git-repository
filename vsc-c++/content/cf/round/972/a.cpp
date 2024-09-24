#include <bits/stdc++.h>
using namespace std;
string l = "aeiou";

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, t, cnt, lim;
    cin >> t;
    while (t--)
    {
        cin >> n;
        string ans;
        cnt = n / 5;
        lim = n % 5;
        for (int i = 0; i < 5; i++)
        {
            for (int j = 1; j <= cnt + (i < lim ? 1 : 0); j++)
                ans += l[i];
        }
        cout << ans << '\n';
    }
    return 0;
}