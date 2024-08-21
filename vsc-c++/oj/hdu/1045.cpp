#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> Pii;
const int inf = 0x3f3f3f3f;
const int N = 300, M = 10;

int n, m, a, b, ans;
struct node
{
    int v, nxt;
} e[N];
int idx, head[N], vis[N], match[N], cntcol, cntrow, row[M][M], col[M][M], mp[M][M];
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
    ans = 0;
    for (int i = 1; i < cntrow; i++)
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
    while (cin >> n && n)
    {
        idx = 0;
        char ch;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                cin >> ch;
                mp[i][j] = ch == '.' ? 1 : 0;
                row[i][j] = col[i][j] = 0;
            }

        cntcol = cntrow = 1;

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                if (mp[i][j] && !col[i][j])
                {
                    for (int k = i; k <= n && mp[k][j]; k++)
                        col[k][j] = cntcol;
                    cntcol++;
                }
                if (mp[i][j] && !row[i][j])
                {
                    for (int k = j; k <= n && mp[i][k]; k++)
                        row[i][k] = cntrow; 
                    cntrow++;
                }
            }

        memset(head, 0, sizeof head);
        memset(match, 0, sizeof match);

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (mp[i][j])
                    add(row[i][j], col[i][j]);

        cout << hungarian() << '\n';
    }
    return 0;
}