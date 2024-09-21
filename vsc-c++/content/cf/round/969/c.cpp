#include <bits/stdc++.h>
using namespace std;
#define ll long long


signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while(T--)
    {
        int n, a, b, tmp;
        cin >> n >> a >> b;
        vector<int> v;
        int d = __gcd(a, b);

        for (int i = 1; i <= n;i++)
        {
            cin >> tmp;
            tmp %= d;
            v.push_back(tmp);
        }

        sort(v.begin(), v.end());
        int res = v.back() - v.front();
        for (int i = 1; i < n;i++)
            res = min(res, v[i - 1] + d - v[i]);
        cout << res << "\n";
    }
    return 0;
}