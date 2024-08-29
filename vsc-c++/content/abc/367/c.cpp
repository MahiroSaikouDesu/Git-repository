#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> P;
const int inf = 0x3f3f3f3f << 1;
const int N = 20;

int a[N], ans[N], n, k;

void dfs(int x, int sum)
{
    if (x > n)
        if (sum % k)
            return;
        else
        {
            for (int i = 1; i <= n; i++)
                cout << ans[i] << ' ';
            cout << '\n';
        }
    else
    {
        for (int i = 1; i <= a[x]; i++)
        {
            ans[x] = i;
            dfs(x + 1, sum + i);
            ans[x] = 0;
        }
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    dfs(1, 0);
    return 0;
}