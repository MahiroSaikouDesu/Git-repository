#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> Pii;

const int mod = 1e9 + 7, N = 2e5 + 5, inf = mod; // 定义常量mod和N
ll fac[N], infac[N];                             // 定义一维数组fac和infac

// 快速幂运算函数
int qmi(int a, int b, int m)
{
    int res = 1;
    while (b)
    {
        if (b & 1 == 1)
            res = (ll)res * a % m; // 如果b是奇数，则累乘到结果中
        a = (ll)a * a % m;         // a自身平方
        b >>= 1;                   // b右移一位，相当于除以2
    }

    return res;
}

// 初始化函数
void init()
{
    fac[0] = infac[0] = 1;
    for (int i = 1; i < N; ++i)
    {
        fac[i] = fac[i - 1] * i % mod;                            // 计算阶乘
        infac[i] = (ll)infac[i - 1] * qmi(i, mod - 2, mod) % mod; // 计算阶乘的逆元
    }
}

ll c(int b, int a)
{
    return (ll)fac[a] * infac[b] % mod * infac[a - b] % mod;
}

ll work()
{
    int n, k, cnt = 0;
    ll res = 0;
    cin >> n >> k;
    int tmp = (k + 1) >> 1;
    tmp--;
    for (int i = 1; i <= n; i++)
    {
        int t;
        cin >> t;
        cnt += t ? 0 : 1;
    }
    for (int i = tmp + 1; i <= n - tmp; i++)
    {
        res += i > cnt ? c(tmp, i - 1) * c(tmp, n - i) : 0;
        res %= inf;
    }
    return res;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    init();
    while (T--)
        cout << work() % inf << "\n";
    return 0;
}