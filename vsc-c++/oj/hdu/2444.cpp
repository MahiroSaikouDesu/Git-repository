#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> Pii;
const int inf = 0x3f3f3f3f;
const int N = 210, M = N * N;

int n, m, a, b, ans;
struct node
{
    int v, nxt;
} e[M];
int idx, head[N], vis[N], match[N], color[N];
void add(int a, int b)
{
    e[++idx] = {b, head[a]};
    head[a] = idx;
}
bool dfs(int u)
{
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v;
        if (vis[v])
            continue;
        vis[v] = 1;
        if (!match[v] || dfs(match[v]))
        {
            match[v] = u;
            return 1;
        }
    }
    return 0;
}
int hungarian()
{
    for (int i = 1; i <= n; i++)
    {
        if (color[i] != 1)
            continue;
        memset(vis, 0, sizeof vis);
        if (dfs(i))
            ans++;
    }
    return ans;
}

bool dfsc(int x, int c)
{
    color[x] = c;
    for (int i = head[x]; i; i = e[i].nxt)
    {
        int v = e[i].v;
        if (color[v] == color[x])
            return 0;
        if (!color[v] && !dfsc(v, -c))
            return 0;
    }
    return 1;
}
bool solve()
{
    for (int i = 1; i <= n; i++)
        if (!color[i])
            if (!dfsc(i, 1))
                return 0;
    return 1;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    while (cin >> n >> m)
    {
        idx = ans = 0;
        for (int i = 1; i <= n; i++)
            color[i] = match[i] = head[i] = 0;
        while (m--)
        {
            cin >> a >> b;
            add(a, b);
            add(b, a);
        }
        if (n == 1 || !solve())
        {
            cout << "No\n";
            continue;
        }

        cout << hungarian() << '\n';
    }
    return 0;
}