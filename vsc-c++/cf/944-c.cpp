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
int main()
{
    int n = read();
    while (n--)
    {
        // a < b , c < d
        int a = read(), b = read(), c = read(), d = read(), tmp = 0;

        if(a>b)
            swap(a, b);
        if(c>d)
            swap(c, d);

        tmp += (a < c) && (c < b) ? 1 : 0;
        tmp += (a < d) && (d < b) ? 1 : 0;

        if(tmp==1)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}