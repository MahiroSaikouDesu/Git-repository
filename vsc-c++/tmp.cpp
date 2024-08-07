#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e4 + 7;
const int maxm = 1e4 + 7;

int m;
int tot;

int a[maxn], b[maxn + maxm];

struct Tree
{
    int sum;
    int lc, rc;
} tree[2136839];

int root[maxn];

void out()
{
    cout << (int)(maxn * 4 + maxn * log2(maxn) + maxm * log2(maxn)) << endl;
}

void init(int n)
{
    tot = 0;
    sort(b + 1, b + 1 + n);
    m = unique(b + 1, b + 1 + n) - b - 1;
}

int getid(int x)
{
    return lower_bound(b + 1, b + 1 + m, x) - b;
}

int build(int l, int r)
{
    int k = ++tot;
    tree[k].sum = 0;
    if (l == r)
        return k;
    int mid = (l + r) >> 1;
    tree[k].lc = build(l, mid);
    tree[k].rc = build(mid + 1, r);
    return k;
}

int updata(int p, int l, int r, int id, int val)
{
    int k = ++tot;
    tree[k] = tree[p];
    if (l == r)
    {
        tree[k].sum += val;
        return k;
    }
    int mid = (l + r) >> 1;
    if (id <= mid)
        tree[k].lc = updata(tree[p].lc, l, mid, id, val);
    else
        tree[k].rc = updata(tree[p].rc, mid + 1, r, id, val);
    tree[k].sum = tree[tree[k].lc].sum + tree[tree[k].rc].sum;
    return k;
}

int S[maxn];          // 树状数组中线段树的最开始的节点;
int X[maxn], Y[maxn]; // 树状数组中该次查找会用到的线段树的节点编号;
int n;

int lowbit(int x)
{
    return x & (-x);
}

void add(int x, int id, int val)
{
    for (; x <= n; x += lowbit(x))
        S[x] = updata(S[x], 1, m, id, val);
}

int getsum(int x, int a[])
{
    int res = 0;
    for (; x; x -= lowbit(x))
        res += tree[tree[a[x]].lc].sum;
    return res;
}

// 区间查询非递归写法;
int myfind(int p, int q, int k)
{
    int l = 1, r = m, mid;
    int left_root = root[q - 1], right_root = root[p];
    for (int x = p; x; x -= lowbit(x))
        Y[x] = S[x];
    for (int x = q - 1; x; x -= lowbit(x))
        X[x] = S[x];
    while (l < r)
    {
        mid = (l + r) >> 1;
        int summ = getsum(p, Y) - getsum(q - 1, X) + tree[tree[right_root].lc].sum - tree[tree[left_root].lc].sum;
        if (k <= summ)
        {
            r = mid;
            for (int x = p; x; x -= lowbit(x))
                Y[x] = tree[Y[x]].lc;
            for (int x = q - 1; x; x -= lowbit(x))
                X[x] = tree[X[x]].lc;
            left_root = tree[left_root].lc;
            right_root = tree[right_root].lc;
        }
        else
        {
            k -= summ;
            l = mid + 1;
            for (int x = p; x; x -= lowbit(x))
                Y[x] = tree[Y[x]].rc;
            for (int x = q - 1; x; x -= lowbit(x))
                X[x] = tree[X[x]].rc;
            left_root = tree[left_root].rc;
            right_root = tree[right_root].rc;
        }
    }
    return l;
}

struct Node
{
    int l, r;
    int k;
    bool f;
} qq[maxm];
char s[9];

int main()
{
    // out();
    int t, q;
    scanf("%d", &t);
    while (t--)
    {
        int len = 0;
        scanf("%d%d", &n, &q);
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &a[i]);
            b[++len] = a[i];
        }
        for (int i = 1; i <= q; ++i)
        {
            scanf("%s", s);
            if (s[0] == 'Q')
            {
                scanf("%d%d%d", &qq[i].l, &qq[i].r, &qq[i].k);
                qq[i].f = 1;
            }
            else
            {
                scanf("%d%d", &qq[i].l, &qq[i].r);
                qq[i].f = 0;
                b[++len] = qq[i].r;
            }
        }

        init(len);
        // cout<<m<<endl;
        root[0] = build(1, m);
        for (int i = 1; i <= n; ++i)
            root[i] = updata(root[i - 1], 1, m, getid(a[i]), 1);
        for (int i = 1; i <= n; ++i)
            S[i] = root[0];
        for (int i = 1; i <= q; ++i)
        {
            if (qq[i].f)
                printf("%d\n", b[myfind(qq[i].r, qq[i].l, qq[i].k)]);
            else
            {
                add(qq[i].l, getid(a[qq[i].l]), -1);
                add(qq[i].l, getid(qq[i].r), 1);
                a[qq[i].l] = qq[i].r;
            }
        }
    }
    return 0;
}