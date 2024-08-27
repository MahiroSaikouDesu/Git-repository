#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
const int N = 2e5 + 10;

int T, a[N], n, x, ans;
ll sum[N];

struct node
{
    int mx, l, r, lz;
} tree[N << 3];
void pushup(int k)
{
    int lc = k << 1, rc = lc | 1;
    tree[k].mx = max(tree[lc].mx, tree[rc].mx);
}
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
    rc = lc | 1;
    build(lc, l, mid);
    build(rc, mid + 1, r);
    pushup(k);
}
int query(int k, int l, int r)
{
    if (l <= tree[k].l && tree[k].r <= r)
        return tree[k].mx;
    int mid, lc, rc, Max = 0;
    mid = (tree[k].l + tree[k].r) >> 1;
    lc = k << 1;
    rc = lc + 1;
    if (l <= mid)
        Max = max(Max, query(lc, l, r));
    if (r > mid)
        Max = max(Max, query(rc, l, r));
    return Max;
}
map<int, set<int>> mp;

void prot(int l, int r, int cap)
{
    if (l > r || sum[r] - sum[l - 1] < cap)
        return;
    int maxx = query(1, l, r), cur = l;
    while (true)
    {
        auto now = mp[maxx].upper_bound(cur - 1);
        if (now == mp[maxx].end() || (*now) > r)
        {
            prot(cur, r, maxx);
            break;
        }
        ans++;
        prot(cur, (*now) - 1, maxx);
        cur = (*now) + 1;
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> T;
    while (T--)
    {
        ans = 0;
        mp.clear();
        cin >> n >> x;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= n; i++)
            sum[i] = sum[i - 1] + (ll)a[i], mp[a[i]].insert(i);
        build(1, 1, n);

        prot(1, n, query(1, 1, n));
        cout << ans << '\n';
    }
    return 0;
}