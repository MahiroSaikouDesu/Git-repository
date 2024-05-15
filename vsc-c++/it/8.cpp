#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int, int> P;
char d[100][100];
vector<P> wf;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
char now;
bool vis[100][100], visb[100000];
int bz[100][100], f[100000];
int n, m, cnt;

void dfs(int x, int y)
{
    bz[x][y] = cnt;
    for (int i = 0; i < 4; i++)
    {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (xx <= 0 || xx > n || yy <= 0 || yy > m || vis[xx][yy] == true || d[xx][yy] != now)
        {
            continue;
        }
        vis[xx][yy] = true;
        dfs(xx, yy);
    }
}

int getB()
{
    int ans = 0;
    now = 'B';
    memset(vis, false, sizeof(vis));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (vis[i][j] == false && d[i][j] == 'B')
            {
                cnt++;
                vis[i][j] = true;
                ans++;
                dfs(i, j);
            }
        }
    }
    return ans;
}

int getW()
{
    int ans = 0;
    now = 'W';
    memset(vis, false, sizeof(vis));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (vis[i][j] == false && d[i][j] == 'W')
            {
                wf.push_back({i, j});
                vis[i][j] = true;
                ans++;
                dfs(i, j);
            }
        }
    }
    return ans;
}

set<int> dfsw(int x, int y)
{
    set<int> ans;
    memset(vis, false, sizeof vis);
    memset(visb, false, sizeof visb);

    queue<P> q;
    q.push({x, y});

    while (!q.empty())
    {
        P now = q.front();
        q.pop();
        if (vis[now.first][now.second] == true)
            continue;
        vis[now.first][now.second] = true;
        for (int i = 0; i < 4; i++)
        {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx <= 0 || xx > n || yy <= 0 || yy > m || vis[xx][yy] == true)
                continue;

            if (d[xx][yy] != 'W')
            {
                if (visb[bz[xx][yy]])
                    continue;
                visb[bz[xx][yy]] = true;
                ans.insert(bz[xx][yy]);
            }
            else
                q.push({xx, yy});
        }
    }
    return ans;
}

struct node
{
    set<int> w;
    node(set<int> b) { w = b; }
    bool operator<(const node &a) const
    {
        return w.size() < a.w.size();
    }
};

int find(int x)
{
    return f[x] == x ? x : f[x] = find(f[x]);
}

int work()
{
    int ans = 0;
    priority_queue<node> q;
    // 找连接了哪几组b
    for (auto &t : wf)
        q.push(node(dfsw(t.first, t.second)));
    while (!q.empty() && cnt > 1)
    {
        node now = q.top();
        q.pop();
        int flag = 1;
        // 检查b是否被连接过了
        for (auto &t : now.w)
        {
            if (find(t) != t)
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            cnt -= now.w.size() - 1;
            ans++;
            int fr = *now.w.begin();
            auto it = now.w.begin();
            it++;
            for (; it != now.w.end(); it++)
            {
                f[*it] = fr;
            }
        }
        else
        {
            set<int> ne;
            for (auto &t : now.w)
                if (find(t) == t)
                    ne.insert(t);
            q.push(node(ne));
        }
    }
    return ans;
}

signed main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> d[i][j];
        }
    }

    // num - B num2 - W
    int num2 = getW();
    int num = getB();

    for (int i = 1; i <= cnt; i++)
        f[i] = i;
        
    int wused = work() + 1;
    cout << min(wused, num);
}
