#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> P;
const int inf = 0x3f3f3f3f << 1;
const int N = 1e5 + 10;
int d[N], edge[N];
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T, a, b, n;
    string s;
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            edge[i] = 0;

        for (int i = 1; i < n; i++)
        {
            cin >> a >> b;
            edge[a] += 1;
            edge[b] += 1;
        }
        cin >> s;
        for (int i = 1; i <= n; i++)
            if (s[i - 1] == '1')
                d[i] = 1;
            else if (s[i - 1] == '0')
                d[i] = 0;
            else
                d[i] = -1;

        int d0 = 0, d1 = 0, df = 0, ans = 0, dun = 0;
        for (int i = 2; i <= n; i++)
            if (edge[i] == 1)
            {
                if (d[i] == 1)
                    d1++;
                else if (d[i] == -1)
                    df++;
                else
                    d0++;
            }
            else if (d[i] == -1)
                dun++;
        // cout << d0 << ' ' << d1 << ' ' << df << ' ' << dun << '\n';
        if (d[1] != -1)
        {
            if (d[1] == 1)
                ans += d0;
            else
                ans += d1;
            ans += (df + 1) / 2;
        }
        else
        {
            if (d0 != d1)
            {
                ans += max(d0, d1) + df / 2;
            }
            else
            {
                ans += d0;
                if (dun % 2 == 0)
                    ans += (df) / 2;
                else
                    ans += (df + 1) / 2;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}