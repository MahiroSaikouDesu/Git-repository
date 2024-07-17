#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
const int N = 2e5 + 10;
bool v[N], v1[N];
int num[N];
vector<int> ans;
vector<vector<P>> p(N);
set<int> fa[N], son[N];
queue<int> q;
int main()
{
    int n, m, flag = 0, cnt = 1;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        p[a].push_back({b, c});
        fa[b].insert(a);
        fa[c].insert(a);
        son[a].insert(b);
        son[a].insert(c);
        v[a] = true;
        v1[a] = true;
        v1[b] = true;
        v1[c] = true;
        if (a == b || a == c)
        {
            flag = 1;
        }
    }
    if (flag)
    {
        cout << -1;
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        if (v[i] == false || v1[i] == false)
        {
            num[i] = 1;
            for (auto &t : fa[i])
            {
                son[t].erase(i);
                if (son[t].empty())
                    q.push(t);
            }
        }
    }
    while (!q.empty())
    {
        cnt++;
        queue<int> qtmp;
        while (!q.empty())
        {
            int front = q.front();
            q.pop();
            ans.push_back(front);
            for (auto &t : fa[front])
            {
                son[t].erase(front);
                if (son[t].empty())
                    qtmp.push(t);
            }
        }
        while (!qtmp.empty())
        {
            q.push(qtmp.front());
            qtmp.pop();
        }
    }
    int he = 0;
    for (auto &t : ans)
    {
        for (auto &tt : p[t])
        {
            num[t] = max(num[t], num[tt.first] + num[tt.second]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (num[i] == 0)
        {
            cout << -1;
            return 0;
        }
        else
            he += num[i];
    }
    if (he > 1e9 || he <= 0)
    {
        cout << -1;
    }
    else
        cout << he;
    return 0;
}

/*
5 4
4 1 1
3 5 4
5 2 1
2 1 1

*/