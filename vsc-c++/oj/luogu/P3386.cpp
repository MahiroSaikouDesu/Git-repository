#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> Pii;
const int inf = 0x3f3f3f3f;
const int N = 1e3, M = 5e4 + 10;

int n, m, k, a, b, ans;
struct node
{
    int v, nxt;
} e[M];
int idx, head[N], vis[N], match[N];
void add(int a, int b)
{
    e[++idx] = {b, head[a]};
    head[a] = idx;
}
bool dfs(int u)
{
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v;
        if (vis[v])
            continue;
        vis[v] = 1;
        if (!match[v] || dfs(match[v]))
        {
            match[v] = u;
            return 1;
        }
    }
    return 0;
}
int work()
{
    for (int i = 1; i <= n; i++)
    {
        memset(vis, 0, sizeof vis);
        if (dfs(i))
            ans++;
    }
    return ans;
}
map<Pii, bool> mp;
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int u, v;
    cin >> n >> m >> k;
    while (k--)
    {
        cin >> u >> v;
        if (mp.find({u, v}) != mp.end())
            continue;
        mp[{u, v}] = true;
        add(u, v);
    }
    cout << work() << '\n';
    return 0;
}