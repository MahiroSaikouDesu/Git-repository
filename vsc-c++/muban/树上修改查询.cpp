struct edge
{
    int u, v, c;
    edge() {}
    edge(int a, int b, int d) : u(a), v(b), c(d) {}
} e[N];
int head[N], to[N << 1], nxt[N << 1], tt;
int fa[N], son[N], dep[N], sz[N], w[N];
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
inline void lazy(int k, int v)
{
    tr[k].add += v;
    tr[k].sum += v * (tr[k].r - tr[k].l + 1);
}
inline void pushdown(int k)
{
    if (tr[k].add == 0)
        return;
    int tmp = k << 1;
    lazy(tmp, tr[k].add);
    lazy(tmp | 1, tr[k].add);
    tr[k].add = 0;
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
    pushdown(u);
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
    if (dep[u] < dep[v]) // dep[u] >= dep[v]
        swap(u, v);
    res += query(1, id[v], id[u]);
    return res;
}
void update(int k, int l, int r, int v)
{
    if (l <= tr[k].l && tr[k].r <= r)
    {
        lazy(k, v);
        return;
    }
    pushdown(k);
    int mid, lc, rc;
    mid = (tr[k].l + tr[k].r) >> 1;
    lc = k << 1;
    rc = lc | 1;
    if (l <= mid)
        update(lc, l, r, v);
    if (r > mid)
        update(rc, l, r, v);
    pushup(k);
}
void update_path(int u, int v, int val)
{
    while (top[u] != top[v])
    {
        if (dep[top[u]] < dep[top[v]])
            swap(u, v);
        update(1, id[top[u]], id[u], val);
        u = fa[top[u]];
    }
    if (dep[u] < dep[v])
        swap(u, v);
    update(1, id[v], id[u], val);
}
void add(int u, int v, int val)
{
    w[tt] = val;
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
    top[u] = t, id[u] = ++cnt, nw[cnt] = w[u];
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
void init()
{
    tt = 0;
    memset(head, -1, sizeof head);
}