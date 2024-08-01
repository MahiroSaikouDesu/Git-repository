#include <bits/stdc++.h>
using namespace std;
const int N = 300005, inf = 0x3f3f3f3f;

#define fa(x) tr[x].p
#define lc(x) tr[x].s[0]
#define rc(x) tr[x].s[1]
#define notroot(x) lc(fa(x)) == x || rc(fa(x)) == x
int n, m, x, y;
struct node
{
    int s[2], p, v, mx, tag, add;
} tr[N];
void pushup(int x)
{
    tr[x].mx = max(tr[x].v, max(tr[lc(x)].mx, tr[rc(x)].mx));
}
void pushdown(int x)
{
    if (tr[x].tag)
    {
        swap(lc(x), rc(x));
        tr[lc(x)].tag ^= 1, tr[rc(x)].tag ^= 1;
        tr[x].tag = 0;
    }
    if (tr[x].add)
    {
        if (lc(x))
        {
            tr[lc(x)].add += tr[x].add;
            tr[lc(x)].mx += tr[x].add;
            tr[lc(x)].v += tr[x].add;
        }
        if (rc(x))
        {
            tr[rc(x)].add += tr[x].add;
            tr[rc(x)].mx += tr[x].add;
            tr[rc(x)].v += tr[x].add;
        }
        tr[x].add = 0;
    }
}
void pushall(int x)
{
    if (notroot(x))
        pushall(fa(x));
    pushdown(x);
}
void rotate(int x)
{
    int y = fa(x), z = fa(y);
    int k = rc(y) == x;
    if (notroot(y))
        tr[z].s[rc(z) == y] = x;
    fa(x) = z;
    tr[y].s[k] = tr[x].s[k ^ 1];
    fa(tr[x].s[k ^ 1]) = y;
    tr[x].s[k ^ 1] = y;
    fa(y) = x;
    pushup(y), pushup(x);
}
void splay(int x)
{
    pushall(x);
    while (notroot(x))
    {
        int y = fa(x), z = fa(y);
        if (notroot(y))
            (rc(y) == x) ^ (rc(z) == y) ? rotate(x) : rotate(y);
        rotate(x);
    }
}
void access(int x)
{
    for (int y = 0; x; y = x, x = fa(x))
    {
        splay(x);
        rc(x) = y;
        pushup(x);
    }
}
void makeroot(int x)
{
    access(x);
    splay(x);
    tr[x].tag ^= 1;
}
void split(int x, int y) // 分离
{
    makeroot(x);
    access(y);
    splay(y);
}
int findroot(int x)
{
    access(x);
    splay(x);
    while (lc(x))
        pushdown(x), x = lc(x);
    splay(x);
    return x;
}
void link(int x, int y)
{
    makeroot(x);
    fa(x) = y;
}
void cut(int x, int y)
{
    split(x, y);
    lc(y) = fa(lc(y)) = 0;
    pushup(y);
}
void add(int w, int x, int y)
{
    split(x, y);
    tr[y].add += w;
    tr[y].v += w;
    tr[y].mx += w;
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    while (cin >> n)
    {
        for (int i = 0; i <= n; i++)
        {
            tr[i].s[0] = 0;
            tr[i].s[1] = 0;
            tr[i].p = 0;
            tr[i].tag = 0;
            tr[i].add = 0;
        }
        tr[0].mx = -inf;
        for (int i = 1; i < n; i++)
        {
            cin >> x >> y;
            link(x, y);
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> tr[i].v;
            tr[i].mx = tr[i].v;
        }

        int q, op, w;
        cin >> q;
        while (q--)
        {
            cin >> op;
            switch (op)
            {
            case 1:
            {
                cin >> x >> y;
                if (findroot(x) == findroot(y))
                    cout << "-1\n";
                else
                    link(x, y);
                break;
            }
            case 2:
            {
                cin >> x >> y;
                if (findroot(x) != findroot(y) || x == y)
                    cout << "-1\n";
                else
                    cut(x, y);
                break;
            }
            case 3:
            {
                cin >> w >> x >> y;
                if (findroot(x) != findroot(y))
                    cout << "-1\n";
                else
                    add(w, x, y);
                break;
            }
            case 4:
            {
                cin >> x >> y;
                if (findroot(x) != findroot(y))
                    cout << "-1\n";
                else
                {
                    split(x, y);
                    cout << tr[y].mx << "\n";
                }
                break;
            }
            }
        }
        cout << '\n';
    }
    return 0;
}