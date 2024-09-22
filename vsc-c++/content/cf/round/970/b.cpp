#include <bits/stdc++.h>
using namespace std;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t, n;
    string s;
    cin >> t;
    while (t--)
    {
        cin >> n >> s;
        int nq = sqrt(n), cnt = 0;
        if (nq * nq != n)
        {
            cout << "No\n";
        }
        else
        {
            for (auto i : s)
                if (i == '0')
                    cnt++;
            int b = max(0, nq - 2);
            b *= b;
            cout << (b == cnt ? "Yes\n" : "No\n");
        }
    }
    return 0;
}