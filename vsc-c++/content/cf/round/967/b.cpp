#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> P;
const int inf = 0x3f3f3f3f << 1;
const int N = 2e5 + 10;

int T, a[N], n, cnt, mid, l, r;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> n;
        if (n % 2 == 0)
        {
            cout << "-1\n";
            continue;
        }
        l = cnt = 1, r = n, mid = (1 + n) >> 1;
        while (l < mid)
        {
            a[l++] = cnt++;
            a[r--] = cnt++;
        }
        a[mid] = n;
        for (int i = 1; i <= n; i++)
            cout << a[i] << " \n"[i == n];
    }
    return 0;
}