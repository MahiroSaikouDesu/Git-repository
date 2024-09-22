#include <bits/stdc++.h>
using namespace std;

void prin(int a)
{
    cout << (a ? "Yes\n" : "No\n");
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        int a, b;
        cin >> a >> b;
        if (b % 2)
        {
            if (a >= 2)
                a -= 2;
            else
            {
                prin(0);
                continue;
            }
        }
        prin(a % 2 ? 0 : 1);
    }
    return 0;
}