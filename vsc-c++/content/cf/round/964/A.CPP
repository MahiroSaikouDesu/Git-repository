#include <bits/stdc++.h>
using namespace std;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        string a;
        cin >> a;
        int tmp = a[0] - '0' + a[1] - '0';
        cout << tmp << '\n';
    }
    return 0;
}