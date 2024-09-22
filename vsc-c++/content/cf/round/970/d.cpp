#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;

int fa[N], ans[N], p[N], col[N];
int fafind(int x)
{
    if (x == fa[x])
        return x;
    return fa[x] = fafind(fa[x]);
}
void uni(int x, int y)
{
    x = fafind(x);
    y = fafind(y);
    if (x != y)
        fa[x] = fa[y];
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t, n;
    string scol;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            fa[i] = i;
        memset(ans, 0, sizeof ans);
        for (int i = 1; i <= n; i++)
            cin >> p[i];

        cin >> scol;
        for (int i = 1; i <= n; i++)
            col[i] = scol[i - 1] == '0' ? 0 : 1;

        for (int i = 1; i <= n; i++)
            uni(p[i], i);
        for (int i = 1; i <= n; i++)
            fafind(i);

        for (int i = 1; i <= n; i++)
            if (!col[i])
                ans[fafind(i)]++;

        for (int i = 1; i <= n; i++)
            cout << ans[fafind(i)] << " \n"[i == n];
    }
    return 0;
}