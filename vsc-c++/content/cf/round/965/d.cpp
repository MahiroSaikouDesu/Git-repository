#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> P;
const int inf = 0x3f3f3f3f << 1;
const int N = 2e5 + 10;

int u, v, n, m, T, sum[N], step[N];
vector<int> edge[N];

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            step[i] = inf, sum[i] = 0, edge[i].clear();
        for (int i = 1; i <= n; i++)
            edge[i].push_back(i + 1);
        while (m--)
        {
            cin >> u >> v;
            edge[u].push_back(v);
        }

        queue<int> q;
        q.push(1);
        step[1] = 1;
        while (!q.empty())
        {
            int f = q.front();
            q.pop();
            for (auto v : edge[f])
                if (step[f] + 1 < step[v])
                    step[v] = step[f] + 1, q.push(v);
        }

        for (int i = 1; i <= n; i++)
            for (auto v : edge[i])
                if (i + 1 <= v - step[i])
                    sum[i + 1]++, sum[v - step[i]]--;

        for (int i = 1; i <= n; i++)
            sum[i] += sum[i - 1];
        for (int i = 1; i < n; i++)
            cout << (sum[i] == 0);
        cout << '\n';
    }
    return 0;
}