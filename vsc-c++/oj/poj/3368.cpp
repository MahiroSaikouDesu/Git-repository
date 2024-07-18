#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

const int N = 1e5 + 10, M = 20;
int F[N][M], a[N];
int n, q;

void stCreate()
{
    F[1][0] = 1;
    int cnt = 1, k = log2(n);
    for (int i = 2; i <= n; i++)
        F[i][0] = a[i] != a[i - 1] ? cnt = 1 : ++cnt;

    for (int j = 1; j <= k; j++)
        for (int i = 1; i <= n - (1 << j) + 1; i++)
            F[i][j] = max(F[i][j - 1], F[i + (1 << (j - 1))][j - 1]);
}

inline int stQuery(int l, int r)
{
    int k = log2(r - l + 1);
    return max(F[l][k], F[r - (1 << k) + 1][k]);
}

void work()
{
    cin >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    stCreate();
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        int t = l;
        while (a[t] == a[t - 1] && t <= r)
            t++;
        if (t > r)
            cout << r - l + 1 << '\n';
        else
            cout << max(t - l, stQuery(t, r)) << '\n';
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    while (cin >> n && n)
        work();
    return 0;
}