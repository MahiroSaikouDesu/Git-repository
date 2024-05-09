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
const int N = 2e5 + 10;
int pi[N], ans, n, k;
struct node
{
    vector<int> v;
} p[N];
int dps(int now)
{
}
int main()
{
    n = read(), k = read();
    for (int i = 1; i <= n; i++)
    {
        pi[i] = read();
        p[pi[i]].v.push_back(i);
    }
    int i = 1;
    while(i + k <= n)
    {
        int cnt = 1;
        // check whether legal
        for (int j = i; j <= n; j++)
        {
            if (p[j].v.empty())
                break;
            cnt++;
            if (cnt >= k)
                break;
        }
        if (cnt < k)
            i += cnt;
        else
        {
            ans = max(ans, dps(i));
            i++;
        }
    }
    return 0;
}