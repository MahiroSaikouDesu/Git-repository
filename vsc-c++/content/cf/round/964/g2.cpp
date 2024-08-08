// 三分(hard version)
#include <bits/stdc++.h>
using namespace std;

int query(int a, int b)
{
    printf("? %d %d\n", a, b);
    fflush(stdout);
    int response;
    cin >> response;
    return response;
}

void solve()
{
    int l = 2, r = 999;
    while (l < r)
    {
        int lm = l + (r - l) / 3, rm = l + (r - l) * 2 / 3;
        int q = query(lm, rm);
        if (q == lm * rm)
        {
            l = rm + 1;
        }
        else if (q == (lm + 1) * (rm + 1))
        {
            r = lm;
        }
        else
        {
            l = lm + 1;
            r = rm;
        }
    }
    printf("! %d\n", l);
    fflush(stdout);
}

signed main()
{
    cin.tie(0)->ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}