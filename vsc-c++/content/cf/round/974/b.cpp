#include <bits/stdc++.h>
using namespace std;
#define ll long long

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t, n, k, sum;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        k = min(n, k) - 1;
        sum = (n + n - k) * (k + 1) / 2;
        cout << (sum % 2 ? "NO\n" : "YES\n");
    }
    return 0;
}