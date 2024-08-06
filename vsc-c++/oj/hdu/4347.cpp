#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<ll, int> Pii;
const ll inf = 1e18;
const int N = 5e4 + 10;
#define lc t[p].l
#define rc t[p].r
#define tx t[i].v[0]
#define ty t[i].v[1]
int n, K, root, cur, m, kt; // K维度,root根,cur当前节点
struct KD                   // KD树节点信息
{
    int l, r;       // 左右孩子
    int v[7];       // 点的坐标值
    int L[7], U[7]; // 子树区域的坐标范围
    void init()
    {
        l = r = 0;
        for (int i = 0; i < K; i++)
            L[i] = U[i] = 0;
    }
    bool operator<(const KD &b) const { return v[kt] < b.v[kt]; }
} t[N];
priority_queue<Pii> q;
void pushup(int p) // 更新p子树区域的坐标范围
{
    for (int i = 0; i < K; i++)
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
    kt = k;
    nth_element(t + l, t + m, t + r + 1); // 中位数
    t[m].l = build(l, m - 1, k == K - 1 ? 0 : k + 1);
    t[m].r = build(m + 1, r, k == K - 1 ? 0 : k + 1);
    pushup(m);
    return m;
}
inline ll sq(int x) { return 1LL * x * x; }
ll dis(int p)
{ // 当前点到p点的距离
    ll s = 0;
    for (int i = 0; i < K; i++)
        s += sq(t[cur].v[i] - t[p].v[i]);
    return s;
}
ll dis2(int p) // 当前点到p子树区域的最小距离
{
    if (!p)
        return inf;
    ll s = 0;
    for (int i = 0; i < K; ++i)
        s += sq(max(t[cur].v[i] - t[p].U[i], 0)) +
             sq(max(t[p].L[i] - t[cur].v[i], 0));
    return s;
}
void query(int p)
{ // 查询当前点的最小距离
    if (!p)
        return;
    ll nd = dis(p);
    if (p != cur && nd < q.top().first)
    {
        q.pop();
        q.push({nd, p});
    }
    ll dl = dis2(lc), dr = dis2(rc);
    if (dl < dr)
    {
        if (dl < q.top().first)
            query(lc);
        if (dr < q.top().first)
            query(rc);
    }
    else
    {
        if (dr < q.top().first)
            query(rc);
        if (dl < q.top().first)
            query(lc);
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    while (cin >> n >> K)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < K; j++)
                cin >> t[i].v[j];
            t[i].init();
        }

        root = build(1, n, 0);

        int T, m;
        cur = n + 1;
        cin >> T;
        while (T--)
        {
            for (int j = 0; j < K; j++)
                cin >> t[cur].v[j];
            cin >> m;
            for (int j = 1; j <= m; j++)
                q.push({inf, 0});
            query(root);
            cout << "the closest " << m << " points are:\n";
            vector<int> qans;
            while (!q.empty())
            {
                qans.push_back(q.top().second);
                q.pop();
            }
            for (auto it = qans.rbegin(); it != qans.rend(); it++)
            {
                int now = *it;
                for (int j = 0; j < K; j++)
                    cout << t[now].v[j] << ' ';
                cout << '\n';
            }
        }
    }
    return 0;
}