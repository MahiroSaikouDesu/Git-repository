#include <iostream>
#include <cmath>
#include <cstdio>
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
const int N = 5e4 + 10, M = 20;

int a[N], n, q;
int Fmax[N][M], Fmin[N][M];
void stCreate()
{
    for (int i = 1; i <= n; i++)
        Fmax[i][0] = a[i], Fmin[i][0] = a[i];
    int k = log2(n);
    for (int j = 1; j <= k; j++)
        for (int i = 1; i <= n - (1 << j) + 1; i++)
            Fmax[i][j] = max(Fmax[i][j - 1], Fmax[i + (1 << (j - 1))][j - 1]), Fmin[i][j] = min(Fmin[i][j - 1], Fmin[i + (1 << (j - 1))][j - 1]);
}

int stQuery(int l, int r)
{
    int k = log2(r - l + 1);
    return max(Fmax[l][k], Fmax[r - (1 << k) + 1][k]) - min(Fmin[l][k], Fmin[r - (1 << k) + 1][k]);
}

void print()
{
    int k = log2(n);
    for (int j = 1; j <= k; j++)
    {
        cout << "j: " << j << '\n';
        for (int i = 1; i <= n - (1 << j) + 1; i++)
            cout << Fmin[i][j] << ' ';
        cout << '\n';
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    n = read(), q = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    stCreate();
    while (q--)
    {
        int l = read(), r = read();
        cout << stQuery(l, r) << '\n';
    }
    return 0;
}