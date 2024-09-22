#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t, a, b;
    cin >> t;
    while (t--)
    {
        cin >> a >> b;
        if (a == b)
        {
            cout << "1\n";
            continue;
        }
        int l = 1, r = (b - a), ans, mid, cha = r;
        while (l <= r)
        {
            mid = (l + r) / 2;
            // cout << l << ' ' << r << ' ' << ans << '\n';
            if (mid * (mid + 1) / 2 <= cha)
                ans = mid, l = mid + 1;
            else
                r = mid - 1;
        }
        cout << ans + 1 << '\n';
    }
    return 0;
}