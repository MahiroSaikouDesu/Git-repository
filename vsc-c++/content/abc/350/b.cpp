#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
map<int, int> a;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= q; i++)
    {
        int now;
        cin >> now;
        a[now]++;
    }
    int ans = n;
    for (auto it = a.begin(); it != a.end(); it++)
    {
        PII now = *it;
        if (now.second % 2)
            ans--;
    }
    cout << ans;
    return 0;
}