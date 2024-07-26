#include <iostream>
#include <cmath>
using namespace std;
#define ll long long
#define int long long
const int N = 4e4;
int a[N], s[N];

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    a[1] = 1;
    s[1] = 1;
    for (int i = 2; i <= N; i++)
    {
        a[i] = a[i - 1] + (int)log10(i * 1.0) + 1;
        s[i] = s[i - 1] + a[i];
    }
    int q, t, i, k;
    cin >> q;
    while (q--)
    {
        cin >> t;
        i = 1, k = 0;
        while (s[i] < t) // 哪一组
            i++;
        int pos = t - s[i - 1]; // 这一组 的 第pos个位置
        int len = 0;
        while (len < pos)
        {
            k++;
            len = a[k];
        }
        cout << k / (int)pow(10.0, a[k] - pos) % 10 << '\n';
    }
    return 0;
}