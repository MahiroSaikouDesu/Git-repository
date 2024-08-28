#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> Pii;
const int inf = 0x3f3f3f3f << 1;

priority_queue<int> g, c;
int T, n, m, k, w, tmp;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> T;
    while (T--)
    {
        ll ans = 0;
        while (!c.empty())
            c.pop();

        cin >> n >> m >> k;
        cin >> w;
        while (w--)
        {
            cin >> tmp;
            g.push(tmp);
        }

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                // left-up
                int ax = max(1, i - k + 1), ay = max(1, j - k + 1);
                // right-down
                int bx = min(n, i + k - 1), by = min(m, j + k - 1);
                bx -= k - 1, by -= k - 1;
                c.push((bx - ax + 1) * (by - ay + 1));
            }

        while (!g.empty())
        {
            int fg = g.top(), fc = c.top();
            g.pop(), c.pop();
            ans += 1LL * fc * fg;
        }
        cout << ans << '\n';
    }
    return 0;
}