#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> Pii;
const int inf = (1 << 30) + 1;
const int N = 1e6 + 5;

int n, m, a[N], root[N], idx;
#define lc(x) tr[x].ch[0]
#define rc(x) tr[x].ch[1]
struct node
{
    int ch[2], val;
} tr[N * 25];
void build(int &x, int l, int r)
{
    x = ++idx;
    if (l == r)
    {
        tr[x].val = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(lc(x), l, mid);
    build(rc(x), mid + 1, r);
}
int insert(int x, int y, int l, int r, int pos, int v)
{
    y = ++idx;
    tr[y] = tr[x];
    if (l == r)
    {
        tr[y].val = v;
        return y;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid) // 双指针同步搜索
        lc(y) = insert(lc(x), lc(y), l, mid, pos, v);
    else
        rc(y) = insert(rc(x), rc(y), mid + 1, r, pos, v);
    return y;
}
int query(int x, int l, int r, int k)
{
    if (l == r)
        return tr[x].val;
    int mid = (l + r) >> 1; // 双指针同步搜索
    if (k <= mid)
        return query(lc(x), l, mid, k);
    else
        return query(rc(x), mid + 1, r, k);
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    build(root[0], 1, n);

    int v, op, loc, val;
    for (int i = 1; i <= m; i++)
    {
        cin >> v >> op >> loc;
        if (op == 1)
        {
            cin >> val;
            root[i] = insert(root[v], root[i], 1, n, loc, val);
        }
        else
        {
            cout << query(root[v], 1, n, loc) << '\n';
            root[i] = root[v];
        }
    }
    return 0;
}