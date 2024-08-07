#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> Pii;
const int INF = 1e9 + 10;
const int N = 5e4 + 7, M = 1e5 + 7;

#define ls(x) tr[x].s[0]
#define rs(x) tr[x].s[1]
int n, m, w[N], idx;
int root[N * 4]; // segment_Tree
// splay
struct node
{
    int s[2], p;
    int v, siz;
} tr[N * 20];
void init(int i, int p1, int v1)
{
    tr[i].p = p1;
    tr[i].v = v1;
    tr[i].siz = 1;
}
inline void pushup(int x) { tr[x].siz = tr[ls(x)].siz + tr[rs(x)].siz + 1; }
inline void rotate(int x)
{
    int y = tr[x].p, z = tr[y].p;
    int k = tr[y].s[1] == x;
    tr[z].s[tr[z].s[1] == y] = x, tr[x].p = z;
    tr[y].s[k] = tr[x].s[k ^ 1], tr[tr[x].s[k ^ 1]].p = y;
    tr[x].s[k ^ 1] = y, tr[y].p = x;
    pushup(y), pushup(x);
}
inline void splay(int &root, int x, int k)
{
    while (tr[x].p != k)
    {
        int y = tr[x].p, z = tr[y].p;
        if (z != k)
            if ((rs(y) == x) ^ (rs(z) == y))
                rotate(x);
            else
                rotate(y);
        rotate(x);
    }
    if (!k)
        root = x;
}
inline void insert(int &root, int v)
{
    int u = root, p = 0;
    while (u)
        p = u, u = tr[u].s[v > tr[u].v];
    u = ++idx;
    tr[p].s[v > tr[p].v] = u;
    init(u, p, v);
    splay(root, u, 0);
}
inline void del(int &root, int v)
{
    int u = root;
    while (u)
    {
        if (tr[u].v == v)
            break;
        if (tr[u].v < v)
            u = rs(u);
        else
            u = ls(u);
    }
    splay(root, u, 0);
    int l = ls(u), r = rs(u);
    while (rs(l))
        l = rs(l);
    while (ls(r))
        r = ls(r);
    splay(root, l, 0);
    splay(root, r, l);
    ls(r) = 0;
    splay(root, r, 0);
}
inline int getrank(int root, int v)
{
    int u = root, res = 0;
    while (u)
    {
        if (tr[u].v < v)
            res += tr[ls(u)].siz + 1, u = rs(u);
        else
            u = ls(u);
    }
    return res;
} //////////线段树
#define lc u << 1
#define rc u << 1 | 1
void build(int u, int l, int r)
{
    insert(root[u], -INF), insert(root[u], INF);
    for (int i = l; i <= r; i++)
        insert(root[u], w[i]);
    if (l == r)
        return;
    int mid = l + r >> 1;
    build(lc, l, mid);
    build(rc, mid + 1, r);
}
int queryrank(int u, int l, int r, int x, int y, int v)
{
    if (x <= l && r <= y)
        return getrank(root[u], v) - 1;
    int mid = l + r >> 1, res = 0;
    if (x <= mid)
        res += queryrank(lc, l, mid, x, y, v);
    if (y > mid)
        res += queryrank(rc, mid + 1, r, x, y, v);
    return res;
}
int queryval(int u, int x, int y, int k)
{
    int l = 0, r = INF, ans; // 二分
    while (l <= r)
    {
        int mid = l + r >> 1;
        if (queryrank(1, 1, n, x, y, mid) + 1 <= k)
            l = mid + 1, ans = mid;
        else
            r = mid - 1;
    }
    return ans;
}
void change(int u, int l, int r, int pos, int v)
{
    if (pos < l || r < pos)
        return;
    del(root[u], w[pos]);
    insert(root[u], v);
    if (l == r)
        return;
    int mid = l + r >> 1;
    if (pos <= mid)
        change(lc, l, mid, pos, v);
    else
        change(rc, mid + 1, r, pos, v);
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        idx = 0;
        cin >> n >> m;
        memset(tr, 0, sizeof tr);
        memset(root, 0, sizeof root);
        for (int i = 1; i <= n; i++)
            cin >> w[i];

        build(1, 1, n);
        char op;
        int x, y, z;
        while (m--)
        {
            cin >> op;
            if (op == 'Q')
            {
                cin >> x >> y >> z;
                cout << queryval(1, x, y, z) << '\n';
            }
            else
            {
                cin >> x >> y;
                change(1, 1, n, x, y), w[x] = y;
            }
        }
    }
    return 0;
}