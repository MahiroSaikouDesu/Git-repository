#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long

void work()
{
    int x, y, k;
    cin >> x >> y >> k;
    int cnt1 = 0, cnt2 = 0;
    if (k % 2)
    {
        cout << x << " " << y << '\n';
        k /= 2;
        for (int i = 1; i <= k; i++)
        {
            cout << x - i << ' ' << y << '\n';
            cout << x + i << ' ' << y << '\n';
        }
    }
    else
    {
        k /= 2;
        for (int i = 1; i <= k; i++)
        {
            cout << x - i << ' ' << y << '\n';
            cout << x + i << ' ' << y << '\n';
        }
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--)
        work();

    return 0;
}