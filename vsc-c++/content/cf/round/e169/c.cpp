#include <bits/stdc++.h>
using namespace std;
#define ll long long

int T, n, k, tmp, a, b;
ll ans;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> n >> k;
        priority_queue<int> q;
        for (int i = 1; i <= n; i++)
        {
            cin >> tmp;
            q.push(tmp);
        }
        ans = 0;
        while (q.size() >= 2)
        {
            a = q.top();
            q.pop();
            b = q.top();
            q.pop();
            ans += (ll)(a - b - min(k, a - b));
            k -= min(k, a - b);
        }
        if (q.size())
            ans += q.top();
        cout << ans << '\n';
    }
    return 0;
}