#include <bits/stdc++.h>
using namespace std;
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int maxx = 0;
        vector<int> v(n);

        for (auto &i : v)
            cin >> i;

        for (auto i : v)
            maxx = max(maxx, i);

        if (n % 2 == 0)
            cout << maxx + n / 2 << '\n';
        else
        {
            int flag = 0;
            for (int i = 0; i < n; i += 2)
                if (v[i] == maxx)
                {
                    flag = 1;
                    break;
                }

            if (flag)
                cout << maxx + (n + 1) / 2 << '\n';
            else
                cout << maxx + n / 2 << '\n';
        }
    }
    return 0;
}