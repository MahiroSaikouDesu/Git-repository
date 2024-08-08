#define uls u << 1
#define urs u << 1 | 1
#define vls v << 1
#define vrs v << 1 | 1
#define mid ((l + r) >> 1)
int T, n, MI, MX, a[N][N];
int mi[N << 2][N << 2], mx[N << 2][N << 2];
void pushupX(int u, int v)
{ // X上传
    mx[u][v] = max(mx[uls][v], mx[urs][v]);
    mi[u][v] = min(mi[uls][v], mi[urs][v]);
}
void pushupY(int u, int v)
{ // Y上传
    mx[u][v] = max(mx[u][vls], mx[u][vrs]);
    mi[u][v] = min(mi[u][vls], mi[u][vrs]);
}
void buildY(int u, int v, int l, int r, int x)
{ // 内建
    if (l == r)
    {
        if (x)
            mx[u][v] = mi[u][v] = a[x][l]; // 非0时取a
        else
            pushupX(u, v); // 0时用该列的行信息更新
        return;
    }
    buildY(u, vls, l, mid, x);
    buildY(u, vrs, mid + 1, r, x);
    pushupY(u, v);
}
void buildX(int u, int l, int r)
{ // 外建
    if (l == r)
    {
        buildY(u, 1, 1, n, l); // 叶子时传入行坐标
        return;
    }
    buildX(uls, l, mid);
    buildX(urs, mid + 1, r);
    buildY(u, 1, 1, n, 0); // 非叶子时传入0
}
void changeY(int u, int v, int l, int r, int y, int val)
{ // 内修
    if (l == r)
    {
        if (val)
            mx[u][v] = mi[u][v] = val; // 非0时取新值
        else
            pushupX(u, v); // 0时用该列的行信息更新
        return;
    }
    if (y <= mid)
        changeY(u, vls, l, mid, y, val);
    else
        changeY(u, vrs, mid + 1, r, y, val);
    pushupY(u, v);
}
void changeX(int u, int l, int r, int x, int y, int val)
{ // 外修
    if (l == r)
    {
        changeY(u, 1, 1, n, y, val); // 叶子时传入新值
        return;
    }
    if (x <= mid)
        changeX(uls, l, mid, x, y, val);
    else
        changeX(urs, mid + 1, r, x, y, val);
    changeY(u, 1, 1, n, y, 0); // 非叶子时传入0
}
void queryY(int u, int v, int l, int r, int y1, int y2)
{ // 内查
    if (y1 <= l && r <= y2)
    {
        MX = max(MX, mx[u][v]);
        MI = min(MI, mi[u][v]);
        return;
    }
    if (y1 <= mid)
        queryY(u, vls, l, mid, y1, y2);
    if (y2 > mid)
        queryY(u, vrs, mid + 1, r, y1, y2);
}
void queryX(int u, int l, int r, int x1, int x2, int y1, int y2)
{ // 外查
    if (x1 <= l && r <= x2)
    {
        queryY(u, 1, 1, n, y1, y2);
        return;
    }
    if (x1 <= mid)
        queryX(uls, l, mid, x1, x2, y1, y2);
    if (x2 > mid)
        queryX(urs, mid + 1, r, x1, x2, y1, y2);
}