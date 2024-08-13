#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e4;
int d[N], len = 1, n;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    cin >> d[1];
    for (int i = 2; i <= n; i++)
    {
        int tmp;
        cin >> tmp;
        if (tmp > d[len])
            d[++len] = tmp;
        else if (tmp < d[len])
            *upper_bound(d + 1, d + 1 + len, tmp) = tmp;
    }
    cout << len;
    return 0;
}