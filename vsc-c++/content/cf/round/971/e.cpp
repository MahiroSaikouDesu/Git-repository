#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
const ll inf = 5e18;
int t, n, k, r, l, mid, res, tmp, CONST, tmpb, tmpa;
#define f(mid) n *(mid) - (mid) + CONST

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        l = 1, r = n, res = inf, tmp, CONST = n * (1 - n) >> 1;
        while (l <= r)
        {
            mid = (l + r) >> 1;
            tmp = f(mid);
            tmp = abs(tmp);
            if (tmp < res)
                res = tmp;
            tmpa = f(mid - 1), tmpb = f(mid + 1);
            if (tmpa < tmp && tmp < tmpb)
                r = mid - 1;
            else if (tmpa > tmp && tmp > tmpb)
                l = mid + 1;
            else
                break;
        }
        cout << res << '\n';
    }
    return 0;
}