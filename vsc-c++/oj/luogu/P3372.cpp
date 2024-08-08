#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
typedef pair<int, int> Pii;
const int inf = 1e18;
const int N = 1e5 + 10;

int n, m, a[N];
struct node
{
    int sum, l, r, lz;
} tree[N << 3];
void build(int k, int l, int r)
{
    tree[k].l = l;
    tree[k].r = r;
    tree[k].lz = 0;
    if (l == r)
    {
        tree[k].sum = a[l];
        return;
    }
    int mid, lc, rc;
    mid = (l + r) >> 1;
    lc = k << 1;
    rc = lc | 1;
    build(lc, l, mid);
    build(rc, mid + 1, r);
    tree[k].sum = tree[lc].sum + tree[rc].sum;
}
inline void lazy(int k, int v)
{
    tree[k].lz += v;
    tree[k].sum += v * (tree[k].r - tree[k].l + 1);
}
void pushdown(int k)
{
    int tmp = k << 1;
    lazy(tmp, tree[k].lz);
    lazy(tmp + 1, tree[k].lz);
    tree[k].lz = 0;
}
void update(int k, int l, int r, int v) // a[l-r] = v;
{
    if (l <= tree[k].l && tree[k].r <= r)
    {
        lazy(k, v);
        return;
    }
    if (tree[k].lz)
        pushdown(k);
    int mid, lc, rc;
    mid = (tree[k].l + tree[k].r) >> 1;
    lc = k << 1;
    rc = lc | 1;
    if (l <= mid)
        update(lc, l, r, v);
    if (r > mid)
        update(rc, l, r, v);
    tree[k].sum = tree[lc].sum + tree[rc].sum;
}
int query(int k, int l, int r)
{
    if (l <= tree[k].l && tree[k].r <= r)
        return tree[k].sum;
    if (tree[k].lz)
        pushdown(k);
    int mid, lc, rc, sum = 0;
    mid = (tree[k].l + tree[k].r) >> 1;
    lc = k << 1;
    rc = lc + 1;
    if (l <= mid)
        sum += query(lc, l, r);
    if (r > mid)
        sum += query(rc, l, r);
    return sum;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    build(1, 1, n);
    int op, x, y, k;
    while (m--)
    {
        cin >> op >> x >> y;
        if (op == 1)
        {
            cin >> k;
            update(1, x, y, k);
        }
        else
            cout << query(1, x, y) << "\n";
    }
    return 0;
}