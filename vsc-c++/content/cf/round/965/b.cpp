#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int a[N];

void work()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 2; i <= n; i++)
        cout << a[i] << ' ';
    cout << a[1] << '\n';
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--)
        work();
    return 0;
}