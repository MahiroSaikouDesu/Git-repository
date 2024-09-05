#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10, MAX = 1e7 + 10;
#define int long long
int T, n, ans, nim[MAX], a, vis[MAX];

void init()
{
    nim[1] = 1;
    int cnt = 1;
    for (int i = 3; i < MAX; i += 2)
        if (!vis[i])
        {
            cnt++;
            for (int j = i; j < MAX; j += (i * 2))
            {
                vis[j] = 1;
                if (!nim[j])
                    nim[j] = cnt;
            }
        }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    init();
    cin >> T;
    while (T--)
    {
        ans = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a, ans ^= nim[a];
        cout << (ans ? "Alice\n" : "Bob\n");
    }
    return 0;
}