#include <bits/stdc++.h>
using namespace std;
#define ll long long

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t, n, k;
    cin >> t;
    ll now = 0, ans = 0;
    while (t--)
    {
        cin >> n >> k;
        vector<int> v(n);
        for (auto &i : v)
            cin >> i;
        now = 0, ans = 0;

        for (auto i : v)
        {
            if (i >= k)
                now += i;
            if (i == 0 && now)
                ans++, now--;
        }
        cout << ans << '\n';
    }
    return 0;
}