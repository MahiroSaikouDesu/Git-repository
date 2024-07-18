#include <map>
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;
#define ll long long
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;
const int N = 1e4 + 10;

int fa[N], n, q = 1;
bool vis[N], vis2[N];
vector<int> ans;
vector<vector<int>> mp, query; // (int -> Pii) => + distance
map<Pii, int> query_id;
int fafind(int x)
{
    if (x == fa[x])
        return x;
    return fa[x] = fafind(fa[x]);
}
void tarjan(int u)
{
    vis[u] = 1;
    for (vector<int>::iterator it = mp[u].begin(); it != mp[u].end(); it++)
    {
        int i = (*it);
        if (vis[i])
            continue;
        tarjan(i);
        fa[i] = u;
    }
    for (vector<int>::iterator it = query[u].begin(); it != query[u].end(); it++)
    {
        int i = (*it);
        if (!vis[i] || query_id.find(make_pair(u, i)) == query_id.end())
            continue;
        ans[query_id[make_pair(u, i)]] = fafind(i);
    }
}

void init()
{
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    memset(vis, false, sizeof vis);
    memset(vis2, false, sizeof vis2);
    ans.resize(q + 10);
    mp.clear();
    mp.resize(n + 10);
    query.clear();
    query.resize(n + 10);
    query_id.clear();
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n;
        init();
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
        for (int i = 1; i <= q; i++)
        {
            int t1, t2;
            cin >> t1 >> t2;
            query_id[make_pair(t1, t2)] = i;
            query_id[make_pair(t2, t1)] = i;
            query[t1].push_back(t2);
            query[t2].push_back(t1);
        }
        tarjan(root);
        for (int i = 1; i <= q; i++)
            cout << ans[i] << '\n';
    }
    return 0;
}