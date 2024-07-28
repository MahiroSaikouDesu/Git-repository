const int inf = 0x3f3f3f3f << 1;
int cap[N][N], flow[N][N];
int pre[N], res[N];
bool vis[N];
queue<int> q;
bool bfs(int s, int t)
{
    memset(pre, -1, sizeof pre);
    memset(vis, false, sizeof vis);
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = head[u]; ~i; i = e[i].nxt)
        {
            int v = e[i].v;
            if (!vis[v] && e[i].cap > e[i].flow)
            {
                vis[v] = true;
                pre[v] = u;
                q.push(v);
                if (v == t)
                    return 1;
            }
        }
    }
    return 0;
}
int ek(int s, int t)
{
    int maxflow = 0;
    while (bfs(s, t))
    {
        int d = inf, v = t;
        while (v != s)
        {
            int i = pre[v];
            d = min(d, )
        }
    }
}