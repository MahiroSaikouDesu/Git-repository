#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
const int N = 2e5 + 10;

int t, n, l, r, mid, sum, maxx, maxit, res, cnt;
vector<int> a;

bool check(int x)
{
    a[maxit] += x;
    sum += x;
    cnt = 0;
    int limit = ceil(sum * 1.0 / n / 2);
    for (auto i : a)
        if (i < limit)
            cnt++;
    a[maxit] -= x;
    sum -= x;
    return cnt > n / 2 ? true : false;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n;
        a.resize(n);
        for (auto &i : a)
            cin >> i;

        if (n <= 2)
            cout << "-1\n";
        else
        {
            maxx = sum = a[0];
            maxit = 0;
            for (int i = 1; i < n; i++)
                if (a[i] > maxx)
                {
                    maxx = a[i];
                    maxit = i;
                    sum += a[i];
                }
                else
                    sum += a[i];

            l = 0, r = 1e13;
            while (l <= r)
            {
                mid = l + ((r - l) >> 1);
                if (check(mid))
                    res = mid, r = mid - 1;
                else
                    l = mid + 1;
            }
            cout << res << '\n';
        }
    }
    return 0;
}