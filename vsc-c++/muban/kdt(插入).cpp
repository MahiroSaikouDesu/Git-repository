#define lc t[p].l
#define rc t[p].r
#define px t[p].v[0]
#define py t[p].v[1]
const double A = 0.7; // 重构常数
double ans = inf;
int n, K, root, cur; // K维度,root根,cur当前节点
int g[N], cnt;       // g存储节点的编号
struct KD
{                      // KD树节点信息
    int l, r;          // 左右孩子
    double v[2];       // 点的坐标值
    double L[2], U[2]; // 子树区域坐标极值
    int siz;           // 子树大小
} t[N];

void pushup(int p)
{ // 更新p子树的信息
    t[p].siz = t[lc].siz + t[rc].siz + 1;
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
double sq(double x) { return x * x; }
double dis(int p)
{ // 当前点到p点的距离
    double s = 0;
    for (int i = 0; i < 2; i++)
        s += sq(t[cur].v[i] - t[p].v[i]);
    return s;
}
double dis2(int p)
{ // 当前点到p子树区域的最小距离
    if (!p)
        return 2e18;
    double s = 0;
    for (int i = 0; i < 2; ++i)
        s += sq(max(t[cur].v[i] - t[p].U[i], 0.0)) +
             sq(max(t[p].L[i] - t[cur].v[i], 0.0));
    return s;
}
void query(int p)
{ // 查询当前点的最小距离
    if (!p)
        return;
    if (p != cur)
        ans = min(ans, dis(p));
    double dl = dis2(lc), dr = dis2(rc);
    if (dl < dr)
    {
        if (dl < ans)
            query(lc);
        if (dr < ans)
            query(rc);
    }
    else
    {
        if (dr < ans)
            query(rc);
        if (dl < ans)
            query(lc);
    }
}