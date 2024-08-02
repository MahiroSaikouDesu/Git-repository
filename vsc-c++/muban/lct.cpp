#define fa(x) tr[x].p
#define lc(x) tr[x].s[0]
#define rc(x) tr[x].s[1]
#define notroot(x) lc(fa(x)) == x || rc(fa(x)) == x
int n, m;
struct node
{
    int s[2], p, v, sum, tag, add;
} tr[N];
void pushup(int x)
{
    tr[x].sum = tr[lc(x)].sum ^ tr[x].v ^ tr[rc(x)].sum;
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
void add(int w, int x, int y)
{
    split(x, y);
    tr[y].add += w;
    tr[y].v += w;
}