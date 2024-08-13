#include <bits/stdc++.h>
using namespace std;
const int N = 100;
int f[50];

int work(int x)
{
    if (f[x])
        return f[x];
    else
        return f[x] = work(x - 1) + work(x - 2);
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    f[1] = 1;
    f[2] = 1;
    f[3] = 2;
    while (T--)
    {
        int tmp;
        cin >> tmp;
        cout << work(tmp) << '\n';
    }
    return 0;
}