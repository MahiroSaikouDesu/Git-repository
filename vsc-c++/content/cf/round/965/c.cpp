#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
const int inf = 1e9;
const int N = 2e5 + 10;

int n, k;
struct node
{
    int a, b, flag;
    bool operator<(const node &j) const { return a == j.a ? b > j.b : a < j.a; }
} e[N];

bool check(int x)
{
    int mid = n - (n >> 1), use = 0;
    for (int i = n - 1; i >= 1; i--)
        if (e[i].a >= x)
            mid--;
        else if (mid > 0 && e[i].b)
            mid--, use += x - e[i].a;
    return mid <= 0 && use <= k;
}

int solve()
{
    sort(e + 1, e + 1 + n);
    // case 1:
    int maxx = 0, maxit = 0, mid = (1 + n) >> 1, ans = 0;
    for (int i = 1; i <= n; i++)
        if (e[i].b && maxx < e[i].a)
            maxx = e[i].a, maxit = i;
    if (maxit)
        if (n % 2)
            ans = max(ans, k + maxx + (maxit >= mid ? e[mid - 1].a : e[mid].a));
        else
            ans = max(ans, k + maxx + (maxit > mid ? e[mid].a : e[mid + 1].a));

    // case 2: 不改max
    int l = 1, r = inf, ans1 = 0;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        if (check(mid))
            ans1 = mid, l = mid + 1;
        else
            r = mid - 1;
    }
    ans = max(ans, e[n].a + ans1);
    return ans;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
            cin >> e[i].a;
        for (int i = 1; i <= n; i++)
            cin >> e[i].b;
        for (int i = 1; i <= n; i++)
            e[i].flag = 0;

        cout << solve() << '\n';
    }
    return 0;
}