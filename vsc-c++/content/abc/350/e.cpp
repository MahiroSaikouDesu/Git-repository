#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;

int n, a, x, y;
map<ll, double> f;

double solve(int n)
{
    if (n == 0)
        return 0;
    if (f[n] != 0)
        return f[n];
    double fir = x + solve(n / a);
    double sec = (6.0 * y + solve(n / 2) + solve(n / 3) + solve(n / 4) + solve(n / 5) + solve(n / 6)) / 5.0;
    // double sec = 6.0 * y / 5.0 + solve(n / 2) / 5.0 + solve(n / 3) / 5.0 + solve(n / 4) / 5.0 + solve(n / 5) / 5.0 + solve(n / 6) / 5.0;
    // double sec = 1.2 * (y + 1.0 / 6 * (solve(n / 2) + solve(n / 3) + solve(n / 4) + solve(n / 5) + solve(n / 6)));
    return f[n] = min(fir, sec);
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> a >> x >> y;
    cout << fixed << setprecision(10) << solve(n);
    return 0;
}