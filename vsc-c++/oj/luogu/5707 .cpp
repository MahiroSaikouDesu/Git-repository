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
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int s = read(), v = read();
    int a = s / v;
    if (a * v < s)
        a++;
    int h = 7, m = 50;
    while (a)
    {
        if (a >= 60)
        {
            a -= 60, h--;
        }
        else
        {
            m -= a;
            if (m < 0)
            {
                m += 60;
                h--;
            }
            break;
        }
    }
    if (h < 0)
        h += 24;
    if (h >= 10)
        cout << h;
    else
        cout << 0 << h;
    cout << ':';
    if (m >= 10)
        cout << m;
    else
        cout << 0 << m;
    return 0;
}