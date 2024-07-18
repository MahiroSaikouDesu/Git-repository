#include <map>
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;
#define ll long long
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;
const int N = 1e4 + 10;

int fa[N], n, q = 1, t1, t2, ans;
bool vis[N], vis2[N];
vector<vector<int>> mp; // (int -> Pii) => + distance
int fafind(int x)
{
    if (x == fa[x])
        return x;
    return fa[x] = fafind(fa[x]);
}
void tarjan(int u)
{
    if (ans)
        return;
    vis[u] = 1;
    for (vector<int>::iterator it = mp[u].begin(); it != mp[u].end(); it++)
    {
        int i = (*it);
        if (vis[i])
            continue;
        tarjan(i);
        if (ans)
            return;
        fa[i] = u;
    }
    if (u == t1 && vis[t2])
        ans = fafind(t2);
    if (u == t2 && vis[t1])
        ans = fafind(t1);
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        ans = 0;
        cin >> n;
        mp.clear();
        mp.resize(n + 10);
        memset(vis, false, sizeof vis);
        memset(vis2, false, sizeof vis2);
        for (int i = 1; i <= n; i++)
            fa[i] = i;
        for (int i = 1; i < n; i++)
        {
            int u, v;
            cin >> u >> v;
            mp[u].push_back(v);
            vis2[v] = true;
        }
        int root;
        for (int i = 1; i <= n; i++)
            if (!vis2[i])
            {
                root = i;
                break;
            }
        // cout << "R: " << root << '\n';
        cin >> t1 >> t2;
        tarjan(root);
        cout << ans << '\n';
    }
    return 0;
}