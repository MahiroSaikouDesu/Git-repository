#include <queue>
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <algorithm>
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
const int N = 1000010;
struct node
{
    int x, y;
    bool operator<(const node &a) const
    {
        return x < a.x || (x == a.x && y < a.y);
    }
} e[N];
int c[N], n, m, k, kas;
long long ans;
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
void add(int i) // a[i] += val
{
    for (; i <= m; i += lowbit(i))
        c[i]++;
}

signed main()
{
    int T = read();
    while (T--)
    {
        n = read(), m = read(), k = read();
        ans = 0;
        memset(c, 0, sizeof c);
        for (int j = 0; j < k; j++)
        {
            e[j].x = read(), e[j].y = read();
        }
        sort(e, e + k);
        for (int j = 0; j < k; j++)
        {
            ans += j - sum(e[j].y);
            add(e[j].y);
        }
        // printf("Test case %d: %lld\n", ++kas, ans);
        kas++;
        cout << "Test case " << kas << ": " << ans << '\n';
    }
    return 0;
}