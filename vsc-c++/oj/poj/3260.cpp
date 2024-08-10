#include <iostream>
#include <cstring>
using namespace std;
#define ll long long
typedef pair<int, int> Pii;
const int inf = (1 << 30) + 1;
const int N = 110, M = 3e4;
int n, t, maxv, w1, w2;
int v[N], c[N], dppay[M], dpchange[M];
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    memset(dppay, 0x3f, sizeof dppay);
    memset(dpchange, 0x3f, sizeof dpchange);
    int inf = dpchange[0], ans = inf;
    cin >> n >> t;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        maxv = max(maxv, v[i]);
    }
    for (int i = 1; i <= n; i++)
        cin >> c[i];

    // pay mult
    dppay[0] = 0;
    w2 = maxv * maxv;
    w1 = w2 + t;
    for (int i = 1; i <= n; i++)
    {
        if (v[i] * c[i] >= w1) // comple
            for (int j = v[i]; j <= w1; j++)
                dppay[j] = min(dppay[j], dppay[j - v[i]] + 1);
        else // zoneone
        {
            for (int k = 1; c[i] > 0; k <<= 1)
            {
                int p = min(k, c[i]);
                for (int j = w1; j >= v[i] * p; j--)
                    dppay[j] = min(dppay[j], dppay[j - p * v[i]] + p);
                c[i] -= p;
            }
        }
    }
    dpchange[0] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = v[i]; j <= w2; j++)
            dpchange[j] = min(dpchange[j], dpchange[j - v[i]] + 1);
    for (int i = 0; i <= w2; i++)
        ans = min(ans, dpchange[i] + dppay[i + t]);
    if (ans == inf)
        cout << -1;
    else
        cout << ans;
    return 0;
}