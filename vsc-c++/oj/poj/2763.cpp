#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;
#define ll int
const int N = 1e5 + 10;

struct edge
{
    int u, v, c;
    edge() {}
    edge(int a, int b, int d) : u(a), v(b), c(d) {}
};

edge e[N];
int head[N], to[N << 1], nxt[N << 1], tt;
int n, q, s, root, mxs;
int fa[N], son[N], dep[N], sz[N];
int top[N], id[N], nw[N], cnt;
struct tree
{
    int l, r;
    ll add, sum;
} tr[N << 2];
inline void pushup(int u)
{
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}
void build(int k, int l, int r)
{
    tr[k].l = l;
    tr[k].r = r;
    tr[k].add = 0;
    if (l == r)
    {
        tr[k].sum = nw[l];
        return;
    }
    int mid, lc, rc;
    mid = (l + r) >> 1;
    lc = k << 1;
    rc = lc | 1;
    build(lc, l, mid), build(rc, mid + 1, r);
    pushup(k);
}
ll query(int u, int l, int r)
{
    if (l <= tr[u].l && tr[u].r <= r)
        return tr[u].sum;

    ll res = 0;

    int mid = (tr[u].l + tr[u].r) >> 1;
    if (l <= mid)
        res += query(u << 1, l, r);
    if (mid < r)
        res += query(u << 1 | 1, l, r);
    return res;
}
ll query_path(int u, int v)
{
    ll res = 0;
    while (top[u] != top[v])
    {
        if (dep[top[u]] < dep[top[v]])
            swap(u, v);
        res += query(1, id[top[u]], id[u]);
        u = fa[top[u]];
    }

    if (u == v)
        return res;

    if (dep[u] < dep[v]) // dep[u] >= dep[v]
        swap(u, v);
    res += query(1, id[son[v]], id[u]);

    return res;
}
void update(int k, int l, int r, int v)
{
    if (l <= tr[k].l && tr[k].r <= r)
    {
        tr[k].sum = v;
        return;
    }
    int mid = (tr[k].l + tr[k].r) >> 1;
    if (l <= mid)
        update(k << 1, l, r, v);
    else
        update(k << 1 | 1, l, r, v);
    pushup(k);
}
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
    top[u] = t, id[u] = ++cnt;
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

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    memset(head, -1, sizeof head);

    cin >> n >> q >> s;
    int a, b, val, op;
    for (int i = 1; i < n; i++)
    {
        cin >> a >> b >> val;
        add(a, b);
        add(b, a);
        e[i].u = a, e[i].v = b, e[i].c = val;
    }
    dfs1(1, 1);
    dfs2(1, 1);

    for (int i = 1; i < n; i++)
    {
        if (dep[e[i].u] < dep[e[i].v])
            swap(e[i].u, e[i].v);
        nw[id[e[i].u]] = e[i].c;
    }
    build(1, 1, n);

    while (q--)
    {
        cin >> op;
        if (op == 0)
        {
            cin >> a;
            cout << query_path(s, a) << '\n';
            s = a;
        }
        else
        {
            cin >> a >> val;
            update(1, id[e[a].u], id[e[a].u], val);
        }
    }
    return 0;
}