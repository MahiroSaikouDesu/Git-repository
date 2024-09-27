#include <bits/stdc++.h>
using namespace std;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<string> s(n);
        for (int i = n - 1; i >= 0; i--)
            cin >> s[i];
        for (int i = 0; i < n; i++)
            cout << s[i].find('#') + 1 << " \n"[i == n - 1];
    }
    return 0;
}