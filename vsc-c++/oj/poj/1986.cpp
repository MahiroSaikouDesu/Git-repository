#include <vector>
#include <map>
#include <iostream>
#include <stdio.h>
using namespace std;
#define ll long long
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;
#include <cstring>
const int N = 80010;

int n, m;
int fa[N], dis[N];
bool vis[N];
int ans[N];
vector<Pii> mp[N], query[N]; // (int -> Pii) => + distance
int fafind(int x)
{
    if (x == fa[x])
        return x;
    return fa[x] = fafind(fa[x]);
}
void tarjan(int u)
{
    vis[u] = true;
    for (int j = 0; j < mp[u].size(); j++)
    {
        Pii i = mp[u][j];
        if (vis[i.first])
            continue;
        dis[i.first] = dis[u] + i.second;
        tarjan(i.first);
        fa[i.first] = u;
    }
    for (int j = 0; j < query[u].size(); j++)
    {
        Pii i = query[u][j];
        if (!vis[i.first])
            continue;
        ans[i.second] = dis[u] + dis[i.first] - 2 * dis[fafind(i.first)];
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    scanf("%d %d", &n, &m);
    int T, a, b, l;
    char d;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d %d %d %c", &a, &b, &l, &d);
        mp[a].push_back(make_pair(b, l));
        mp[b].push_back(make_pair(a, l));
    }
    scanf("%d", &T);
    for (int i = 1; i <= T; i++)
    {
        scanf("%d %d", &a, &b);
        query[a].push_back(make_pair(b, i));
        query[b].push_back(make_pair(a, i));
    }

    for (int i = 1; i <= n; i++)
        fa[i] = i;
    tarjan(1);

    for (int i = 1; i <= T; i++)
        printf("%d\n", ans[i]);

    return 0;
}