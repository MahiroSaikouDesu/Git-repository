#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> Pii;
const ll inf = 1e18;
// const int N = 2e5 + 3e4;
const int N = 2e5 + 10;
#define double int
#define lc t[p].l
#define rc t[p].r
#define tx t[i].v[0]
#define ty t[i].v[1]
#define tw t[i].w
vector<int> P; // now -> old
map<Pii, int> pl;
int n, K, root, cur, m, res; // K维度,root根,cur当前节点
ll ans;
struct KD // KD树节点信息
{
    int l, r, w;    // 左右孩子
    int v[2];       // 点的坐标值
    int L[2], U[2]; // 子树区域的坐标范围
    void init() { L[0] = L[1] = U[0] = U[1] = l = r = 0; }
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
    int m = (l + r) >> 1;
    K = k;
    nth_element(t + l, t + m, t + r + 1); // 中位数
    t[m].l = build(l, m - 1, k ^ 1);
    t[m].r = build(m + 1, r, k ^ 1);
    pushup(m);
    return m;
}
inline ll sq(int x) { return 1ll * x * x; }
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
        return inf;
    ll s = 0;
    for (int i = 0; i < 2; ++i)
        s += sq(max(t[cur].v[i] - t[p].U[i], 0)) +
             sq(max(t[p].L[i] - t[cur].v[i], 0));
    return s;
}
void query(int p)
{ // 查询当前点的最小距离
    if (!p)
        return;
    ll nd = dis(p);
    if (p != cur && (t[p].w <= t[cur].w && nd <= ans))
    {
        if (nd == ans)
            res = P[res] < P[p] ? res : p;
        else
            res = p, ans = nd;
    }
    ll dl = dis2(lc), dr = dis2(rc);
    if (dl < dr)
    {
        if (dl <= ans)
            query(lc);
        if (dr <= ans)
            query(rc);
    }
    else
    {
        if (dr <= ans)
            query(rc);
        if (dl <= ans)
            query(lc);
    }
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    // cout << '\n'; // 输出分割
    while (T--)
    {
        K = 0;
        cin >> n >> m;
        P.resize(n + 10);
        pl.clear();
        for (int i = 1; i <= n; i++)
        {
            cin >> tx >> ty >> tw;
            t[i].init();
            pl[{tx, ty}] = i;
        }

        root = build(1, n, K);

        for (int i = 1; i <= n; i++)
            P[i] = pl[{tx, ty}];

        int x, y, c, i = n + 1;
        cur = i;
        while (m--)
        {
            ans = inf;
            res = 0;
            cin >> tx >> ty >> tw;
            query(root);
            cout << t[res].v[0] << ' ' << t[res].v[1] << ' ' << t[res].w << "\n";
        }
    }
    return 0;
}