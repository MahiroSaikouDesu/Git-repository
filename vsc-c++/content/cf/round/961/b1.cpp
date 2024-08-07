#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<ll, ll> P;

ll work()
{
    ll n, m, res = 0ll, tmp;
    map<ll, ll> mp;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> tmp;
        mp[tmp]++;
    }
    auto it = mp.begin();
    P last = (*it);
    it++;
    res = max(res, min(last.second, m / last.first) * last.first);
    for (; it != mp.end(); it++)
    {
        P now = (*it);
        tmp = min(now.second, m / now.first);
        res = max(res, tmp * now.first);
        if (last.first + 1 < now.first)
        {
            last = now;
            continue;
        }
        ll t1 = last.first * last.second, t2 = now.first * now.second;
        if (t1 + t2 <= m)
        {
            res = max(res, t1 + t2);
            last = now;
            continue;
        }
        ll buylast = min(last.second, m / last.first);
        while (buylast)
        {
            ll buynow = min(now.second, (m - last.first * buylast) / now.first);
            res = max(res, buylast * last.first + buynow * now.first);
            if (buynow == now.second)
                buylast = 0;
            else
                buylast--;
        }
        last = now;
    }
    return res;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--)
        cout << work() << '\n';
    return 0;
}