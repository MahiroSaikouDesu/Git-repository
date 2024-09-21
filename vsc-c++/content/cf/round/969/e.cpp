#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5 + 10;

int n, a;
int c1[N], c2[N], fa[N], dep[N], len[N];
ll w;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n >> w;
        for (int i = 1; i <= n; i++)
            c1[i] = c2[i] = fa[i] = dep[i] = len[i] = 0;
        for (int i = 2; i <= n; i++)
        {
            cin >> fa[i];
            dep[i] = dep[fa[i]] + 1;
        }

        for (int i = 1, x, y; i <= n; i++)
        {
            x = i, y = i == n ? 1 : i + 1;
            while (x != y)
            {
                if (dep[x] < dep[y])
                    swap(x, y);
                (c1[x] ? c2[x] : c1[x]) = i, x = fa[x], ++len[i];
            }
        }

        ll sur = n, sum = 0;
        for (int i = 2; i <= n; i++)
        {
            int x;
            ll ww;
            cin >> x >> ww;
            sum += ww;
            if ((--len[c1[x]]) == 0)
                sur--;
            if ((--len[c2[x]]) == 0)
                sur--;
            cout << sum * 2 + (w - sum) * sur << " \n"[i == n];
        }
    }
    return 0;
}