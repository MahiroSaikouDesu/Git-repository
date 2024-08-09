#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, m, a[N], root[N], idx, xx[N], yy[N], totx, toty, VN;
vector<int> v;
#define ls(x) tr[x].ch[0]
#define rs(x) tr[x].ch[1]
struct node
{
    int ch[2], siz;
} tr[N * 600];
struct ask
{
    int a, b, c;
} q[N];
inline int lowbit(int x) { return x & -x; }
inline int getid(int x) { return lower_bound(v.begin(), v.end(), x) - v.begin() + 1; }

void insert(int &u, int v, int l, int r, int k, int flag)
{
    u = ++idx, tr[u] = tr[v], tr[u].siz += flag;
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    if (k <= mid)
        insert(ls(u), ls(v), l, mid, k, flag);
    else
        insert(rs(u), rs(v), mid + 1, r, k, flag);
}

void add(int x, int flag)
{
    int k = getid(a[x]); // new val
    for (; x <= n; x += lowbit(x))
        insert(root[x], root[x], 1, VN, k, flag);
}

int query(int l, int r, int k)
{
    if (l == r)
        return l;
    int sum = 0, mid = (l + r) >> 1;
    for (int i = 1; i <= totx; i++)
        sum -= tr[ls(xx[i])].siz;
    for (int i = 1; i <= toty; i++)
        sum += tr[ls(yy[i])].siz;
    if (k <= sum) // left
    {
        for (int i = 1; i <= totx; i++)
            xx[i] = ls(xx[i]);
        for (int i = 1; i <= toty; i++)
            yy[i] = ls(yy[i]);
        return query(l, mid, k);
    }
    else
    {
        for (int i = 1; i <= totx; i++)
            xx[i] = rs(xx[i]);
        for (int i = 1; i <= toty; i++)
            yy[i] = rs(yy[i]);
        return query(mid + 1, r, k - sum);
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        v.push_back(a[i]);
    }
    char op;
    int x, y, z;
    for (int i = 1; i <= m; i++)
    {
        cin >> op >> q[i].a >> q[i].b;
        if (op == 'Q')
            cin >> q[i].c;
        else
            v.push_back(q[i].b);
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    VN = v.size();

    for (int i = 1; i <= n; i++)
        add(i, 1);

    for (int i = 1; i <= m; i++)
    {
        if (q[i].c)
        {
            totx = toty = 0;
            for (int j = q[i].a - 1; j; j -= lowbit(j))
                xx[++totx] = root[j];
            for (int j = q[i].b; j; j -= lowbit(j))
                yy[++toty] = root[j];
            cout << v[query(1, VN, q[i].c) - 1] << '\n';
        }
        else
        {
            add(q[i].a, -1);
            a[q[i].a] = q[i].b;
            add(q[i].a, 1);
        }
    }

    return 0;
}