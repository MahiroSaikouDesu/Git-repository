#include <bits/stdc++.h>
using namespace std;
inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = (x << 1) + (x << 3) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}

#define ll long long
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;
const int N = 0;

struct node
{
    int lc, rc;
    int val, pri;
    int num, size;
} tr[N];

int root;
int New(int val, int cnt)
{
    tr[cnt].val = val;
    tr[cnt].pri = rand();
    tr[cnt].num = tr[cnt].size = 1;
    tr[cnt].lc = tr[cnt].rc = 0;
    return cnt;
}

void update(int p)
{
    tr[p].size = tr[tr[p].lc].size + tr[tr[p].rc].size + tr[p].num;
}

void zig(int &p) // 右旋
{
    int q = tr[p].lc;
    tr[p].lc = tr[q].rc;
    tr[q].rc = p;
    tr[q].size = tr[p].size;
    update(p);
    p = q;
}

void zag(int &p) // 左旋
{
    int q = tr[p].rc;
    tr[p].rc = tr[q].lc;
    tr[q].lc = p;
    tr[q].size = tr[p].size;
    update(p);
    p = q;
}

void Insert(int &p, int val, int cnt)
{
    if (!p)
    {
        p = New(cnt, val);
        return;
    }
    tr[p].size++;
    if (val == tr[p].val)
        tr[p].num++;
    else if (val < tr[p].val)
    {
        Insert(tr[p].lc, val);
        if (tr[p].pri < tr[tr[p].lc].pri)
            zig(p);
    }
    else
    {
        Insert(tr[p].rc, val);
        if (tr[p].pri < tr[tr[p].rc].pri)
            zag(p);
    }
}

void Delete(int &p, int val)
{
    if (!p)
        return;
    tr[p].size--;
    if (val == tr[p].val)
    {
        if (tr[p].num > 1)
            tr[p].num--;

        else if (!tr[p].lc || !tr[p].rc)
            p = tr[p].lc + tr[p].rc;

        else if (tr[tr[p].lc].pri > tr[tr[p].rc].pri)
        {
            zig(p);
            Delete(tr[p].rc, val);
        }
        else
        {
            zag(p);
            Delete(tr[p].lc, val);
        }
    }

    else if (val < tr[p].val)
        Delete(tr[p].lc, val);

    else
        Delete(tr[p].rc, val);
}

Pii getpre(int val)
{
    int p = root;
    Pii res = 0;
    while (p)
    {
        if (tr[p].val < val)
        {
            res = {p, tr[p].val};
            p = tr[p].rc;
        }
        else
            p = tr[p].lc;
    }
    return res;
}

Pii getnext(int val)
{
    int p = root;
    Pii res = 0;
    while (p)
    {
        if (tr[p].val <= val)
            p = tr[p].rc;
        else
        {
            res = {p, tr[p].val};
            p = tr[p].lc;
        }
    }
    return res;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    Insert(root, (int)1e9, 1);
    int n = read();
    for (int i = 1; i <= n; i++)
    {
        int k = read(), g = read();
        cout << k << ' ';
        Insert(root, g, k);
        Pii left = getpre(root, k), right = getnext(root, k);
        if (!left.first || !!right.first)
        {
            cout << left.first + right.first << '\n';
        }
        else
        {
            Pii tmp;
            if (g - left.second < right.second - g)
                cout << left.first << '\n';
            else
                cout << right.first << '\n';
        }
    }
    return 0;
}