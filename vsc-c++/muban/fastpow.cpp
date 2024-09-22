long long fpow(long long a, long long b)
{
    long long ans = 1;
    while (b)
    {
        if (b & 1)
            ans *= a;
        b >>= 1;
        a *= a;
    }
    return ans;
}