#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, ll> Pii;
const ll inf = 1e18;
const int N = 300, M = 2e4 + 10;

int n, m, t1, t2, Q, flag, del[N];
ll e[N][N], t3;
struct node
{
    int op, a, b;
    ll ans;
} q[M];

void add(int i)
{
    del[i]--;
    if (del[i])
        return;
    for (int j = 1; j <= n; j++)
        for (int k = 1; k <= n; k++) // k
            if (!del[j] && !del[k])
                e[i][j] = e[j][i] = min(e[i][j], e[i][k] + e[k][j]);
    for (int j = 1; j <= n; j++)
        for (int k = 1; k <= n; k++) // k
            if (!del[j] && !del[k])
                e[j][k] = e[k][j] = min(e[j][k], e[j][i] + e[i][k]);
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            e[i][j] = i == j ? 0LL : inf;
    for (int i = 1; i <= m; i++)
    {
        cin >> t1 >> t2 >> t3;
        e[t2][t1] = e[t1][t2] = min(t3, e[t1][t2]);
    }

    int op, x, y;
    cin >> Q;
    for (int i = 1; i <= Q; i++)
    {
        cin >> q[i].op >> q[i].a;
        if (q[i].op == 2)
            cin >> q[i].b;
        else
            del[q[i].a]++;
    }

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (e[i][j] > e[i][k] + e[k][j] && !del[i] && !del[j] && !del[k])
                    e[i][j] = e[i][k] + e[k][j];

    for (int i = Q; i >= 1; i--)
    {
        if (q[i].op == 1)
            add(q[i].a);
        else
            q[i].ans = e[q[i].a][q[i].b] == inf ? -1 : e[q[i].a][q[i].b];
    }
    for (int i = 1; i <= Q; i++)
        if (q[i].op == 2)
            cout << q[i].ans << '\n';
    return 0;
}