#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> Pii;
#define int long long
const int inf = 1e18, INF = 1e18;
const int N = 2e5 + 10;

int n, k;
int a[N], b[N];

#define ls(x) tr[x].ch[0]
#define rs(x) tr[x].ch[1]
struct node
{
    int ch[2]; // 儿
    int fa;    // 父
    int v;     // 点权
    int cnt;   // 点权次数
    int siz;   // 子树大小
    int sti;
    void init(int p, int v1)
    {
        fa = p, v = v1;
        cnt = siz = 1;
        sti = 0;
    }
} tr[N];
int root, tot; // 根,节点个数

void pushup(int x)
{ // 上传
    tr[x].siz = tr[ls(x)].siz + tr[rs(x)].siz + tr[x].cnt;
}
void rotate(int x)
{                                                              // 旋转
    int y = tr[x].fa, z = tr[y].fa, k = tr[y].ch[1] == x;      // y的右儿是x
    tr[z].ch[tr[z].ch[1] == y] = x, tr[x].fa = z;              // z的儿是x,x的父是z
    tr[y].ch[k] = tr[x].ch[k ^ 1], tr[tr[x].ch[k ^ 1]].fa = y; // y的儿是x的异儿,x的异儿的父是y
    tr[x].ch[k ^ 1] = y, tr[y].fa = x;                         // x的异儿是y,y的父是x
    pushup(y), pushup(x);                                      // 自底向上push
}
void splay(int x, int k)
{ // 伸展
    while (tr[x].fa != k)
    { // 折线转xx,直线转yx
        int y = tr[x].fa, z = tr[y].fa;
        if (z != k)
            (ls(y) == x) ^ (ls(z) == y) ? rotate(x) : rotate(y);
        rotate(x);
    }
    if (!k)
        root = x; // k=0时,x转到根
}
void insert(int v, int sti)
{ // 插入
    int x = root, p = 0;
    // x走到空节点或走到目标点结束
    while (x && tr[x].v != v)
        p = x, x = tr[x].ch[v > tr[x].v];
    if (x)
        tr[x].cnt++, tr[x].sti += sti; // 目标点情况
    else
    { // 空节点情况
        x = ++tot;
        tr[p].ch[v > tr[p].v] = x;
        tr[x].init(p, v);
        tr[x].sti += sti;
    }
    splay(x, 0);
}
void find(int v)
{ // 找到v并转到根
    int x = root;
    while (tr[x].ch[v > tr[x].v] && v != tr[x].v)
        x = tr[x].ch[v > tr[x].v];
    splay(x, 0);
}
int getpre(int v)
{ // 前驱
    find(v);
    int x = root;
    if (tr[x].v < v)
        return x;
    x = ls(x);
    if (x == 0)
        return x;
    while (rs(x))
        x = rs(x);
    splay(x, 0);
    return x;
}
int getsuc(int v)
{ // 后继
    find(v);
    int x = root;
    if (tr[x].v > v)
        return x;
    x = rs(x);
    if (x == 0)
        return x;
    while (ls(x))
        x = ls(x);
    splay(x, 0);
    return x;
}
void del(int v)
{ // 删除
    int pre = getpre(v);
    int suc = getsuc(v);
    splay(pre, 0), splay(suc, pre);
    int del = tr[suc].ch[0];
    if (tr[del].cnt > 1)
        tr[del].cnt--, splay(del, 0);
    else
        tr[suc].ch[0] = 0, splay(suc, 0);
}
int getval(int k)
{ // 数值
    int x = root;
    while (true)
    {
        if (k <= tr[ls(x)].siz)
            x = ls(x);
        else if (k <= tr[ls(x)].siz + tr[x].cnt)
            break;
        else
            k -= tr[ls(x)].siz + tr[x].cnt, x = rs(x);
    }
    splay(x, 0);
    return x;
}

void work()
{
    int maxval = 0, minval = inf;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        maxval = max(maxval, a[i]);
        minval = min(minval, a[i]);
    }
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    int maxx = a[1], maxxit = 1, ans = 0, tmp = n >> 1, maxb = 0;
    for (int i = 2; i <= n; i++)
    {
        int cnt = a[i];
        if (b[i])
            cnt += k;
        if (maxx < cnt)
        {
            maxx = cnt;
            maxxit = i;
            maxb = b[i];
        }
        else if (maxx == cnt && maxb == 1 && !b[i])
        {
            maxx = cnt;
            maxxit = i;
            maxb = b[i];
        }
    }
    if (maxb)
    {
        priority_queue<int> q;
        for (int i = 1; i <= tmp; i++)
            q.push(inf);
        for (int i = 1; i <= n; i++)
            if (i != maxxit && q.top() > a[i])
                q.pop(), q.push(a[i]);
        cout << maxx + q.top() << '\n';
    }
    else
    {
        for (int i = 1; i <= n; i++)
            if (i != maxxit)
                insert(a[i], b[i]);
        while (k > 0)
        {
            int now = getval(tmp);
            if (tr[now].sti == 0)
            {
                int nowtmp = now;
                while (tr[now].sti == 0 && now)
                    now = getpre(now);
                if (now == 0)
                {
                    k = 0;
                    continue;
                }
                int kt = tr[nowtmp].v + 1 - tr[now].v;
                insert(tr[now].v + min(tr[nowtmp].v + 1 - tr[now].v, k), 1);
                k -= kt;
                tr[now].sti--;
                del(tr[now].v);
            }
            else // sti>0
            {
                int suc = getsuc(tr[now].v);
                if (suc)
                {
                    int kt = tr[suc].v + 1 - tr[now].v;
                    insert(min(tr[suc].v + 1 - tr[now].v, k) + tr[now].v, 1);
                    k -= kt;
                    tr[now].sti--;
                    del(tr[now].v);
                }
                else
                {
                    if (tr[now].cnt != tr[now].sti || k < tr[now].cnt)
                        k = 0;
                    else
                    {
                        cout << maxx + k / tr[now].cnt << '\n';
                        return;
                    }
                }
            }
        }
        cout << maxx + tr[getval(tmp)].v << '\n';
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--)
        work();
    return 0;
}