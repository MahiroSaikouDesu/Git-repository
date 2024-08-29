#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        P a, b;
        cin >> a.first >> a.second >> b.first >> b.second;
        if (a.second < b.first || b.second < a.first)
        {
            cout << 1 << '\n';
        }
        else
        {
            cout << min(a.second, b.second) - max(a.first, b.first) + (a.first != b.first) + (a.second != b.second) << "\n";
        }
    }
    return 0;
}