#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> Pii;
const int inf = 1e9 + 7;

ll c(int a, int b)
{
    a = min(a, b - a);
    ll ans = 1;
    for (int i = b; i > b - a; i--)
        ans *= i;
    for (int i = a; i; i--)
        ans /= i;
    return ans;
}

int work()
{
    int n, k, cnt = 0;
    ll res = 0;
    cin >> n >> k;
    int tmp = (k + 1) >> 1;
    tmp--;
    for (int i = 1; i <= n; i++)
    {
        int t;
        cin >> t;
        cnt += t ? 0 : 1;
    }
    for (int i = tmp + 1; i <= n - tmp; i++)
    {
        res += i > cnt ? c(tmp, i - 1) * c(tmp, n - i) : 0;
        res %= inf;
    }
    return (int)(res % inf);
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--)
        cout << work() % inf << "\n";
    return 0;
}