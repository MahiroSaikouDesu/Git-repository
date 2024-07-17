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
int a[N];
map<int, int> fi;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n = read();
    vector<Pii> ans;
    for (int i = 1; i <= n; i++)
    {
        a[i] = read();
        fi[a[i]] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == i)
            continue;
        int now = a[i];
        ans.push_back({i, fi[i]});
        swap(a[i], a[fi[i]]);
        fi[now] = fi[i];
        fi[i] = i;
    }
    cout << ans.size() << '\n';
    for (auto it : ans)
    {
        cout << it.first << ' ' << it.second << '\n';
    }
    return 0;
}