#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

const int maxn = 1e5 + 10;

struct E
{
    int u, v, c;
    E() {}
    E(int a, int b, int d) : u(a), v(b), c(d) {}
};

int n, q, s;
//  深度      子树大小    父亲  dfs序        重儿子 重链顶端    计数器
int dep[maxn], siz[maxn], fa[maxn], id[maxn], son[maxn], top[maxn], tot;
int tre[maxn << 2];
int val[maxn];
// 链式前向星
E edge[maxn];
int head[maxn], to[maxn << 1], nxt[maxn << 1], tt = 0;

// 树链剖分，第一遍dfs
// 当前节点，父亲节点
void dfs0(int now, int fat)
{
    dep[now] = dep[fat] + 1, siz[now] = 1, fa[now] = fat, son[now] = 0;

    for (int i = head[now]; i != -1; i = nxt[i])
    {
        int v = to[i];
        if (v == fat)
            continue;

        dfs0(v, now);
        siz[now] += siz[v]; // 更新子树大小
        if (siz[son[now]] < siz[v])
            son[now] = v; // 更新重儿子
    }
}

// 树链剖分，第二遍dfs
// 当前节点，重链顶端
void dfs1(int now, int tp)
{
    id[now] = ++tot, top[now] = tp;

    // 先搜重儿子
    if (son[now])
        dfs1(son[now], tp);

    for (int i = head[now]; i != -1; i = nxt[i])
    {
        int v = to[i];
        if (v == fa[now] || v == son[now])
            continue;
        dfs1(v, v);
    }
}

void build(int p, int l, int r)
{
    if (l == r)
    {
        tre[p] = val[l];
        return;
    }

    int mid = (l + r) >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);

    tre[p] = tre[p << 1] + tre[p << 1 | 1];
}

void update(int p, int l, int r, int x, int y) // location +  val
{
    if (l == r)
    {
        tre[p] = y;
        return;
    }

    int mid = (l + r) >> 1;
    if (x <= mid)
        update(p << 1, l, mid, x, y);
    else
        update(p << 1 | 1, mid + 1, r, x, y);

    tre[p] = tre[p << 1] + tre[p << 1 | 1];
}

int query(int p, int l, int r, int x, int y)
{
    if (x <= l && r <= y)
        return tre[p];

    int mid = (l + r) >> 1;

    int res = 0;
    if (x <= mid)
        res += query(p << 1, l, mid, x, y);
    if (y > mid)
        res += query(p << 1 | 1, mid + 1, r, x, y);

    return res;
}

int get_dis(int u, int v)
{
    int res = 0;

    while (top[u] != top[v])
    { // 不在同一条重链上
        if (dep[top[u]] < dep[top[v]])
            swap(u, v);

        res += query(1, 1, n, id[top[u]], id[u]); // 深度大的往上爬
        u = fa[top[u]];
    }

    if (u == v)
        return res;

    if (dep[u] < dep[v])
        swap(u, v);
    res += query(1, 1, n, id[son[v]], id[u]);

    return res;
}

void ins(int f, int t)
{
    to[tt] = t;
    nxt[tt] = head[f];
    head[f] = tt;
    tt++;
}

int main()
{
    // 链式前向星建图
    memset(head, -1, sizeof head);
    scanf("%d %d %d", &n, &q, &s);

    for (int i = 1; i <= n - 1; i++)
    {
        int x, y, c;
        scanf("%d %d %d", &x, &y, &c);
        edge[i].u = x, edge[i].v = y, edge[i].c = c;
        ins(x, y);
        ins(y, x);
    }

    // 树链剖分两遍dfs
    dfs0(1, 0);
    dfs1(1, 1);

    // 把边权分到深度较大的点上
    for (int i = 1; i <= n - 1; i++)
    {
        if (dep[edge[i].u] < dep[edge[i].v])
            swap(edge[i].u, edge[i].v);
        val[id[edge[i].u]] = edge[i].c;
    }

    // 构造线段树，维护区间和
    build(1, 1, n);

    while (q--)
    {
        int a, b, c;
        scanf("%d", &a);

        if (a == 0)
        {
            scanf("%d", &b);
            cout << get_dis(s, b) << endl;
            s = b;
        }
        else
        {
            scanf("%d %d", &b, &c);
            // 单点修改
            update(1, 1, n, id[edge[b].u], c);
        }
    }

    return 0;
}
