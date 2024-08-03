#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> Pii;
const int inf = (1 << 30) + 1;
const int N = 5e5 + 10;

#define lc t[p].l
#define rc t[p].r
#define px t[p].v[0]
#define py t[p].v[1]
const double A = 0.7;              // 重构常数
int n, K, root, cur, ans, lastans; // K维度,root根,cur当前节点
int g[N], cnt;                     // g存储节点的编号
int q[2][2], x, y, w;
struct KD
{                   // KD树节点信息
    int l, r;       // 左右孩子
    int v[2];       // 点的坐标值
    int L[2], U[2]; // 子树区域坐标极值
    int siz;        // 子树大小
    int val, sum;
} t[N];

void pushup(int p)
{ // 更新p子树的信息
    t[p].siz = t[lc].siz + t[rc].siz + 1;
    t[p].sum = t[lc].sum + t[rc].sum + t[p].val;
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
bool cmp(int a, int b)
{ // 按点的坐标值比较
    return t[a].v[K] < t[b].v[K];
}
int rebuild(int l, int r, int k)
{ // 重构子树
    if (l > r)
        return 0;
    int m = (l + r) >> 1;
    K = k;
    nth_element(g + l, g + m, g + r + 1, cmp);
    t[g[m]].l = rebuild(l, m - 1, k ^ 1);
    t[g[m]].r = rebuild(m + 1, r, k ^ 1);
    pushup(g[m]);
    return g[m];
}
void dfs(int p)
{ // 提取p子树的节点编号
    if (!p)
        return;
    g[++cnt] = p;
    dfs(lc);
    dfs(rc);
}
void check(int &p, int k)
{ // 检查
    if (A * t[p].siz < max(t[lc].siz, t[rc].siz))
        cnt = 0, dfs(p), p = rebuild(1, cnt, k);
}
void insert(int &p, int k)
{ // 插点
    if (!p)
    {
        p = cur;
        pushup(p);
        return;
    }
    insert(t[cur].v[k] <= t[p].v[k] ? lc : rc, k ^ 1);
    pushup(p);
    check(p, k); // 检查是否重构p子树
}
int sq(int x) { return x * x; }
bool range(int p)
{
    for (int i = 0; i < 2; i++)
        if (q[i][0] > t[p].L[i] || q[i][1] < t[p].U[i])
            return 0;
    return 1;
}
bool qcheck(int p)
{
    for (int i = 0; i < 2; i++)
        if (q[i][0] > t[p].U[i] || q[i][1] < t[p].L[i])
            return 0;
    return 1;
}
bool qpcheck(int p)
{
    for (int i = 0; i < 2; i++)
        if (q[i][0] > t[p].v[i] || q[i][1] < t[p].v[i])
            return 0;
    return 1;
}
void query(int p)
{ // 查询当前点的最小距离
    if (!p)
        return;
    if (range(p))
    {
        ans += t[p].sum;
        return;
    }
    if (qpcheck(p))
        ans += t[p].val;
    if (qcheck(lc))
        query(lc);
    if (qcheck(rc))
        query(rc);
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    int op;
    while (1)
    {
        cin >> op;
        if (op == 1)
        {
            cur++;
            cin >> t[cur].v[0] >> t[cur].v[1] >> t[cur].val;
            t[cur].v[0] ^= lastans;
            t[cur].v[1] ^= lastans;
            t[cur].val ^= lastans;
            insert(root, 0);
        }
        if (op == 2)
        {
            ans = 0;
            cin >> q[0][0] >> q[1][0] >> q[0][1] >> q[1][1];
            q[0][0] ^= lastans;
            q[0][1] ^= lastans;
            q[1][0] ^= lastans;
            q[1][1] ^= lastans;
            query(root);
            cout << ans << '\n';
            lastans = ans;
        }
        if (op == 3)
            break;
    }
    return 0;
}