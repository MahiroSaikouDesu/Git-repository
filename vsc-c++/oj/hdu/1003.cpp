#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> Pii;
const int inf = (1 << 30) + 1;
const int N = 1e5+10;
int dp[N];

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T, n, kas = 0;
    cin >> T;
    while(T--)
    {
        memset(dp, 0, sizeof dp);
        cin >> n;
        for (int i = 1; i <= n;i++)
            cin >> dp[i];
        int l = 1, r = 1, maxx = dp[1], pos = 1;
        for (int i = 2; i <= n; i++)
        {
            if(dp[i-1]>=0)
                dp[i] += dp[i - 1];
            else
                pos = i;
            if(dp[i]>maxx)
            {
                maxx = dp[i];
                l = pos;
                r = i;
            }
        }
        kas++;
        cout << "Case " << kas << ":\n";
        cout << maxx << ' ' << l << ' ' << r << "\n\n";
    }
    return 0;
}