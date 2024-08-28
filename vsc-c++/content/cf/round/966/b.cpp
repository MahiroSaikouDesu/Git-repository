#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;

int flag[N], use[N], T, a[N], n, ans;

void add(int x)
{
    if (x > 1 && !use[x - 1])
        flag[x - 1] = 1;
    if (x < n && !use[x + 1])
        flag[x + 1] = 1;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            flag[i] = use[i] = 0;
        }
        ans = use[a[1]] = 1;
        add(a[1]);

        for (int i = 2; i <= n; i++)
        {
            if (!flag[a[i]])
            {
                ans = 0;
                break;
            }
            flag[a[i]] = 0;
            use[a[i]] = 1;
            add(a[i]);
        }
        cout << (ans ? "YES\n" : "NO\n");
    }
    return 0;
}