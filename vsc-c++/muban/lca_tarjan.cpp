int fa[N], dis[N];
bool vis[N];
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
    for (auto i : mp[u])
    {
        if (vis[i])
            continue;
        dis[i] = dis[u] + 1;
        tarjan(i);
        fa[i] = u;
    }
    for (auto i : query[u])
    {
        if (!vis[i])
            continue;
        ans[query_id[{u, i}]] = dis[u] + dis[i] - 2 * dis[fafind(i)];
    }
}

void init()
{
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    memset(vis, false, sizeof vis);
    ans.resize(q + 5);
    mp.clear();
    mp.resize(n + 10);
    query.clear();
    query.resize(n + 10);
    query_id.clear();
}