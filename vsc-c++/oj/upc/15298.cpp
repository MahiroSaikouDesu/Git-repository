#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
typedef pair<int, int> Pii;

int n, m, k, x, y, maxx;
deque<Pii> a;
priority_queue<int> q;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    maxx = 0;
    cin >> n >> k >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> x >> y;
        a.push_back({x, y});
    }
    sort(a.begin(), a.end(), [](Pii i, Pii j)
         { return i.first == j.first ? i.second < j.second : i.first < j.first; });
    // 买a
    while (!a.empty())
    {
        Pii f = a.front();
        if (m < f.first)
            break;
        maxx++, m -= f.first;
        a.pop_front();
        q.push(f.first - f.second);
    }
    sort(a.begin(), a.end(), [](Pii i, Pii j)
         { return i.second < j.second; });
    while (k && !a.empty())
    {
        Pii f = a.front();
        if (m >= f.second)
        {
            k--, maxx++, m -= f.second;
            a.pop_front();
        }
        else
        {
            while (k && m < f.second && !q.empty())
            {
                k--, m += q.top();
                q.pop();
            }
            if (k && m >= f.second)
            {
                k--, maxx++, m -= f.second;
                a.pop_front();
            }
            else
                break;
        }
    }
    cout << maxx;
    return 0;
}