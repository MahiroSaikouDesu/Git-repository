#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;
inline int read()
{
    int s = 0, w = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            w = -1;
        ch = getchar();
    }
    while ('0' <= ch && ch <= '9')
        s = (s << 1) + (s << 3) + (ch ^ 48), ch = getchar();
    return s * w;
}
const double alpha = 0.75;
const int K = 2;
struct K_D_Tree
{
    int l, r, sum, val, size, Min[K], Max[K], d[K];
} tr[MAXN];
int n, ans, root, len;
int p[K], q[K][2], A;
int D, num, h[MAXN];
bool cmp(const int &a, const int &b)
{
    return tr[a].d[D] < tr[b].d[D];
}
inline void update(int x)
{
    int l = tr[x].l, r = tr[x].r;
    tr[x].size = tr[l].size + tr[r].size + 1;
    tr[x].sum = tr[l].sum + tr[r].sum + tr[x].val;
    for (int i = 0; i < K; i++)
    {
        if (l)
            tr[x].Max[i] = max(tr[l].Max[i], tr[x].Max[i]), tr[x].Min[i] = min(tr[l].Min[i], tr[x].Min[i]);
        if (r)
            tr[x].Max[i] = max(tr[r].Max[i], tr[x].Max[i]), tr[x].Min[i] = min(tr[r].Min[i], tr[x].Min[i]);
    }
}
inline void build(int &x, int l, int r, int k)
{
    if (l > r)
        return;
    int mid = (l + r) >> 1;
    D = k;
    nth_element(h + l, h + mid + 1, h + r + 1, cmp);
    x = h[mid];
    tr[x].sum = tr[x].val;
    for (int i = 0; i < K; i++)
        tr[x].Max[i] = tr[x].Min[i] = tr[x].d[i];
    build(tr[x].l, l, mid - 1, (k + 1) % K);
    build(tr[x].r, mid + 1, r, (k + 1) % K);
    update(x);
}
inline void erase(int &x)
{
    if (!x)
        return;
    h[++num] = x;
    erase(tr[x].l), erase(tr[x].r);
    x = 0;
}
inline void rebuild(int &x, int k)
{
    h[num = 1] = ++len;
    tr[len].size = 1;
    for (int i = 0; i < K; i++)
        tr[len].d[i] = p[i];
    tr[len].val = tr[len].sum = A;
    erase(x), build(x, 1, num, k);
}
inline void insert(int &x, int k)
{
    if (!x)
    {
        tr[x = ++len].size = 1, tr[x].val = tr[x].sum = A;
        for (int i = 0; i < K; i++)
            tr[x].Max[i] = tr[x].Min[i] = tr[x].d[i] = p[i];
        return;
    }
    if (p[k] < tr[x].d[k])
    {
        if (tr[tr[x].l].size > tr[x].size * alpha)
            rebuild(x, k);
        else
            insert(tr[x].l, (k + 1) % K);
    }
    else
    {
        if (tr[tr[x].r].size > tr[x].size * alpha)
            rebuild(x, k);
        else
            insert(tr[x].r, (k + 1) % K);
    }
    update(x);
}
inline bool check_range(int x)
{
    if (!x)
        return 0;
    for (int i = 0; i < K; i++)
        if (q[i][0] > tr[x].Min[i] || q[i][1] < tr[x].Max[i])
            return 0;
    return 1;
}
inline bool check_point(int x)
{
    if (!x)
        return 0;
    for (int i = 0; i < K; i++)
        if (tr[x].d[i] < q[i][0] || tr[x].d[i] > q[i][1])
            return 0;
    return 1;
}
inline bool check(int x)
{
    if (!x)
        return 0;
    for (int i = 0; i < K; i++)
        if (q[i][1] < tr[x].Min[i] || q[i][0] > tr[x].Max[i])
            return 0;
    return 1;
}
inline void query(int x)
{
    if (check_range(x))
    {
        ans += tr[x].sum;
        return;
    }
    if (check_point(x))
        ans += tr[x].val;
    if (check(tr[x].l))
        query(tr[x].l);
    if (check(tr[x].r))
        query(tr[x].r);
}
int main()
{
    n = read();
    while (1)
    {
        int opt = read();
        if (opt == 1)
        {
            for (int i = 0; i < K; i++)
                p[i] = read() ^ ans;
            A = read() ^ ans;
            insert(root, 0);
        }
        if (opt == 2)
        {
            for (int i = 0; i <= 1; i++)
                for (int j = 0; j < K; j++)
                    q[j][i] = read() ^ ans;
            ans = 0;
            query(root);
            printf("%d\n", ans);
        }
        if (opt == 3)
            break;
    }
    return 0;
}