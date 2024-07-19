int fa[N], dis[N], ans[N], n, T;
bool vis[N];
vector<Pii> mp[N], query[N]; // (int -> Pii) => + distance
int fafind(int x)
{
    if (x == fa[x])
        return x;
    return fa[x] = fafind(fa[x]);
}
void tarjan(int u, int len)
{
    vis[u] = 1;
    dis[u] = len;
    for (auto i : mp[u])
    {
        if (vis[i.first])
            continue;
        tarjan(i, len + i.second);
        fa[i.first] = u;
    }
    for (auto i : query[u])
    {
        if (!vis[i.first])
            continue;
        ans[i.second] = dis[u] + dis[i.first] - 2 * dis[fafind(i.first)];
    }
}
void init()
{
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    memset(vis, false, sizeof vis);
}