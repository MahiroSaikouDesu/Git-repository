#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long

#define ls(x) tr[x].ch[0]
#define rs(x) tr[x].ch[1]
const int N = 2e5 + 10, INF = 0x3f3f3f3f << 1, inf = INF;
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
    }
} tr[N];
int root, tot; // 根,节点个数
int n, k;
int a[N], b[N];
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
void insertq(int v, int sti, int sum)
{ // 插入
    int x = root, p = 0;
    // x走到空节点或走到目标点结束
    while (x && tr[x].v != v)
        p = x, x = tr[x].ch[v > tr[x].v];
    if (x)
        tr[x].cnt += sum, tr[x].sti += sti; // 目标点情况
    else
    { // 空节点情况
        x = ++tot;
        tr[p].ch[v > tr[p].v] = x;
        tr[x].init(p, v);
        tr[x].cnt = sum;
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
    while (ls(x))
        x = ls(x);
    splay(x, 0);
    return x;
}
int getprework(int v)
{ // 前驱
    find(v);
    int x = root;
    if (tr[x].v < v)
        return x;
    x = ls(x);
    if (!x || tr[x].v == -inf)
        return 0;
    while (rs(x))
        x = rs(x);
    splay(x, 0);
    return x;
}
int getsucwork(int v)
{ // 后继
    find(v);
    int x = root;
    if (tr[x].v > v)
        return x;
    x = rs(x);
    if (!x || tr[x].v == inf)
        return 0;
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
void delq(int v, int sum)
{ // 删除
    int pre = getpre(v);
    int suc = getsuc(v);
    splay(pre, 0), splay(suc, pre);
    int del = tr[suc].ch[0];
    if (tr[del].cnt > 1)
        tr[del].cnt -= sum, splay(del, 0);
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
    return tr[x].v;
}
int getvalbyrank(int k)
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
ll work()
{
    memset(tr, 0, sizeof tr);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    int maxx = a[1], maxxit = 1, ans = 0, tmp = n >> 1, maxb = 0;
    for (int i = 2; i <= n; i++)
    {
        int cnt = a[i];
        if (b[i])
            cnt += k;
        if (maxx < cnt)
            maxx = cnt, maxxit = i, maxb = b[i];
        else if (maxx == cnt && maxb && !b[i])
            maxx = cnt, maxxit = i, maxb = b[i];
    }
    if (maxb)
    {
        priority_queue<int> q;
        for (int i = 1; i <= tmp; i++)
            q.push(inf);
        for (int i = 1; i <= n; i++)
            if (i != maxxit && q.top() > a[i])
                q.pop(), q.push(a[i]);
        return maxx * 1LL + q.top();
    }
    else
    {
        insert(inf, 0), insert(-inf, 0);
        for (int i = 1; i <= n; i++)
            if (i != maxxit)
                insert(a[i], b[i]);
        tmp++;
        while (k > 0)
        {
            int nowidx = getvalbyrank(tmp);
            if (tr[nowidx].sti)
            {
                int nowsuc = getsucwork(tr[nowidx].v);
                if (nowsuc)
                {
                    int kt = tr[nowsuc].v - tr[nowidx].v;
                    insert(min(kt, k) + tr[nowidx].v, 1);
                    k -= kt;
                    tr[nowidx].sti--;
                    del(tr[nowidx].v);
                }
                else // suc = 0
                {
                    if (k < tr[nowidx].sti)
                        return maxx + tr[nowidx].v;

                    if (tr[nowidx].sti >= tr[nowidx].cnt)
                        return maxx + k / tr[nowidx].cnt + tr[nowidx].v;

                    else // sti < cnt
                    {
                        int pre = nowidx;
                        while (pre = getprework(tr[pre].v) && !tr[pre].sti)
                            ;
                        if (!pre)
                        {
                            if (k >= tr[nowidx].sti)
                            {

                            }
                            else
                            {

                            }
                        }
                        int kt = tr[nowidx].v - tr[pre].v;
                        insert(min(kt, k) + tr[pre].v, 1);
                        k -= kt;
                        tr[pre].sti--;
                        del(tr[pre].v);
                    }
                }
            }
            else // tr[now].sti == 0
            {
                int pre = nowidx;
                while (1)
                {
                    pre = getprework(tr[pre].v);
                    if (!pre || tr[pre].sti)
                        break;
                }
                if (!pre)
                    return maxx + tr[nowidx].v;
                int kt = tr[nowidx].v + 1 - tr[pre].v;
                insert(min(kt, k) + tr[pre].v, 1);
                k -= kt;
                tr[pre].sti--;
                del(tr[pre].v);
            }
        }
        return maxx + getval(tmp);
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--)
        cout << work() << '\n';
    return 0;
}