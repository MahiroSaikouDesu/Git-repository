// 快速幂运算函数，计算a的b次方对p取模的结果
ll qmi(ll a, ll b, ll p)
{
    ll res = 1;
    while (b)
    {
        if (b & 1 == 1)
            res = res * a % p; // 如果b是奇数，则累乘到结果中
        a = a * a % p;         // a自身平方
        b >>= 1;               // b右移一位，相当于除以2
    }
    return res;
}
// 计算组合数C(a, b)对p取模的结果
ll C(ll a, ll b, ll p)
{
    ll res = 1;
    for (int i = 1, j = a; i <= b; ++i, --j)
    {
        res = res * j % p;                // 计算阶乘部分
        res = res * qmi(i, p - 2, p) % p; // 计算阶乘的逆元部分
    }

    return res;
}
// Lucas定理，用于计算大组合数取模的问题
ll lucas(ll a, ll b, ll p)
{
    if (a < p && b < p)
        return C(a, b, p); // 如果a和b都小于p，直接计算C(a, b)
    else
        return C(a % p, b % p, p) * lucas(a / p, b / p, p) % p; // 否则，递归计算
}