#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> Pii;
const int N = 100010;
priority_queue<ll, vector<ll>, greater<ll>> q;
#define lc t[p].l
#define rc t[p].r
#define tx t[i].v[0]
#define ty t[i].v[1]
ll n;
int K, root, cur; // K维度,root根,cur当前节点
struct KD         // KD树节点信息
{
    int l, r;      // 左右孩子
    ll v[2];       // 点的坐标值
    ll L[2], U[2]; // 子树区域的坐标范围
    bool operator<(const KD &b) const { return v[K] < b.v[K]; }
} t[N];
void pushup(int p) // 更新p子树区域的坐标范围
{
    for (int i = 0; i < 2; i++)
    {
        t[p].L[i] = t[p].U[i] = t[p].v[i];
        if (lc)
            t[p].L[i] = min(t[p].L[i], t[lc].L[i]),
            t[p].U[i] = max(t[p].U[i], t[lc].U[i]);
        if (rc)
            t[p].L[i] = min(t[p].L[i], t[rc].L[i]),
            t[p].U[i] = max(t[p].U[i], t[rc].U[i]);
    }
}
int build(int l, int r, int k) // 交替建树
{
    if (l > r)
        return 0;
    ll m = (l + r) >> 1;
    K = k;
    nth_element(t + l, t + m, t + r + 1); // 中位数
    t[m].l = build(l, m - 1, k ^ 1);
    t[m].r = build(m + 1, r, k ^ 1);
    pushup(m);
    return m;
}
inline ll sq(ll x) { return x * x; }
ll dis(int p)
{ // 当前点到p点的距离
    ll s = 0;
    for (int i = 0; i < 2; i++)
        s += sq(t[cur].v[i] - t[p].v[i]);
    return s;
}
ll dis2(int p) // 当前点到p子树区域的最小距离
{
    if (!p)
        return 0;
    ll s = 0;
    for (int i = 0; i < 2; ++i)
        s += sq(max(t[cur].v[i] - t[p].L[i], 1ll * 0)) +
             sq(max(t[p].U[i] - t[cur].v[i], 1ll * 0));
    return s;
}
void query(int p)
{ // 查询当前点的最小距离
    if (!p || p == cur)
        return;
    ll d = dis(p);
    if (d > q.top())
        q.pop(), q.push(d);
    ll dl = dis2(lc), dr = dis2(rc);
    if (dl > dr)
    {
        if (dl > q.top())
            query(lc);
        if (dr > q.top())
            query(rc);
    }
    else
    {
        if (dr > q.top())
            query(rc);
        if (dl > q.top())
            query(lc);
    }
}
inline ll read()
{
    ll x = 0;
    int f = 1;
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

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll T;
    n = read(), T = read();
    while (T--)
        q.push(0), q.push(0);
    for (int i = 1; i <= n; i++)
        tx = read(), ty = read();

    root = build(1, n, 0);

    for (cur = 1; cur <= n; cur++)
        query(root);

    printf("%lld", q.top());
    return 0;
}