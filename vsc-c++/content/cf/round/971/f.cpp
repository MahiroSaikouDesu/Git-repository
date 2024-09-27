#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> P;
const int inf = 0x3f3f3f3f << 1;
const int N = 2e5 + 10;
ll a[2 * N], s[2 * N];

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t, n, q;
    cin >> t;
    while (t--)
    {
        cin >> n >> q;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            a[n + i] = a[i];
        for (int i = 0; i < 2 * n; i++)
            s[i] = (i == 0 ? 0 : s[i - 1]) + a[i];

        ll l, r;
        while (q--)
        {
            cin >> l >> r;
            l--, r--;

            ll t1 = l / n, t2 = r / n, ans = 0;
            l %= n, r %= n;
            if (t2 > t1)
                ans += (t2 - t1 - 1) * s[n - 1];
            if (t1 == t2)
                ans += s[t1 + r] - (t1 + l - 1 == -1 ? 0 : s[t1 + l - 1]);
            else
            {
                ans += s[t1 + n - 1] - (t1 + l - 1 == -1 ? 0 : s[t1 + l - 1]);
                ans += s[t2 + r] - (t2 - 1 == -1 ? 0 : s[t2 - 1]);
            }

            cout << ans << '\n';
        }
    }
    return 0;
}