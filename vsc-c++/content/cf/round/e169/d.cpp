#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;

int T, q, n, x, y;
const string col[7] = {"BG", "BR", "BY", "GR", "GY", "RY"};

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> n >> q;
        vector<int> ci(n);
        vector<vector<int>> le(n), re(n);
        for (int i = 0; i < n; i++)
        {
            char s[5];
            cin >> s;
            ci[i] = find(col, col + 6, s) - col;
        }

        for (int o = 0; o <= 1; o++)
        {
            vector<int> last(6, -inf);
            for (int i = 0; i < n; i++)
            {
                last[ci[i]] = (o ? n - i - 1 : i);
                (o ? re[n - i - 1] : le[i]) = last;
            }
            reverse(ci.begin(), ci.end());
        }

        while (q--)
        {
            cin >> x >> y;
            x--, y--;
            if (x > y)
                swap(x, y);

            // x <= y
            if (ci[x] + ci[y] == 5)
            {
                int ans = inf;
                for (int i = 0; i < 6; i++)
                    if (i != ci[x] && i != ci[y])
                    {
                        if (le[x][i] != -inf)
                            ans = min(ans, abs(x - le[x][i]) + abs(y - le[x][i]));
                        if (re[x][i] != -inf)
                            ans = min(ans, abs(re[x][i] - x) + abs(re[x][i] - y));
                    }
                if (ans > inf / 2)
                    ans = -1;
                cout << ans << '\n';
            }
            else
                cout << abs(y - x) << '\n';
        }
    }
    return 0;
}