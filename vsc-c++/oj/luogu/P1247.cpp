#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
#define int long long
int a[N], n;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int s = 0, ans1, ans2;
    for (int i = 1; i <= n; i++)
        s ^= a[i];

    if (s)
    {
        for (int i = 1; i <= n; i++)
            if ((a[i] ^ s) < a[i])
            {
                ans1 = a[i] - (a[i] ^ s);
                ans2 = i;
                a[i] ^= s;
                break;
            }
        cout << ans1 << ' ' << ans2 << '\n';
        for (int i = 1; i <= n; i++)
            cout << a[i] << ' ';
    }
    else
        cout << "lose\n";

    return 0;
}