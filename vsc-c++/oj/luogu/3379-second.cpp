#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;
const int N = 5e5 + 10;

int n, m, s;
struct edge
{
    int u, v, c;
} e[N];
int head[N], to[N << 1], nxt[N << 1], tt;
int fa[N], son[N], dep[N], sz[N];
int top[N];
void add(int u, int v)
{
    to[tt] = v;
    nxt[tt] = head[u];
    head[u] = tt;
    tt++;
}
void dfs1(int u, int father) // fa , dep , son || IJi
{
    fa[u] = father, dep[u] = dep[father] + 1, sz[u] = 1;
    for (int i = head[u]; i != -1; i = nxt[i])
    {
        int v = to[i];
        if (v == father)
            continue;
        dfs1(v, u);
        sz[u] += sz[v];
        if (sz[son[u]] < sz[v])
            son[u] = v;
    }
}
void dfs2(int u, int t) // top , id , nw || HaKaTTe
{
    top[u] = t;
    if (!son[u])
        return;
    dfs2(son[u], t);
    for (int i = head[u]; i != -1; i = nxt[i])
    {
        int v = to[i];
        if (v != fa[u] && v != son[u])
            dfs2(v, v);
    }
}
int lca(int u, int v)
{
    while (top[u] != top[v])
    {
        if (dep[top[u]] < dep[top[v]])
            swap(u, v);
        u = fa[top[u]];
    }
    return dep[u] < dep[v] ? u : v;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m >> s;
    memset(head, -1, sizeof head);
    int x, y;
    for (int i = 1; i < n; i++)
    {
        cin >> x >> y;
        add(x, y);
        add(y, x);
    }
    dfs1(s, s);
    dfs2(s, s);
    while (m--)
    {
        cin >> x >> y;
        if (x == y)
            cout << x << '\n';
        else
            cout << lca(x, y) << '\n';
    }
    return 0;
}