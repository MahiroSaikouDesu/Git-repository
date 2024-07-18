int pos[N], seq[2 * N - 1], dep[2 * N - 1], F[2 * N - 1][K], tot;
//|| pos - first time meet || seq - Euler list || F - ST // the deepest index || dep - depth
bool vis[N];
vector<vector<int>> mp; // (int -> Pii) => + distance
void dfs(int u, int d)
{
    vis[u] = true;
    pos[u] = ++tot;
    seq[tot] = u;
    dep[tot] = d;
    for (auto i : mp[u])
    {
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