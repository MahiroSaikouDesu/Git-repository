#include <bits/stdc++.h>
using namespace std;
const int N = 150, M = 1050;
const int NN = 105, MM = 1005;

int n, res, sum[N << 2][M << 2]; // 节点区间和
#define uls u << 1
#define urs u << 1 | 1
#define vls v << 1
#define vrs v << 1 | 1
#define mid ((l + r) >> 1)
void changeY(int u, int v, int l, int r, int y, int a)
{                                  // 内修
    sum[u][v] = max(sum[u][v], a); // 内层经过的节点均修改
    if (l == r)
        return;
    if (y <= mid)
        changeY(u, vls, l, mid, y, a);
    else
        changeY(u, vrs, mid + 1, r, y, a);
}
void changeX(int u, int l, int r, int x, int y, int a)
{                               // 外修
    changeY(u, 1, 1, MM, y, a); // 外层经过的节点均入内
    if (l == r)
        return;
    if (x <= mid)
        changeX(uls, l, mid, x, y, a);
    else
        changeX(urs, mid + 1, r, x, y, a);
}
void queryY(int u, int v, int l, int r, int y1, int y2)
{ // 内查
    if (y1 <= l && r <= y2)
    {
        res = max(res, sum[u][v]); // 内层覆盖即返回
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
        queryY(u, 1, 1, MM, y1, y2); // 外层覆盖即入内
        return;
    }
    if (x1 <= mid)
        queryX(uls, l, mid, x1, x2, y1, y2);
    if (x2 > mid)
        queryX(urs, mid + 1, r, x1, x2, y1, y2);
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    while (cin >> T && T)
    {
        memset(sum, 0, sizeof sum);
        while (T--)
        {

            char c;
            cin >> c;
            if (c == 'I')
            {
                int h, A, L;
                double a, l;
                cin >> h >> a >> l;
                h -= 99;
                A = a * 10 + 1, L = l * 10;
                changeX(1, 1, NN, h, A, L);
            }
            else
            {
                int h1, h2, A1, A2;
                double a, b;
                cin >> h1 >> h2 >> a >> b;
                h1 -= 99, h2 -= 99;
                A1 = a * 10 + 1, A2 = b * 10 + 1;
                if (h1 > h2)
                    swap(h1, h2);
                if (A1 > A2)
                    swap(A1, A2);
                res = 0;
                queryX(1, 1, NN, h1, h2, A1, A2);
                if (res == 0)
                    cout << "-1\n";
                else
                    cout << fixed << setprecision(1) << (res) * 1.0 / 10 << "\n";
            }
        }
    }
    return 0;
}