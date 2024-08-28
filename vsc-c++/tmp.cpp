// Problem: H. Ksyusha and the Loaded Set
// Contest: Codeforces - Codeforces Round 966 (Div. 3)
// URL: https://codeforces.com/contest/2000/problem/H
// Memory Limit: 512 MB
// Time Limit: 3000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
#include <set>
using namespace std;
const int N = 3e6 + 9;
// 线段树
struct SEG
{
#define INF 4000001
#define ll long long
#define tl(id) (id << 1)
#define tr(id) (id << 1 | 1)
#define li inline
    struct node
    {
        int l, r, len;
        // 0
        ll lmx, rmx, tmx;
    } seg[N << 2];
    li void pushup(node &id, node &l, node &r)
    {
        id.lmx = l.lmx + r.lmx * (l.lmx == l.len);
        id.rmx = r.rmx + l.rmx * (r.rmx == r.len);
        id.tmx = max(l.tmx, max(r.tmx, l.rmx + r.lmx));
    }
#define pushup(id) pushup(seg[id], seg[tl(id)], seg[tr(id)]);
    li int inrange(int L, int R, int l, int r) { return l <= L && R <= r; }
    li int outofrange(int L, int R, int l, int r) { return L > r || R < l; }
    li void build(const int id, int l, int r)
    {
        seg[id] = {l, r, r - l + 1};
        if (l == r)
        {
            seg[id] = {l, r, 1, 1, 1, 1};
            return;
        }
        int mid = (l + r) >> 1;
        build(tl(id), l, mid);
        build(tr(id), mid + 1, r);
        pushup(id);
    }
    li ll query(int id, int l, int r, int v)
    {
        if (l == r)
        {
            return l;
        }
        int mid = (l + r) >> 1;
        if (seg[tl(id)].tmx >= v)
        {
            return query(tl(id), l, mid, v);
        }
        if (seg[tl(id)].rmx + seg[tr(id)].lmx >= v)
        {
            return seg[tl(id)].r - seg[tl(id)].rmx + 1;
        }
        if (seg[tr(id)].tmx >= v)
        {
            return query(tr(id), mid + 1, r, v);
        }
        return 0;
    }
    li void update(int id, int l, int r, int pos, int v)
    {
        if (l == r)
        {
            if (v == 1)
            {
                seg[id] = {l, r, 1, 0, 0, 0};
            }
            if (v == 0)
            {
                seg[id] = {l, r, 1, 1, 1, 1};
            }
            return;
        }
        int mid = (l + r) >> 1;
        if (mid >= pos)
        {
            update(tl(id), l, mid, pos, v);
        }
        else
        {
            update(tr(id), mid + 1, r, pos, v);
        }
        pushup(id);
    }
} t;
void solve()
{
    set<int> st;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        st.insert(x);
        t.update(1, 1, INF, x, 1);
    }
    int m;
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        char op;
        int x;
        cin >> op >> x;
        if (op == '+')
        {
            st.insert(x);
            t.update(1, 1, INF, x, 1);
        }
        else if (op == '-')
        {
            st.erase(x);
            t.update(1, 1, INF, x, 0);
        }
        else
        {
            cout << t.query(1, 1, INF, x) << " ";
        }
    }
    for (auto &i : st)
    {
        t.update(1, 1, INF, i, 0);
    }
    cout << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    t.build(1, 1, INF);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}