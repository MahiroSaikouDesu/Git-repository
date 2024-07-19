#include <bits/stdc++.h>
using namespace std;
inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = (x << 1) + (x << 3) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}
#define ll long long
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;
const int N = 4e4;

int c[N], n, ans[N];
inline int lowbit(int i)
{
    return (-i) & i;
}
int sum(int i) // a[1] + a[2] + ... + a[i]
{
    int res = 0;
    for (; i > 0; i -= lowbit(i))
        res += c[i];
    return res;
}
void add(int i, int val) // a[i] += val
{
    for (; i <= N; i += lowbit(i))
        c[i] += val;
}

signed main()
{
    int a, b;
    n = read();
    for (int i = 1; i <= n; i++)
    {
        a = read(), b = read();
        a++;
        // cout << sum(a) << '\n';
        ans[sum(a)]++;
        add(a, 1);
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << '\n';
    return 0;
}