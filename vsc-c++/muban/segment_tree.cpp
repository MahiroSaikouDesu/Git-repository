const int inf = 0x3f3f3f3f << 1;
struct node
{
    int mx, l, r, lz;
} tree[N];
void build(int k, int l, int r)
{
    tree[k].l = l;
    tree[k].r = r;
    tree[k].lz = -1;
    if (l == r)
    {
        tree[k].mx = a[l];
        return;
    }
    int mid, lc, rc;
    mid = (l + r) >> 1;
    lc = k << 1;
    rc = lc + 1;
    build(lc, l, mid);
    build(rc, mid + 1, r);
    tree[k].mx = max(tree[lc].mx, tree[rc].mx);
}
void update(int k, int i, int v) // a[i] = v
{
    if (tree[k].l == tree[k].r && tree[k].l == i)
    {
        tree[k].mx = v;
        return;
    }
    int mid, lc, rc;
    mid = (tree[k].l + tree[k].r) >> 1;
    lc = k << 1;
    rc = lc | 1;
    if (i <= mid)
        update(lc, i, v);
    else
        update(rc, i, v);
    tree[k].mx = max(tree[lc].mx, tree[rc], mx);
}
inline void lazy(int k, int v)
{
    tree[k].mx = tree[k].lz = v;
}
void pushdown(int k)
{
    int tmp = k << 1;
    lazy(tmp, tree[k].lz);
    lazy(tmp + 1, tree[k].lz);
    tree[k].lz = -1;
}
void update(int k, int l, int r, int v) // a[l-r] = v;
{
    if (l <= tree[k].l && tree[k].r <= r)
    {
        lazy(k, v);
        return;
    }
    if (tree[k].lz != -1)
        pushdown(k);
    int mid, lc, rc;
    mid = (tree[k].l + tree[k].r) >> 1;
    lc = k << 1;
    rc = lc | 1;
    if (l <= mid)
        update(lc, l, r, v);
    if (r > mid)
        update(rc, l, r, v);
    tree[k].mx = max(tree[lc].mx, tree[rc].mx);
}
int query(int k, int l, int r)
{
    if (l <= tree[k].l && tree[k].r <= r)
        return tree[k].mx;
    if (tree[k].lz != -1)
        pushdown(k);
    int mid, lc, rc, Max = -inf;
    mid = (tree[k].l + tree[k].r) >> 1;
    lc = k << 1;
    rc = lc + 1;
    if (l <= mid)
        Max = max(Max, query(lc, l, r));
    if (r > mid)
        Max = max(Max, query(rc, l, r));
    return Max;
}