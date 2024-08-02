#include <bits/stdc++.h>
using namespace std;
const int N = 1100010, inf = 0x3f3f3f3f;

#define ls(x) tr[x].ch[0]
#define rs(x) tr[x].ch[1]
struct node
{
    int ch[2]; // 儿
    int fa;    // 父
    int v;     // 点权
    int cnt;   // 点权次数
    int siz;   // 子树大小
    void init(int p, int v1)
    {
        fa = p, v = v1;
        cnt = siz = 1;
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
void insert(int v)
{ // 插入
    int x = root, p = 0;
    // x走到空节点或走到目标点结束
    while (x && tr[x].v != v)
        p = x, x = tr[x].ch[v > tr[x].v];
    if (x)
        tr[x].cnt++; // 目标点情况
    else
    { // 空节点情况
        x = ++tot;
        tr[p].ch[v > tr[p].v] = x;
        tr[x].init(p, v);
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
int getrank(int v)
{ // 排名
    insert(v);
    int res = tr[tr[root].ch[0]].siz;
    del(v);
    return res;
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
int op, w, n;
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    insert(-inf);
    insert(inf);
    while (n--)
    {
        cin >> op >> w;
        if (op == 1)
            insert(w);
        if (op == 2)
            del(w);
        if (op == 3)
            cout << getrank(w) << '\n';
        if (op == 4)
            cout << getval(w + 1) << '\n';
        if (op == 5)
            cout << tr[getpre(w)].v << '\n';
        if (op == 6)
            cout << tr[getsuc(w)].v << '\n';
    }
    return 0;
}