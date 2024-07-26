#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;
const int N = 1e5 + 10;

int n, L[N], R[N], a[N], mx[N], tmp[N], m, pos[N];
void btCreate()
{
    int t = sqrt(n * 1.0), num = n / t;
    if (n % t)
        num++;
    for (int i = 1; i <= num; i++)
    {
        L[i] = (i - 1) * t + 1;
        R[i] = i * t;
    }
    R[num] = n;
    for (int i = 1; i <= num; i++)
        for (int j = L[i]; j <= R[i]; j++)
            pos[j] = i;
    for (int i = 1; i <= num; i++)
        sort(tmp + L[i], tmp + R[i] + 1);
}
int query(int l, int r, int h)
{
    int p = pos[l], q = pos[r], ans = 0;
    if (p == q)
    {
        for (int i = l; i <= r; i++)
            ans += h >= a[i] ? 1 : 0;
    }
    else
    {
        for (int i = p + 1; i <= q - 1; i++)
            ans += upper_bound(tmp + L[i], tmp + R[i] + 1, h) - tmp - L[i];
        for (int i = l; i <= R[p]; i++)
            ans += h >= a[i] ? 1 : 0;
        for (int i = L[q]; i <= r; i++)
            ans += h >= a[i] ? 1 : 0;
    }
    return ans;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int q, kas = 0;
    cin >> q;
    while (q--)
    {
        kas++;
        cout << "Case " << kas << ":\n";
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            tmp[i] = a[i];
        }
        btCreate();
        while (m--)
        {
            int l, r, h;
            cin >> l >> r >> h;
            l++, r++;
            cout << query(l, r, h) << '\n';
        }
    }
    return 0;
}