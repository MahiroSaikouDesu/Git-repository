#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> P;
const int inf = 0x3f3f3f3f << 1;
const int N = 1e5 + 10;

struct node
{
    int v, i1, i2;
};
int n, m, T, u, v, i1, i2, t1, t2, t3, tx, ty, vis[N], ans, used[N];
vector<node> edge[N];

bool check(int tim)
{
    if (tim <= tx || tim > ty)
        return 0;
    else
        return 1;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> T;
    while (T--)
    {
        ans = inf;
        cin >> n >> m >> t1 >> t2 >> t3;
        tx = t1 - t3, ty = t1 - t2;
        for (int i = 1; i <= n; i++)
            vis[i] = 0, used[i] = inf, edge[i].clear();

        for (int i = 1; i <= m; i++)
        {
            cin >> u >> v >> i1 >> i2;
            edge[u].push_back({v, i1, i2});
            edge[v].push_back({u, i1, i2});
        }

        priority_queue<P, vector<P>, greater<P>> q;
        q.push({0, n});
        while (!q.empty())
        {
            P f = q.top();
            q.pop();
            if (vis[f.second])
                continue;
            vis[f.second] = 1;

            if (f.first > t1)
                break;
            if (f.second == 1)
            {
                ans = f.first;
                break;
            }

            for (auto i : edge[f.second])
            {
                if (vis[i.v])
                    continue;
                int diss = f.first + i.i2;
                if (f.first + i.i1 <= tx)
                    diss = f.first + i.i1;
                else
                    diss = min(diss, max(f.first, ty) + i.i1);

                if (diss < used[i.v])
                {
                    used[i.v] = diss;
                    q.push({diss, i.v});
                }
            }
        }

        cout << (ans == inf ? -1 : t1 - ans) << '\n';
    }
    return 0;
}