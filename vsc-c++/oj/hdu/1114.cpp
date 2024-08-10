#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f << 1;
const int N = 1e4 + 10;
vector<int> val(N), wei(N), dp(N);
void work()
{
    int emptyWei, fullWei, n;
    cin >> emptyWei >> fullWei >> n;
    int v = fullWei - emptyWei;
    for (int i = 0; i <= v; i++)
        dp[i] = inf;
    for (int i = 1; i <= n; i++)
        cin >> val[i] >> wei[i];
    dp[0] = 0;
    for (int i = 1; i <= n; i++)          // bone
        for (int j = wei[i]; j <= v; j++) // size
            dp[j] = min(dp[j], val[i] + dp[j - wei[i]]);
    if (dp[v] == inf)
        cout << "This is impossible.\n";
    else
        cout << "The minimum amount of money in the piggy-bank is " << dp[v] << ".\n";
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