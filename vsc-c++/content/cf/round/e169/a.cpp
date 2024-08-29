#include <bits/stdc++.h>
using namespace std;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        int n, a1, a2;
        cin >> n;
        if (n > 2)
        {
            for (int i = 1; i <= n; i++)
                cin >> a1;
            cout << "NO\n";
        }
        else
        {
            cin >> a1 >> a2;
            if (a1 > a2)
                swap(a1, a2);
            if (a1 + 1 == a2)
                cout << "NO\n";
            else
                cout << "YES\n";
        }
    }
    return 0;
}