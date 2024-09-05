#include <bits/stdc++.h>
using namespace std;
const int N = 110;

int a[N], T, n, maxx, tmp;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> n;
        maxx = 0;
        for (int i = 1; i <= n; i++)
            a[i] = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> tmp;
            a[tmp]++;
            maxx = max(maxx, a[tmp]);
        }
        cout << n - maxx << '\n';
    }
    return 0;
}