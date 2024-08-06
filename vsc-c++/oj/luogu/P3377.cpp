#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> Pii;
const int inf = (1 << 30) + 1;
const int N = 1e5 + 10;

int n, m, v[N], lc[N], rc[N], dis[N]; // 左偏树
int fa[N];                            // 并查集
int find(int x)
{ // 并查集找根
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}
int merge(int x, int y)
{
    if (!x || !y)
        return x + y; // 若一个堆为空则返回另一个堆
    if (v[x] == v[y] ? x > y : v[x] > v[y])
        swap(x, y);          // 取小值做根
    rc[x] = merge(rc[x], y); // 递归合并右儿子与另一个堆

    if (dis[lc[x]] < dis[rc[x]])
        swap(lc[x], rc[x]);  // 维护左偏性
    dis[x] = dis[rc[x]] + 1; // 更新dis
    return x;                // 返回合并后的根
}
void erase(int x) // 删除x点
{
    v[x] = -1;
    fa[lc[x]] = fa[rc[x]] = fa[x] = merge(lc[x], rc[x]);
}
void init()
{
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    dis[0] = -1; // 空节点的dis初始化
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    init();
    for (int i = 1; i <= n; i++)
        cin >> v[i];

    int op, x, y;
    while (m--)
    {
        cin >> op;
        if (op == 1)
        {
            cin >> x >> y;
            if (v[x] == -1 || v[y] == -1)
                continue;
            x = find(x), y = find(y);
            if (x != y)
                fa[x] = fa[y] = merge(x, y);
        }
        else
        {
            cin >> x;
            if (v[x] == -1)
            {
                cout << v[x] << '\n';
                continue;
            }
            x = find(x);
            cout << v[x] << '\n';
            erase(x);
        }
    }
    return 0;
}
