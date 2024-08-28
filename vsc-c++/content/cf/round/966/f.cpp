#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> Pii;
const int inf = 0x3f3f3f3f;
const int N = 1e3 + 10, M = 1e2 + 10;

int dp[N][M], a[N][2], n, fen;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n >> fen;
        for (int i = 1; i <= n; i++)
            cin >> a[i][0] >> a[i][1];
        memset(dp, 0x3f, sizeof dp);
        for (int i = 0; i <= n; i++)
            dp[i][0] = 0;

        for (int i = 1; i <= n; i++)
        {
            int limit1 = a[i][0] + a[i][1], cnt = 0;
            for (int k = 1; k <= limit1; k++)
            {
                if (a[i][0] > a[i][1])
                    swap(a[i][0], a[i][1]);
                cnt += a[i][0];
                a[i][1]--;
                for (int j = k; j <= fen; j++)
                    dp[i][j] = min(min(dp[i - 1][j], dp[i][j]), dp[i - 1][j - k] + cnt);
            }
        }
        cout << (dp[n][fen] == inf ? -1 : dp[n][fen]) << '\n';
    }
    return 0;
}