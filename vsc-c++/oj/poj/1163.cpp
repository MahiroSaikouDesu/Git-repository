#include <iostream>
using namespace std;
const int N = 1000;
int a[N][N];

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            cin >> a[i][j];
    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= i; j++)
        {
            if (j == 1)
                a[i][j] += a[i - 1][j];
            else
                a[i][j] += max(a[i - 1][j], a[i - 1][j - 1]);
        }
    int maxx = 0;
    for (int j = 1; j <= n; j++)
        maxx = max(maxx, a[n][j]);
    cout << maxx;
    return 0;
}