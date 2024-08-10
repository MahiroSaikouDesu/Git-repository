#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
vector<int> val(N), wei(N), dp(N);
void work()
{
    int v, n;
    cin >> n >> v;
    for (int i = 0; i <= v; i++)
        dp[i] = 0;
    for (int i = 1; i <= n; i++)
        cin >> val[i];
    for (int i = 1; i <= n; i++)
        cin >> wei[i];
    for (int i = 1; i <= n; i++)          // bone
        for (int j = v; j >= wei[i]; j--) // size
            if (j - wei[i] >= 0)
                dp[j] = max(dp[j], val[i] + dp[j - wei[i]]);
    cout << dp[v] << '\n';
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--)
        work();
    return 0;
}