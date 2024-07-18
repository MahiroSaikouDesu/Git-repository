#include <iostream>
#include <cmath>
using namespace std;
#define ll long long
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;
const int N = 300, M = 10, K = 300;

int n, b, q;
int F[K][N][M], Fmin[K][N][M], a[N][N];
void stCreate()
{
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            F[k][i][0] = Fmin[k][i][0] = a[k][i];
    int k = log2(n);
    for (int q = 1; q <= n; q++)
        for (int j = 1; j <= k; j++)
            for (int i = 1; i <= n - (1 << j) + 1; i++)
            {
                F[q][i][j] = max(F[q][i][j - 1], F[q][i + (1 << (j - 1))][j - 1]);
                Fmin[q][i][j] = min(Fmin[q][i][j - 1], Fmin[q][i + (1 << (j - 1))][j - 1]);
            }
}

inline int stQuery(int line, int l, int r)
{
    int k = log2(r - l + 1);
    return max(F[line][l][k], F[line][r - (1 << k) + 1][k]);
}

inline int stQuery2(int line, int l, int r)
{
    int k = log2(r - l + 1);
    return min(Fmin[line][l][k], Fmin[line][r - (1 << k) + 1][k]);
}

void print()
{
    int k = log2(n);
    for (int m = 1; m <= n; m++)
    {
        cout << "m: " << m << '\n';
        for (int j = 0; j <= k; j++)
        {
            for (int i = 1; i <= n - (1 << j) + 1; i++)
                cout << Fmin[m][i][j] << ' ';
            cout << '\n';
        }
        cout << '\n';
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> b >> q;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    stCreate();
    // print();
    while (q--)
    {
        int l, r, maxx = 0, minn = 400;
        cin >> l >> r;
        for (int i = l; i <= l + b - 1; i++)
        {
            maxx = max(maxx, stQuery(i, r, r + b - 1));
            minn = min(minn, stQuery2(i, r, r + b - 1));
        }
        cout << maxx - minn << '\n';
    }
    return 0;
}