#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t, x, y, k;
    cin >> t;
    while (t--)
    {
        cin >> x >> y >> k;
        int resx = x / k + (x % k ? 1 : 0), resy = y / k + (y % k ? 1 : 0);
        // cout << resx << ' ' << resy << '\n';
        if (resx <= resy)
            cout << resy * 2 << '\n';
        else
            cout << resx * 2 - 1 << '\n';
    }
    return 0;
}