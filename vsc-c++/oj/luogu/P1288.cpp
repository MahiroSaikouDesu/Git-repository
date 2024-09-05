#include <bits/stdc++.h>
using namespace std;
const int N = 100;
int a[N];

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, flag = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        if (!a[i])
        {
            if (i % 2 == 0)
                flag = 1;
            break;
        }

    for (int i = n; i >= 1; i--)
        if (!a[i])
        {
            if ((n - i + 1) % 2 == 0)
                flag = 1;
            break;
        }
    cout << (flag ? "YES" : "NO");
    return 0;
}