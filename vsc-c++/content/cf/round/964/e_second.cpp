#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
const int N = 1e9;

vector<int> v(30);

ll getci(ll x)
{
    int cnt = 0;
    for (; 1; cnt++)
        if (v[cnt] > x)
            return cnt;
}

int work()
{
    priority_queue<int, vector<int>, greater<int>> q;
    int l, r, res = 0, flag = 1;
    cin >> l >> r;
    int it = l;
    while (it <= r)
    {
        int tmp = getci(it), tmp2 = pow(3, tmp);
        res += tmp * (min(r, tmp2 - 1) - it + 1 + flag);
        it = tmp2;
        flag = 0;
    }
    return res;
}

void init()
{
    int cnt = 0, tmp = 1;
    while (tmp <= N)
    {
        v[cnt] = tmp;
        cnt++;
        tmp *= 3;
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    init();
    while (T--)
        cout << work() << '\n';
    return 0;
}