int fa[N];
int fafind(int x)
{
    if (x == fa[x])
        return x;
    return fa[x] = fafind(fa[x]);
}
void uni(int x, int y)
{
    x = fafind(x);
    y = fafind(y);
    if (x != y)
        fa[x] = fa[y];
}