#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t, n, m, q, nowlocation;
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> q;
        vector<int> b(m);
        for (int i = 0; i < m; i++)
            cin >> b[i];
        sort(b.begin(), b.end());

        while (q--)
        {
            cin >> nowlocation;
            // cout << b.front() << ' ' << b.back() << '\n';
            if (nowlocation < b.front())
            {
                cout << b.front() - 1 << "\n";
                continue;
            }
            if (nowlocation > b.back())
            {
                cout << n - b.back() << '\n';
                continue;
            }

            int l = 0, r = m - 1, mid, res;
            while (l <= r)
            {
                mid = (l + r) >> 1;
                if (b[mid] < nowlocation)
                    res = mid, l = mid + 1;
                else
                    r = mid - 1;
            }
            cout << ((b[res + 1] - b[res]) >> 1) << '\n';
        }
    }
    return 0;
}