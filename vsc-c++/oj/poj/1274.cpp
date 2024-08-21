#include <iostream>
#include <cstring>
using namespace std;
#define ll long long
typedef pair<int, int> Pii;
const int inf = 0x3f3f3f3f;
const int N = 1e3, M = 4e4 + 10;

int n, m, k, a, b, ans;
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
int work()
{
    for (int i = 1; i <= n; i++)
    {
        memset(vis, 0, sizeof vis);
        if (dfs(i))
            ans++;
    }
    return ans;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    while (cin >> n >> m)
    {
        int tmp;
        idx = 0, ans = 0;
        memset(head, 0, sizeof head);
        memset(match, 0, sizeof match);
        for (int i = 1; i <= n; i++)
        {
            cin >> k;
            while (k--)
            {
                cin >> tmp;
                add(i, tmp);
            }
        }
        cout << work() << '\n';
    }
    return 0;
}