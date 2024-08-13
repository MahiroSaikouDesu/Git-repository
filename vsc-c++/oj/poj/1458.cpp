#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e3;
int d[N][N];

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string a, b;
    while (cin >> a >> b)
    {
        memset(d, 0, sizeof d);
        for (int i = 1; i <= a.length(); i++)
            for (int j = 1; j <= b.length(); j++)
                if (a[i - 1] == b[j - 1])
                    d[i][j] = d[i - 1][j - 1] + 1;
                else
                    d[i][j] = max(d[i - 1][j], d[i][j - 1]);
        cout << d[a.length()][b.length()] << '\n';
    }
    return 0;
}