#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> P;
const int inf = 0x3f3f3f3f << 1;

int n, p, tmp, m;
vector<int> v;

void MultipleQuest()
{
    // init
    cin >> n >> p;
    v.resize(n);
    for (auto &i : v)
        cin >> i;
    sort(v.begin(), v.end(), greater<int>());

    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 1; i <= p; i++)
        q.push(0);

    // work
    for (auto i : v)
    {
        int f = q.top();
        q.pop();
        q.push(f + i);
    }

    // getAnswer
    int res = 0;
    while (!q.empty())
    {
        res = q.top();
        q.pop();
    }
    cout << "Answer: " << res << '\n';
}

struct node
{
    int f, s, v;
};

void EventChoose()
{
    // init
    cin >> n;
    vector<node> a(n);
    v.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].f >> a[i].s >> a[i].v;
    sort(a.begin(), a.end(), [&](const node &a, const node &b)
         { return a.s == b.s ? a.f < b.f : a.s < b.s; });
    int maxx = a.back().s + 1; // 迎合 ++

    // work
    vector<int> dp(maxx + 10, 0);
    for (int i = 0; i < n; i++)
    {
        node now = a[i];
        now.f++, now.s++; // 防被卡0

        for (int j = now.s; j <= maxx; j++)
            dp[j] = max(dp[j], dp[now.f - 1] + now.v);
    }

    // printAnswer
    cout << "Answer: " << dp[maxx] << '\n';
}

void NumDiverge()
{
    // init
    cin >> n;
    v.resize(2 * n);
    for (auto &i : v)
        cin >> i;

    sort(v.begin(), v.end());

    // work
    int res = 0, flag = 0;
    for (auto i : v)
        res += (flag ^= 1) ? i : 0; // 第一个取，之后每隔一个加值

    cout << "Answer: " << res << '\n';
}

void CookieDistribute()
{
    // init
    cin >> n >> m; // n个孩子 m个饼干
    priority_queue<int, vector<int>, greater<int>> g, s;
    for (int i = 1; i <= n; i++)
    {
        cin >> tmp;
        g.push(tmp);
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> tmp;
        s.push(tmp);
    }

    // work
    int cnt = 0;
    while (!s.empty() && !g.empty())
    {
        tmp = s.top();
        s.pop();
        if (tmp >= g.top())
            cnt++, g.pop();
    }

    cout << "Answer: " << cnt << '\n';
}

bool work(deque<int> v, int n)
{
    int cnt = 0, n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cnt += (v[i - 1] || v[i] || v[i + 1]) ? 0 : (v[i] = 1); // 相邻3个但凡有一个被种了都不能种
    return cnt >= n;
}

void PlantingFlower()
{
    // init
    cin >> n;
    deque<int> dq(n);
    for (auto &i : dq)
        cin >> i;
    dq.push_back(0);
    dq.push_front(0); // 前后不受边界限制

    cout << ((work(dq, n)) ? "True" : "False") << '\n';
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    // Problem 1
    MultipleQuest();

    // Problem 2
    // 时间复杂度为 O(n)

    // Problem 3
    EventChoose();

    // Problem 4
    NumDiverge();

    // Problem 5
    CookieDistribute();

    // Problem 6
    PlantingFlower();

    return 0;
}