#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;
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
int fa[N];
vector<set<int>> cnt;

int ffind(int x)
{
    if (fa[x] == x)
        return x;
    return fa[x] = ffind(fa[x]);
}

void uni(int x, int y)
{
    int a = ffind(x), b = ffind(y);
    if (a != b)
        fa[a] = b;
}

struct node
{
    int now = 0;
    set<int> all;
};

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, ans = 0;
    cin >> n >> m;
    cnt.resize(n + 1);
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        uni(a, b);
        cnt[a].insert(b);
        cnt[b].insert(a);
    }
    map<int, node> root;
    for (int i = 1; i <= n; i++)
    {
        fa[i] = ffind(i);
        if (fa[i] == i)
        {
            node tmp;
            tmp.all.insert(i);
            root.insert({i, tmp});
        }
    }
    for (int i = 1; i <= n; i++)
    {
        root[fa[i]].now += (int)cnt[i].size();
        root[fa[i]].all.insert(i);
        //cout << "f" << i << ' ' << fa[i] << '\n';
    }
    for (auto it = root.begin(); it != root.end(); it++)
    {
        node tmp = (*it).second;
        //cout << tmp.now << ' ' << tmp.all.size() << '\n';
        tmp.now >>= 1;
        int tmp2 = tmp.all.size();
        ans += tmp2 * (tmp2 - 1) / 2 - tmp.now;
    }
    cout << ans;
    return 0;
}