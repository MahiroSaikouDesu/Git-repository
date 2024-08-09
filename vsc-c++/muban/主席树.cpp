int n, m, a[N], root[N], idx;
vector<int> v;
#define lc(x) tr[x].ch[0]
#define rc(x) tr[x].ch[1]
struct node
{
    int ch[2], siz;
} tr[N * 25];
void build(int &x, int l, int r)
{
    x = ++idx;
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    build(lc(x), l, mid);
    build(rc(x), mid + 1, r);
}
void insert(int x, int &y, int l, int r, int v)
{
    y = ++idx, tr[y] = tr[x], tr[y].siz++;
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    if (v <= mid) // 双指针同步搜索
        insert(lc(x), lc(y), l, mid, v);
    else
        insert(rc(x), rc(y), mid + 1, r, v);
}
int query(int x, int y, int l, int r, int k)
{
    if (l == r)
        return l;
    int mid = (l + r) >> 1; // 双指针同步搜索
    int s = tr[lc(y)].siz - tr[lc(x)].siz;
    if (k <= s)
        return query(lc(x), lc(y), l, mid, k);
    else
        return query(rc(x), rc(y), mid + 1, r, k - s);
}