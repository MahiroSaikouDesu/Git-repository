#include <cmath>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
#define ll long long
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;
const int N = 1e4 + 10, M = 3e4, K = 20;

int pos[N], seq[2 * N - 1], dep[2 * N - 1], F[2 * N - 1][K], tot, n;
//|| pos - first time meet || seq - Euler list || F - ST // the deepest index || dep - depth
bool vis[N], vis2[N];
vector<vector<int>> mp; // (int -> Pii) => + distance

void dfs(int u, int d)
{
    vis[u] = true;
    pos[u] = ++tot;
    seq[tot] = u;
    dep[tot] = d;
    for (vector<int>::iterator it = mp[u].begin(); it != mp[u].end(); it++)
    {
        int i = (*it);
        if (vis[i])
            continue;
        dfs(i, d + 1);
        seq[++tot] = u;
        dep[tot] = d;
    }
}
void stCreate()
{
    for (int i = 1; i <= tot; i++)
        F[i][0] = i;
    int k = log2(tot);
    for (int j = 1; j <= k; j++)
        for (int i = 1; i <= tot - (1 << j) + 1; i++)
            F[i][j] = dep[F[i][j - 1]] < dep[F[i + (1 << (j - 1))][j - 1]] ? F[i][j - 1] : F[i + (1 << (j - 1))][j - 1];
}
int RMQ_query(int l, int r)
{
    int k = log2(r - l + 1);
    return dep[F[l][k]] < dep[F[r - (1 << k) + 1][k]] ? F[l][k] : F[r - (1 << k) + 1][k];
}
int LCA(int x, int y)
{
    int l = pos[x], r = pos[y]; // l <= r
    if (l > r)
        swap(l, r);
    return seq[RMQ_query(l, r)];
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n;
        mp.clear();
        mp.resize(n + 10);
        tot = 0;
        memset(vis, false, sizeof vis);
        memset(vis2, false, sizeof vis2);
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
        dfs(root, 1);
        stCreate();
        int u, v;
        cin >> u >> v;
        cout << LCA(u, v) << '\n';
    }
    return 0;
}