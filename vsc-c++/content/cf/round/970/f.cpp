#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9 + 7;
const int N = 2e5 + 10;
ll a[N];
long long fpow(long long a, long long b)
{
    long long ans = 1;
    while (b)
    {
        if (b & 1)
            ans *= a;
        ans %= mod;
        b >>= 1;
        a *= a;
        a %= mod;
    }
    return ans % mod;
}

ll inv(ll v)
{
    return fpow(v, mod - 2);
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t, n;
    ll sum, res, q;
    cin >> t;
    while (t--)
    {
        cin >> n;
        res = sum = 0;
        q = (1LL * n * (n - 1) / 2) % mod;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= n; i++)
            sum += a[i];

        for (int i = 1; i < n; i++)
        {
            sum -= a[i];
            res += a[i] * (sum % mod);
            res %= mod;
        }
        cout << (res % mod) * inv(q) % mod << '\n';
    }
    return 0;
}