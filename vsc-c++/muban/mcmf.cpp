int idx, head[N], d[N], pre[N], n, m, s, t;
bool vis[N];
struct node
{
    int v, nxt, cap, flow, cost;
} e[M << 1];
void adde(int u, int v, int c, int cost)
{
    e[idx].v = v;
    e[idx].cap = c;
    e[idx].flow = 0;
    e[idx].cost = cost;
    e[idx].nxt = head[u];
    head[u] = idx++;
}
void add(int u, int v, int c, int cost)
{
    adde(u, v, c, cost);
    adde(v, u, 0, -cost);
}
bool SPFA(int s, int t)
{
    queue<int> q;
    memset(vis, false, sizeof vis);
    memset(pre, -1, sizeof pre);
    memset(d, 0x3f, sizeof d);
    vis[s] = 1;
    d[s] = 0;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for (int i = head[u]; ~i; i = e[i].nxt)
        {
            int v = e[i].v;
            if (e[i].cap > e[i].flow && d[v] > d[u] + e[i].cost)
            {
                d[v] = d[u] + e[i].cost;
                pre[v] = i;
                if (!vis[v])
                {
                    q.push(v);
                    vis[v] = 1;
                }
            }
        }
    }
    return pre[t] != -1;
}
int MCMF(int s, int t)
{
    int dis = 0, mincost = 0, maxflow = 0;
    while (SPFA(s, t))
    {
        dis = inf;
        for (int i = pre[t]; ~i; i = pre[e[i ^ 1].v])
            dis = min(dis, e[i].cap - e[i].flow);
        for (int i = pre[t]; ~i; i = pre[e[i ^ 1].v])
            e[i].flow += dis, e[i ^ 1].flow -= dis;
        maxflow += dis;
        mincost += d[t] * dis;
    }
    return mincost;
}