#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;
const int N = 1e5 + 10, inf = 0x3f3f3f3f;

#define fa(x) tr[x].p
#define lc(x) tr[x].s[0]
#define rc(x) tr[x].s[1]
#define notroot(x) lc(fa(x)) == x || rc(fa(x)) == x
int n, m, T, a, b, x, y, w, op, d, kns;
struct node
{
    int s[2], p, v, tag, add, mx1, mx2, c1, c2, cha, size;
} tr[N];

void change(int y, int v)
{
    tr[y].cha = v;
    tr[y].v = v;
    tr[y].mx1 = v, tr[y].mx2 = -inf;
    tr[y].add = 0;
    tr[y].c1 = tr[y].size;
    tr[y].c2 = 0;
}
void add(int y, int v)
{
    tr[y].add += v;
    tr[y].v += v;
    tr[y].mx1 += v;
    if (tr[y].mx2 != -inf)
        tr[y].mx2 += v;
}
void cnt(int x, int val, int c) // 统计最大值之类信息
{
    if (val > tr[x].mx1)
    {
        tr[x].mx2 = tr[x].mx1;
        tr[x].mx1 = val;
        tr[x].c2 = tr[x].c1;
        tr[x].c1 = c;
    }
    else if (val == tr[x].mx1)
        tr[x].c1 += c;
    else if (val > tr[x].mx2)
    {
        tr[x].mx2 = val;
        tr[x].c2 = c;
    }
    else if (val == tr[x].mx2)
        tr[x].c2 += c;
}
void pushup(int x)
{
    tr[x].mx1 = tr[x].mx2 = -inf;
    tr[x].c1 = tr[x].c2 = 0;
    cnt(x, tr[x].v, 1);
    if (lc(x))
        cnt(x, tr[lc(x)].mx1, tr[lc(x)].c1), cnt(x, tr[lc(x)].mx2, tr[lc(x)].c2);
    if (rc(x))
        cnt(x, tr[rc(x)].mx1, tr[rc(x)].c1), cnt(x, tr[rc(x)].mx2, tr[rc(x)].c2);
    tr[x].size = tr[lc(x)].size + tr[rc(x)].size + 1;
}
void pushdown(int x)
{
    if (tr[x].tag)
    {
        swap(lc(x), rc(x));
        tr[lc(x)].tag ^= 1, tr[rc(x)].tag ^= 1, tr[x].tag ^= 1;
    }
    if (tr[x].cha != -inf)
    {
        if (lc(x))
            change(lc(x), tr[x].cha);
        if (rc(x))
            change(rc(x), tr[x].cha);
        tr[x].cha = -inf;
    }
    if (tr[x].add)
    {
        if (lc(x))
            add(lc(x), tr[x].add);
        if (rc(x))
            add(rc(x), tr[x].add);
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

    /*fa[x] = z; fa[y] = x; fa[c[x][k]] = y;
    c[y][!k] = c[x][k]; c[x][k] = y;*/

    // fa(x) = z;
    // fa(y) = x;
    // fa(tr[x].s[k]) = y;
    // tr[y].s[!k] = tr[x].s[k];
    // tr[x].s[k] = y;
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
    if (findroot(y) != x)
        fa(x) = y;
}
void cut(int x, int y)
{
    split(x, y);
    tr[y].s[0] = tr[lc(y)].p = 0;
    pushup(y);
}
void query(int x, int y)
{
    if (tr[y].size == tr[y].c1)
        cout << "ALL SAME\n";
    else
        cout << tr[x].mx2 << ' ' << tr[x].c2 << '\n';
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> T;
    while (T--)
    {
        kns++;
        cout << "Case #" << kns << ":\n";
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            cin >> tr[i].v;

        for (int i = 0; i <= n; i++)
        {
            tr[x].mx1 = tr[x].v;
            tr[x].c1 = tr[x].size = 1;
            tr[x].cha = tr[x].mx2 = -inf, tr[x].c2 = 0;
            tr[x].p = tr[x].s[0] = tr[x].s[1] = tr[x].add = tr[x].tag = 0;
        }
        for (int i = 1; i < n; i++)
        {
            cin >> a >> b;
            link(a, b);
        }
        while (m--)
        {
            cin >> op;
            switch (op)
            {
            case 1:
            {
                cin >> x >> y >> a >> b;
                cut(x, y);
                link(a, b);
                break;
            }
            case 2:
            {
                cin >> a >> b >> w;
                split(a, b);
                change(b, w);
                break;
            }
            case 3:
            {
                cin >> a >> b >> d;
                split(a, b);
                add(b, d);
                break;
            }
            case 4:
            {
                cin >> a >> b;
                split(a, b);
                query(a, b);
                break;
            }
            }
        }
    }
    return 0;
}