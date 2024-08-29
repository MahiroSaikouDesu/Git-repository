#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 4e5 + 10, M = 1e6 + 10;

int n, ans;
ll m;
ll a[N];
vector<int> y;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    y.resize(m + 10);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    ll cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        cnt += a[i];
        y[cnt % m]++;
    }
    for (int i = 0; i < m; i++)
    {
        ll now = 1LL * y[i];
        ans += now * (now - 1) / 2;
    }
    cout << ans;
    return 0;
}