#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> P;
const int inf = 0x3f3f3f3f << 1;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t, n, d, k, a, b, res1, res2, cnt1, cnt2;
    cin >> t;
    while (t--)
    {
        cin >> n >> d >> k;
        vector<P> v(k);
        for (auto &i : v)
        {
            cin >> a >> b;
            i = {a, b};
        }
        sort(v.begin(), v.end(), greater<P>());

        cnt1 = 0;
        cnt2 = inf;
        res1 = res2 = 1;
        for (int i = 0; i < n; i++)
        {
            P nxt = {v[i].second + d - 1, 0};

            if (nxt.first > n)
                break;
            int fnxt = upper_bound(v.begin(), v.end(), nxt) - v.begin() - 1;
            if (fnxt - i + 1 > cnt1)
            {
                cnt1 = fnxt - i + 1;
                res1 = max(v[i].second - nxt.first + v[fnxt].first, 1);
            }

            if (i == 0)
            {
                nxt.first = d;
                cnt2 = upper_bound(v.begin(), v.end(), nxt) - v.begin();
            }
            else
            {
                nxt.first = v[i - 1].second + d - 1;
                fnxt = upper_bound(v.begin(), v.end(), nxt) - v.begin() - 1;
                if (fnxt - i + 1 < cnt2)
                {
                    cnt2 = fnxt - i + 1;
                    res2 = nxt.first;
                }
            }
        }
        cout << res1 << ' ' << res2 << '\n';
    }
    return 0;
}