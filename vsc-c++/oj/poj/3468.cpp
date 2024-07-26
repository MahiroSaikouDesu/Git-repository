#include <iostream>
#include <cmath>
using namespace std;
#define ll long long
#define int unsigned int
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;
const int N = 31269;
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
    int q, n, i, k;
    cin >> q;
    while (q--)
    {
        cin >> n;
        i = 1, k = 0;
        while (s[i] < n) // 哪一组
            i++;
        int pos = n - s[i - 1]; // 这一组 的 第pos个位置
        int len = 0;
        for (i = 1; len < pos; i++)
            len += (int)log10((double)i) + 1;
        cout << (i - 1) / (int)pow((double)10, len - pos) % 10 << '\n';
    }
    return 0;
}