#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n, ans, T, sum, tmp;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> n;
        sum = ans = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> tmp;
            ans ^= tmp;
            sum += (tmp == 1);
        }
        cout << ((sum == n ? n % 2 : ans == 0) ? "Brother" : "John") << '\n';
    }
    return 0;
}