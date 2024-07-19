int c[N], n;
#define lowbit(x) (x) & (-x)
int sum(int i) // a[1] + a[2] + ... + a[i]
{
    int res = 0;
    for (; i > 0; i -= lowbit(i))
        res += c[i];
    return res;
}
int sum(int i, int j) // a[i] + a[i+1] + ... + a[j-1] + a[j]
{
    return sum(j) - sum(i - 1);
}
void add(int i, int val) // a[i] += val
{
    for (; i <= N; i += lowbit(i))
        c[i] += val;
}