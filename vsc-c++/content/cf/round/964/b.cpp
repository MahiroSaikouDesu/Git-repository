#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
int v[5][5];
int a[5], b[5], res;
P tmp[5];

void dfs(int cnt)
{
    if (cnt >= 2)
    {
        int t1 = 0, t2 = 0;
        for (int j = 1; j <= 2; j++)
        {
            if (tmp[j].first > tmp[j].second)
                t1++;
            else if (tmp[j].first < tmp[j].second)
                t2++;
        }
        if (t1 > t2)
            res++;
        return;
    }
    for (int i = 1; i <= 2; i++)
        if (!v[1][i])
            for (int j = 1; j <= 2; j++)
            {
                if (v[2][j])
                    continue;
                v[1][i] = v[2][j] = 1;
                tmp[i] = {a[i], b[j]};
                dfs(cnt + 1);
                tmp[i] = {0, 0};
                v[1][i] = v[2][j] = 0;
            }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        res = 0;
        cin >> a[1] >> a[2] >> b[1] >> b[2];
        for (int i = 1; i <= 2; i++)
            for (int j = 1; j <= 2; j++)
                v[i][j] = 0;
        dfs(0);
        cout << res << '\n';
    }
    return 0;
}