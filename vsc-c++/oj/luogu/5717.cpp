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
    int a[3];
    a[0] = read(), a[1] = read(), a[2] = read();
    sort(a, a + 3);
    if(a[0]+a[1]<a[2])
        cout << "Not triangle";
    
    
    return 0;
}