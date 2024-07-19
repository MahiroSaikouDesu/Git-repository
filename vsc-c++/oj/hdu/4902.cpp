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
const int N = 2e5 + 10;

// 辗转相除法
int gcd(int a, int b)
{
    if (!b)
        return a;
    else
        return gcd(b, a % b);
}

int n;
const int inf = 0x3f3f3f3f << 1;
struct node
{
    int mx, l, r, lz;
} tree[N << 2];
void pushup(int p)
{
    tree[p].mx = max(tree[p << 1].mx, tree[p << 1 | 1].mx);
    tree[p].lz = (tree[p << 1].lz == tree[p << 1 | 1].lz && tree[p << 1].lz != -1) ? tree[p << 1].lz : -1;
    if (tree[p].lz != -1)
        tree[p].mx = tree[p].lz;
}
void build(int k, int l, int r)
{
    tree[k].l = l;
    tree[k].r = r;
    tree[k].lz = -1;
    if (l == r)
    {
        tree[k].mx = tree[k].lz = read();
        return;
    }
    int mid, lc, rc;
    mid = (l + r) >> 1;
    lc = k << 1;
    rc = lc + 1;
    build(lc, l, mid);
    build(rc, mid + 1, r);
    pushup(k);
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
void update1(int k, int l, int r, int v) // a[l-r] = v;
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
        update1(lc, l, r, v);
    if (r > mid)
        update1(rc, l, r, v);
    pushup(k);
}
void update2(int k, int l, int r, int v) // gcd
{
    if (tree[k].mx <= v)
        return;
    if (tree[k].lz != -1)
    {
        if (l <= tree[k].l && tree[k].r <= r)
        {
            lazy(k, gcd(tree[k].lz, v));
            return;
        }
        else
            pushdown(k);
    }
    int mid, lc, rc;
    mid = (tree[k].l + tree[k].r) >> 1;
    lc = k << 1;
    rc = lc | 1;
    if (l <= mid)
        update2(lc, l, r, v);
    if (r > mid)
        update2(rc, l, r, v);
    pushup(k);
}
void print(int k, int l, int r)
{
    if (l == r)
    {
        cout << tree[k].mx << ' ';
        return;
    }
    if (tree[k].lz != -1)
        pushdown(k);
    int mid, lc, rc;
    mid = (l + r) >> 1;
    lc = k << 1;
    rc = lc + 1;
    print(lc, l, mid);
    print(rc, mid + 1, r);
}

signed main()
{
    int T = read();
    while (T--)
    {
        n = read();
        build(1, 1, n);
        int Q = read();
        while (Q--)
        {
            int t = read(), l = read(), r = read(), x = read();
            if (t == 1)
                update1(1, l, r, x);
            else
                update2(1, l, r, x);
        }
        print(1, 1, n);
        cout << '\n';
    }
    return 0;
}