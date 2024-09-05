#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> P;
const int inf = 0x3f3f3f3f << 1;
const int N = 1e4 + 10;

int a[N], n;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        int s = 0;
        for (int i = 1; i <= n; i++)
            s ^= a[i];

        if (s)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}