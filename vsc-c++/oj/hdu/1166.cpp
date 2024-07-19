#include <bits/stdc++.h>
using namespace std;
inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = (x << 1) + (x << 3) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}

#define ll long long
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;
const int N = 5e5, inf = 0x3f3f3f3f << 1;

struct node
{
    int sum, l, r, lz;
} tree[N];
void build(int k, int l, int r)
{
    tree[k].l = l;
    tree[k].r = r;
    tree[k].lz = -1;
    if (l == r)
    {
        tree[k].sum = read();
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
void update(int k, int i, int v) // a[i] = v
{
    if (tree[k].l == tree[k].r && tree[k].l == i)
    {
        tree[k].sum += v;
        return;
    }
    int mid, lc, rc;
    mid = (tree[k].l + tree[k].r) >> 1;
    lc = k << 1;
    rc = lc + 1;
    if (i <= mid)
        update(lc, i, v);
    else
        update(rc, i, v);
    tree[k].sum = tree[lc].sum + tree[rc].sum;
}
int query(int k, int l, int r)
{
    if (l <= tree[k].l && tree[k].r <= r)
        return tree[k].sum;
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
    int T = read(), kas = 0;
    string op;
    while (T--)
    {
        int n = read();
        build(1, 1, n);
        kas++;
        cout << "Case " << kas << ":\n";
        while (cin >> op && op != "End")
        {
            int p = read(), q = read();

            if (op == "Query")
                cout << query(1, p, q) << '\n';
            else if (op == "Add")
                update(1, p, q);
            else
                update(1, p, -q);
        }
    }
    return 0;
}