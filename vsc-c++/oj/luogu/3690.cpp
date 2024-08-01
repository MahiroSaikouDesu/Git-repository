#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;
const int N = 1e5 + 10;

#define fa(x) tr[x].p
#define lc(x) tr[x].s[0]
#define rc(x) tr[x].s[1]
#define notroot(x) lc(fa(x)) == x || rc(fa(x)) == x
int n, m, a, b, c;
struct node
{
    int s[2], p, v, sum, tag;
} tr[N];
void pushup(int x)
{
    tr[x].sum = tr[lc(x)].sum ^ tr[x].v ^ tr[rc(x)].sum;
}
void pushdown(int x) // reverse(x)
{
    if (tr[x].tag)
    {
        swap(lc(x), rc(x));
        tr[lc(x)].tag ^= 1, tr[rc(x)].tag ^= 1;
        tr[x].tag = 0;
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
    for (int y = 0; x;)
    {
        splay(x);
        rc(x) = y;
        pushup(x);
        y = x, x = fa(x);
    }
}
void makeroot(int x)
{
    access(x);
    splay(x);
    tr[x].tag ^= 1;
}
void split(int x, int y) // 離れて
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
    makeroot(x);
    if (findroot(y) == x && fa(y) == x && !lc(y))
    {
        rc(x) = fa(y) = 0;
        pushup(x);
    }
}
void change(int x, int v)
{
    splay(x);
    tr[x].v = v;
    pushup(x);
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> tr[i].v;
    while (m--)
    {
        cin >> a >> b >> c;
        switch (a)
        {
        case 0:
        {
            split(b, c);
            cout << tr[c].sum << '\n';
            break;
        }
        case 1:
        {
            link(b, c);
            break;
        }
        case 2:
        {
            cut(b, c);
            break;
        }
        case 3:
        {
            change(b, c);
            break;
        }
        }
    }
    return 0;
}