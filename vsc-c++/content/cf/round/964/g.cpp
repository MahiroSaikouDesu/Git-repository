#include <bits/stdc++.h>
using namespace std;

void work()
{
    int l = 2, r = 999;
    while (1)
    {
        int mid = (l + r) >> 1;
        cout << "? " << mid - 1 << ' ' << mid << '\n';
        cout.flush();
        int now, tmp = (mid - 1) * (mid + 1);
        cin >> now;
        if (tmp == now)
        {
            cout << "! " << mid << '\n';
            cout.flush();
            return;
        }
        if (now < tmp)
        {
            l = mid + 1;
        }
        else
            r = mid - 1;
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