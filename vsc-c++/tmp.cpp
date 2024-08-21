#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <math.h>
using namespace std;
const int N = 505;
int m, n;
int color[N];
int edge[N][N];
int girl[N], used[N];
bool dfs(int v, int c)
{
    color[v] = c; // 将当前顶点涂色
    for (int i = 0; i < n; i++)
    { // 遍历所有相邻顶点，即连着的点
        if (edge[v][i] == 1)
        {                      // 如果顶点存在
            if (color[i] == c) // 如果颜色重复，就返回false
                return false;
            if (color[i] == 0 && !dfs(i, -c)) // 如果还未涂色，就染上相反的颜色-c,并dfs这个顶点，进入下一层
                return false;                 // 返回false
        }
    }
    return true; // 如果所有顶点涂完色，并且没有出现同色的相邻顶点，就返回true
}

int solve()
{
    for (int i = 0; i < n; i++)
    {
        if (color[i] == 0)
        {
            if (!dfs(i, 1))
            {
                return 0;
            }
        }
    }
    return 1;
}

bool found(int x)
{
    for (int i = 1; i <= n; i++)
    {
        if (edge[x][i] && !used[i])
        {
            used[i] = 1;
            if (girl[i] == 0 || found(girl[i]))
            {
                girl[i] = x;
                return 1;
            }
        }
    }
    return 0;
}
int main()
{
    int u, v;
    while (cin >> n >> m)
    {
        memset(color, 0, sizeof(color));
        memset(edge, 0, sizeof(edge));
        for (int i = 0; i < m; i++)
        {
            cin >> u >> v;  // 因为是无向图，所以要往两个方向添加边
            edge[u][v] = 1; // 正着添加
            edge[v][u] = 1; // 反着添加
        }
        if (!solve() || n == 1)
        {
            printf("No\n");
            continue;
        }
        memset(girl, 0, sizeof(girl));
        int sum = 0;
        for (int i = 1; i <= n; i++)
        {
            memset(used, 0, sizeof(used));
            if (found(i))
                sum++;
        }
        printf("%d\n", sum / 2);
    }
    return 0;
}