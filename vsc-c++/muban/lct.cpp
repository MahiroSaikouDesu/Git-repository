#define fa(x) tr[x].p
#define lc(x) tr[x].s[0]
#define rc(x) tr[x].s[1]
#define notroot(x) lc(fa(x)) == x || rc(fa(x)) == x
int n, m;
struct node
{
    int s[2], p, v, sum, tag;
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
}
void rotate(int x)
{
    int y = fa(x), z = fa(y);
    int k = rc(y) == x;
    if(notroot(y)) 
}
