#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
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
ll ans;
int cnt;
int main()
{
    int n = read();
    for (int i = 1; i <= n; i++)
    {
        int a = read(), b = read();
        ans += 1LL * a;
        cnt = max(cnt, b - a);
    }
    cout << ans + 1LL * cnt;
    return 0;
}