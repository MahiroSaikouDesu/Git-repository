#include <bits/stdc++.h>
using namespace std;

int v[30];

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int a, b, c;
    cin >> a >> b >> c;
    while (b != c)
    {
        v[b] = 1;
        b++;
        if (b >= 24)
            b -= 24;
    }
    cout << (v[a] ? "No" : "Yes");
    return 0;
}