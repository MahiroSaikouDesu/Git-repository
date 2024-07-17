#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;
#define int long long
int read()
{
    int sum = 0, f = 1;
    char a = getchar();
    while (a < '0' || a > '9')
    {
        if (a == '-')
            f *= -1;
        a = getchar();
    }
    while (a >= '0' && a <= '9')
    {
        sum = (sum << 3) + (sum << 1) + a - '0';
        a = getchar();
    }
    return f * sum;
}

const int N = 2e5 + 10;
vector<int> ma[N];
int vis[N], n, m, ans;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        ma[a].push_back(b);
        ma[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
            continue;
        int nowcnt = 0, nowedge = 0;
        queue<int> q;
        vis[i] = 1;
        q.push(i);
        while (!q.empty())
        {
            int f = q.front();
            q.pop();
            nowcnt++;
            nowedge += ma[f].size();
            for (int next : ma[f])
            {

                if (vis[next])
                    continue;
                q.push(next);
                vis[next] = 1;
            }
        }
        nowedge /= 2;
        ans += nowcnt * (nowcnt - 1) / 2 - nowedge;
    }
    cout << ans;
    return 0;
}