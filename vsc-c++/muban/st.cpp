int F[N][M];
void stCreate()
{
    for (int i = 1; i <= n; i++)
        F[i][0] = a[i];
    int k = log2(n);
    for (int j = 1; j <= k; j++)
        for (int i = 1; i <= n - (1 << j) + 1; i++)
            F[i][j] = max(F[i][j - 1], F[i + (1 << (j - 1))][j - 1]);
}

inline int stQuery(int l, int r)
{
    int k = log2(r - l + 1);
    return max(F[l][k], F[r - (1 << k) + 1][k]);
}