#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
const int N = 1e4 + 10;
struct EDGE
{
    int to, d, nex;
} e[N * 2];
int n, k, pnum;
int head[N], len;
int vis[N];
int son[N], max_son[N];
void Init()
{
    for (int i = 0; i <= n; i++)
    {
        head[i] = -1;
        vis[i] = 0;
    }
    len = 0;
}
void AddEdge(int x, int y, int z)
{
    e[len].to = y;
    e[len].d = z;
    e[len].nex = head[x];
    head[x] = len++;
}
void getroot(int u, int fa, int &root, int &minn)
{
    son[u] = 1;
    max_son[u] = 0;
    int to;
    for (int i = head[u]; i != -1; i = e[i].nex)
    {
        to = e[i].to;
        if (to == fa || vis[to])
            continue;
        getroot(to, u, root, minn);
        son[u] += son[to];
        max_son[u] = max(max_son[u], son[to]);
    }
    max_son[u] = max(max_son[u], pnum - son[u]);
    if (max_son[u] < minn)
    {
        minn = max_son[u];
        root = u;
    }
}
vector<int> dis;
void getdis(int u, int fa, int d)
{
    dis.push_back(d);
    int to;
    for (int i = head[u]; i != -1; i = e[i].nex)
    {
        to = e[i].to;
        if (to == fa || vis[to])
            continue;
        getdis(to, u, d + e[i].d);
    }
}
int getnum(int u, int d)
{
    int res = 0;
    dis.clear();
    getdis(u, -1, d);
    sort(dis.begin(), dis.end());
    int l = dis.size();
    for (int i = 0; i < l; i++)
    {
        if (dis[i] > k)
            break;
        res += upper_bound(dis.begin(), dis.end(), k - dis[i]) - lower_bound(dis.begin(), dis.end(), k - dis[i]);
    }
    //   cout << u << " " << res << endl;
    return res;
}
int dfs(int u)
{
    int minn = N, root;
    getroot(u, -1, root, minn);
    vis[root] = 1;
    int res = 0;
    res += getnum(root, 0);
    int to;
    for (int i = head[root]; i != -1; i = e[i].nex)
    {
        to = e[i].to;
        if (vis[to])
            continue;
        pnum = son[to];
        res -= getnum(to, e[i].d);
        res += dfs(to);
    }
    return res;
}
int main()
{
    int x, y, z = 1;
    int res;
    while (~scanf("%d", &n) && n)
    {
        Init();
        for (int i = 1; i <= n; i++)
        {
            while (scanf("%d", &x) && x)
            {
                scanf("%d", &z);
                AddEdge(x, i, z);
                AddEdge(i, x, z);
            }
        }
        while (scanf("%d", &k) && k)
        {
            for (int i = 1; i <= n; i++)
                vis[i] = 0;
            pnum = n;
            res = dfs(1);
            // cout << res << endl;
            printf(res ? "AYE\n" : "NAY\n");
        }
        printf(".\n");
    }
    return 0;
}