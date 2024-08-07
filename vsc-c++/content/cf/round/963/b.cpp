#include <bits/stdc++.h>
using namespace std;
#define ll int
const int inf = 1e9;

ll work()
{
    ll n, t, flagJI = 0, flagOU = 0, maxji = 0, ans = 0, maxou = 0, qsize = 0;
    cin >> n;
    priority_queue<ll, vector<ll>, greater<ll>> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> t;
        if (t % 2)
            flagJI = 1, maxji = max(maxji, t);
        else
            flagOU = 1, maxou = max(maxou, t), q.push(t);
    }
    if (flagJI ^ flagOU)
        return 0;
    while (!q.empty())
    {
        ll f = q.top();
        ans++;
        if (f < maxji)
            q.pop();
        else
        {
            maxji += maxou;
            continue;
        }
        maxji += f;
        if (maxji >= inf)
        {
            ans += q.size();
            break;
        }
    }

    return ans + qsize;
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