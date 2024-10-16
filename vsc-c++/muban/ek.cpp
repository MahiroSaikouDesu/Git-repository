struct node
{
    int t, cap, flow, nxt;
} e[M << 1];
int n, idx, pre[N], vis[N], head[N];
void add(int x, int y, int z)
{
    e[idx].t = y;
    e[idx].cap = z;
    e[idx].flow = 0;
    e[idx].nxt = head[x];
    head[x] = idx++;

    e[idx].t = x;
    e[idx].cap = 0;
    e[idx].flow = 0;
    e[idx].nxt = head[y];
    head[y] = idx++;
}
bool bfs(int s, int t)
{
    memset(pre, -1, sizeof pre);
    memset(vis, 0, sizeof vis);
    vis[s] = 1;
    queue<int> q;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = head[u]; ~i; i = e[i].nxt)
        {
            int v = e[i].t;
            if (vis[v] || e[i].cap <= e[i].flow)
                continue;
            pre[v] = i;
            if (v == t)
                return 1;
            vis[v] = 1;
            q.push(v);
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
            d = min(d, e[i].cap - e[i].flow);
            v = e[i ^ 1].t;
        }
        maxflow += d;
        v = t;
        while (v != s)
        {
            int i = pre[v];
            e[i].flow += d;
            e[i ^ 1].flow -= d;
            v = e[i ^ 1].t;
        }
    }
    return maxflow;
}