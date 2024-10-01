#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> P;
const int inf = 0x3f3f3f3f << 1;
const int N = 2e5 + 10;
bool mp[N][2];

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t, n, a, b;
    ll ans;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<P> v(n);
        for (auto &i : v)
        {
            cin >> a >> b;
            i = {a, b};
        }

        vector<vector<bool>> mp(n + 1, vector<bool>(2));
        for (auto i : v)
            mp[i.first][i.second] = true;

        ans = 0;
        for (int i = 0; i <= n; i++)
        {
            if (mp[i][0] && mp[i][1])
                ans += n - 2;

            if (i - 2 >= 0 && mp[i][0] && mp[i - 2][0] && mp[i - 1][1])
                ans++;
            if (i - 2 >= 0 && mp[i][1] && mp[i - 2][1] && mp[i - 1][0])
                ans++;
        }
        cout << ans << '\n';
    }
    return 0;
}