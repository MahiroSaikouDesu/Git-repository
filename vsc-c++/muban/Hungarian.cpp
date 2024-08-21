int n, m, a, b, ans;
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
int hungarian()
{
    for (int i = 1; i <= n; i++)
    {
        memset(vis, 0, sizeof vis);
        if (dfs(i))
            ans++;
    }
    return ans;
}