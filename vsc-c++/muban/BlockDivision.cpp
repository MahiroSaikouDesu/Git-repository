int n, L[N], R[N], add[N], a[N], sum[N], pos[N];
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
        {
            pos[j] = i;
            sum[i] += a[j];
        }
}
void change(int l, int r, int d)
{
    int p = pos[l], q = pos[r];
    if (p == q)
    {
        for (int i = l; i <= r; i++)
            a[i] += d;
        sum[p] += d * (r - l + 1);
    }
    else
    {
        for (int i = p + 1; i <= q - 1; i++)
            add[i] += d;
        for (int i = l; i <= R[p]; i++)
            a[i] += d;
        for (int i = L[q]; i <= r; i++)
            a[i] += d;
        sum[p] += d * (R[p] - l + 1);
        sum[q] += d * (r - L[q] + 1);
    }
}
int query(int l, int r)
{
    int p = pos[l], q = pos[r], ans = 0;
    if (p == q)
    {
        for (int i = l; i <= r; i++)
            ans += a[i];
        ans += add[p] * (r - l + 1);
    }
    else
    {
        for (int i = p + 1; i <= q - 1; i++)
            ans += sum[i] + add[i] * (R[i] - L[i] + 1);
        for (int i = l; i <= R[p]; i++)
            ans += a[i];
        for (int i = L[q]; i <= r; i++)
            ans += a[i];
        ans += add[p] * (R[p] - l + 1);
        ans += add[q] * (r - L[q] + 1);
    }
    return ans;
}