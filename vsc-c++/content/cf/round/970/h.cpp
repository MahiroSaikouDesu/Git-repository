#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> P;
const int N = 1e5 + 10;
#define int long long
int ans[N], a[N], s[N];

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t, n, q, x, limit, tmp;
    cin >> t;
    while (t--)
    {
        cin >> n >> q;
        for (int i = 0; i <= n; i++)
            s[i] = 0;
        for (int i = 0; i <= n; i++)
            ans[i] = 0;

        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            s[a[i]]++;
        for (int i = 1; i <= n; i++)
            s[i] += s[i - 1];

        limit = (n + (n % 2 ? 1 : 2)) / 2;

        int l, r, mid, res, cnt;
        for (int i = 1; i <= n; i++)
        {
            cnt = l = 0, r = i - 1;

            while (l <= r)
            {
                mid = (l + r) >> 1, cnt = 0;
                for (int j = 0; j <= n; j += i)
                    cnt += (j + mid > n ? s[n] : s[j + mid]) - (j == 0 ? 0 : s[j - 1]);
                if (cnt >= limit)
                    res = mid, r = mid - 1;
                else
                    l = mid + 1;
            }
            ans[i] = res;
        }
        while (q--)
        {
            cin >> res;
            cout << ans[res] << ' ';
        }
        cout << '\n';
    }
    return 0;
}