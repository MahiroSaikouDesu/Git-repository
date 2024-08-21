#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> Pii;
const int inf = 0x3f3f3f3f;
const int N = 1e5 + 10, M = 20, P = N * M;

int n, m, a, b, ans;
struct node
{
    int v, nxt;
} e[P];
struct node2
{
    int cap;
    vector<int> match;
} planet[M];
int idx, head[N], vis[M];
void add(int a, int b)
{
    e[++idx] = {b, head[a]};
    head[a] = idx;
}
bool dfs(int u);
bool dfs2(int v)
{
    for (auto i : planet[v].match)
        if (dfs(i))
            return 1;
    return 0;
}
bool dfs(int u)
{
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v;
        if (vis[v])
            continue;
        vis[v] = 1;
        if (planet[v].cap > planet[v].match.size() || dfs2(v))
        {
            planet[v].match.push_back(u);
            return 1;
        }
    }
    return 0;
}
int work()
{
    for (int i = 1; i <= n; i++)
    {
        memset(vis, 0, sizeof vis);
        if (dfs(i))
            ans++;
    }
    return ans;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    while (cin >> n >> m)
    {
        ans = 0, idx = 0;
        memset(head, 0, sizeof head);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                cin >> a;
                if (a)
                    add(i, j);
            }
        for (int i = 1; i <= m; i++)
        {
            cin >> planet[i].cap;
            planet[i].match.clear();
        }

        bool flag = true;
        for (int i = 1; i <= n; i++)
        {
            memset(vis, 0, sizeof vis);
            if (!dfs(i))
            {
                flag = false;
                break;
            }
        }
        if (flag)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}