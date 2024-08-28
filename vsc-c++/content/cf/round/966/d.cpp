#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
typedef pair<int, int> Pii;
const int inf = 0x3f3f3f3f << 1;
const int N = 2e5 + 10;

string line;
int a[N], T, n, sum[N];

void build()
{
    for (int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + a[i];
}

int query(int l, int r)
{
    return sum[r] - sum[l - 1];
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        build();

        cin >> line;
        int ans = 0, l = 0, r = n - 1;
        while (1)
        {
            while (l < n && line[l] != 'L')
                l++;
            while (r >= 0 && line[r] != 'R')
                r--;
            if (l > r)
                break;
            ans += query(l + 1, r + 1);
            l++, r--;
        }

        cout << ans << '\n';
    }
    return 0;
}