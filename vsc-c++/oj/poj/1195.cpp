#include <iostream>
#include <cstring>
using namespace std;
const int N = 1050;

int n, sum[N << 1][N << 1]; // 节点区间和
#define uls u << 1
#define urs u << 1 | 1
#define vls v << 1
#define vrs v << 1 | 1
#define mid ((l + r) >> 1)
void changeY(int u, int v, int l, int r, int y, int a)
{                   // 内修
    sum[u][v] += a; // 内层经过的节点均修改
    if (l == r)
        return;
    if (y <= mid)
        changeY(u, vls, l, mid, y, a);
    else
        changeY(u, vrs, mid + 1, r, y, a);
}
void changeX(int u, int l, int r, int x, int y, int a)
{                              // 外修
    changeY(u, 1, 1, n, y, a); // 外层经过的节点均入内
    if (l == r)
        return;
    if (x <= mid)
        changeX(uls, l, mid, x, y, a);
    else
        changeX(urs, mid + 1, r, x, y, a);
}
int queryY(int u, int v, int l, int r, int y1, int y2)
{ // 内查
    if (y1 <= l && r <= y2)
        return sum[u][v]; // 内层覆盖即返回
    int res = 0;
    if (y1 <= mid)
        res += queryY(u, vls, l, mid, y1, y2);
    if (y2 > mid)
        res += queryY(u, vrs, mid + 1, r, y1, y2);
    return res;
}
int queryX(int u, int l, int r, int x1, int x2, int y1, int y2)
{ // 外查
    if (x1 <= l && r <= x2)
        return queryY(u, 1, 1, n, y1, y2); // 外层覆盖即入内
    if (x2 <= mid)
        return queryX(uls, l, mid, x1, x2, y1, y2);
    else if (x1 > mid)
        return queryX(urs, mid + 1, r, x1, x2, y1, y2);
    else
        return queryX(uls, l, mid, x1, mid, y1, y2) + queryX(urs, mid + 1, r, mid + 1, x2, y1, y2);
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int op, x1, x2, y1, y2, a;
    while (cin >> op)
    {
        if (op == 0)
        {
            cin >> n;
            memset(sum, 0, sizeof sum);
        }
        if (op == 1)
        {
            cin >> x1 >> y1 >> a;
            x1++, y1++;
            changeX(1, 1, n, x1, y1, a);
        }
        if (op == 2)
        {
            cin >> x1 >> y1 >> x2 >> y2;
            x1++, y1++, x2++, y2++;
            cout << queryX(1, 1, n, x1, x2, y1, y2) << '\n';
        }
        if (op == 3)
            break;
    }

    return 0;
}