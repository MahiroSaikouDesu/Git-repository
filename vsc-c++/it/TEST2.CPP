#include <bits/stdc++.h>
using namespace std;
#define int long long

char d[100][100];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
char now;
bool vis[100][100];
int numb[100][100];
int nowb;
int noww;
int n, m;
int tmp;
set<int> wset[1000];
set<int> cover;

void dfs(int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (xx <= 0 || xx > n || yy <= 0 || yy > m || vis[xx][yy] == true || d[xx][yy] != now)
        {
            continue;
        }
        vis[xx][yy] = true;
        numb[xx][yy] = nowb;
        dfs(xx, yy);
    }
}

void dfsW(int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (xx <= 0 || xx > n || yy <= 0 || yy > m || vis[xx][yy] == true)
        {
            continue;
        }
        if (d[xx][yy] == 'B')
        {
            // cout << numb[xx][yy] << "\n";
            wset[noww].insert(numb[xx][yy]);
        }
        else
        {
            vis[xx][yy] = true;
            dfsW(xx, yy);
        }
    }
}

int getB()
{
    int ans = 0;
    now = 'B';
    memset(vis, false, sizeof vis);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (vis[i][j] == false && d[i][j] == 'B')
            {
                vis[i][j] = true;
                ans++;
                nowb++;
                numb[i][j] = nowb;
                dfs(i, j);
            }
        }
    }
    return ans;
}

bool cmp(set<int> a, set<int> b)
{
    return a.size() > b.size();
}

set<int> getmax()
{
    sort(wset + 1, wset + 1 + noww, cmp);
    return wset[1];
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
                vis[i][j] = true;
                noww++;
                dfsW(i, j);
            }
        }
    }

    while (tmp > 1)
    {
        set<int> maxx = getmax();
        tmp -= maxx.size() - 1;
        int fr = *maxx.begin();
        maxx.erase(maxx.begin());
        cover.insert(maxx.begin(), maxx.end());
        for (int i = 1; i <= noww; i++)
        {
            for (auto it : maxx)
            {
                if (wset[i].erase(it) == 1)
                    wset[i].insert(fr);
            }
        }
        ans++;
    }
    return ans;
}

void tmmp()
{
    // memset(d, 0, sizeof d);
    memset(numb, 0, sizeof numb);
    // memset(vis, false, sizeof vis);
    //  wset->clear();
    cover.clear();
    now = 0;
    nowb = 0;
    noww = 0;
    n = 0, m = 0;
    tmp = 0;

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> d[i][j];
        }
    }
    int num = getB();
    tmp = num;
    if (num == 0 || num == 1)
    {
        cout << num;
        return;
    }
    int num2 = getW();
    // cout << num2 << "\n";
    // cout << num << "\n";
    cout << min(num2 + 1, num) << '\n';
}

signed main()
{
    int t = 10;
    while (t--)
        tmmp();
}
