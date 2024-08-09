#include <bits/stdc++.h>
using namespace std;
const int inf = (1 << 30) + 1;
const int N = 2e5 + 10;
int n, m, a[N], root[N], idx;
vector<int> v;
#define lc(x) tr[x].ch[0]
#define rc(x) tr[x].ch[1]
struct node
{
    int ch[2], siz;
} tr[N * 22];
void build(int &x, int l, int r)
{
    x = ++idx;
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    build(lc(x), l, mid);
    build(rc(x), mid + 1, r);
}
void insert(int x, int &y, int l, int r, int v)
{
    y = ++idx, tr[y] = tr[x], tr[y].siz++;
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    if (v <= mid) // 双指针同步搜索
        insert(lc(x), lc(y), l, mid, v);
    else
        insert(rc(x), rc(y), mid + 1, r, v);
}
int query(int x, int y, int l, int r, int k)
{
    if (l == r)
        return l;
    int mid = (l + r) >> 1; // 双指针同步搜索
    int s = tr[lc(y)].siz - tr[lc(x)].siz;
    if (k <= s)
        return query(lc(x), lc(y), l, mid, k);
    else
        return query(rc(x), rc(y), mid + 1, r, k - s);
}
inline int getid(int val) { return lower_bound(v.begin(), v.end(), val) - v.begin() + 1; }

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        v.push_back(a[i]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    int bn = v.size(), l, r, k;
    build(root[0], 1, bn);
    for (int i = 1; i <= n; i++)
        insert(root[i - 1], root[i], 1, bn, getid(a[i]));

    while (m--)
    {
        cin >> l >> r >> k;
        cout << v[query(root[l - 1], root[r], 1, bn, k) - 1] << '\n';
    }
    return 0;
}