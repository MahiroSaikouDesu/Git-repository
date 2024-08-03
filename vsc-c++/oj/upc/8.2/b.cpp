#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> Pii;
const int inf = 0x3f3f3f3f << 1;
const int N = 1e8;
int n, m, ans;
#define lc(x) tr[x].s[0]
#define rc(x) tr[x].s[1]
struct node
{
    int s[2], val;
};
vector<node> tr;
vector<bool> vis;
void dfs(int x)
{
    if (lc(x))
    {
        dfs(lc(x));
        if (tr[lc(x)].val < tr[x].val)
            ans++;
    }
    if (rc(x))
    {
        dfs(rc(x));
        if (tr[rc(x)].val <= tr[x].val)
            ans++;
    }
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    tr.resize(n + 10);
    vis.resize(n + 10);
    for (int i = 1; i <= n; i++)
    {
        cin >> lc(i) >> rc(i) >> tr[i].val;
        vis[lc(i)] = true;
        vis[rc(i)] = true;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
            break;
        }
    }
    cout << ans;
    return 0;
}