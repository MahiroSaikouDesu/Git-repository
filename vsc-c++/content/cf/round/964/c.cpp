#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> Pii;

int work()
{
    int n, s, m, t1, t2;
    cin >> n >> s >> m;
    vector<Pii> mase(n + 10);
    for (int i = 1; i <= n; i++)
    {
        cin >> t1 >> t2;
        mase[i] = {t1, t2};
    }
    if (m - mase[n].second >= s)
        return 1;
    int last = 0;
    for (int i = 1; i <= n; i++)
    {
        if (mase[i].first - last >= s)
            return 1;
        else
            last = mase[i].second;
    }
    return 0;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--)
        if (work())
            cout << "YES\n";
        else
            cout << "NO\n";
    return 0;
}