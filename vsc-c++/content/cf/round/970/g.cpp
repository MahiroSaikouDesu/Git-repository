#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f << 1;
int t, n, k, g, flag;
vector<int> a;

bool check(int x)
{
    int cnt = -1, flag = 1;
    for (auto i : a)
        if (i < x)
            cnt++;
        else
        {
            if (i == x)
                cnt++, flag = 0;
            break;
        }
    return x - cnt < k || (flag && x - cnt <= k);
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--)
    {
        g = flag = 0;
        cin >> n >> k;
        if (n == 1)
        {
            int now;
            cin >> now;
            if (k <= now)
                cout << k - 1;
            else
                cout << k;
            cout << '\n';
            continue;
        }
        a.resize(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        for (int i = 0; i < n; i++)
            if (!a[i])
                flag++;
            else
                g = g ? __gcd(g, a[i]) : a[i];

        int limit = n - max(1, flag);
        a.resize(limit + 1);
        for (int i = 0; i <= limit; i++)
            a[i] = i * g;

        int l = 0, r = INF, mid, res;
        while (l <= r)
        {
            mid = (l + r) >> 1;
            if (check(mid))
                res = mid, l = mid + 1;
            else
                r = mid - 1;
        }
        cout << res << "\n";
    }
    return 0;
}