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
    while(n--){
        int a = read(), b = read();
        if(a>b)
            swap(a, b);
        cout << a << ' ' << b;
    }
    return 0;
}