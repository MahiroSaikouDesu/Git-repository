#include <iostream>
#include <cstring>
using namespace std;
#define ll long long
typedef pair<int, int> Pii;
const int inf = 0x3f3f3f3f;
const int N = 1e3 + 10, M = N * N;

int n, m, k, a, b, c;
struct node
{
    int v, nxt;
} e[M];
int idx, head[N], vis[N], match[N], done[N];
void add(int a, int b)
{
    e[++idx] = {b, head[a]};
    head[a] = idx;
}
int dfs(int u)
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
int work()
{
    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        memset(vis, 0, sizeof vis);
        ans += dfs(i);
    }
    return ans;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    while (cin >> n && n)
    {
        idx = 0;
        memset(head, 0, sizeof head);
        memset(done, 0, sizeof done);
        memset(match, 0, sizeof match);
        cin >> m >> k;
        for (int i = 1; i <= k; i++)
        {
            cin >> a >> b >> c;
            if (b * c != 0)
                add(b, c);
        }
        cout << work() << '\n';
    }
    return 0;
}