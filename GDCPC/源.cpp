#include <bits/stdc++.h>
//#define int long long
#define per(i,j,k) for(int (i)=(j);(i)<=(k);++(i))
#define rep(i,j,k) for(int (i)=(j);(i)>=(k);--(i))
#define debug(a) cout<<#a<<"="<<a<<endl
#define fr first
#define se second
#define endl '\n'
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    struct {
        int x, y;
    }g[n * m];

    per(i, 1, n) {
        per(j, 1, m) {
            int tmp;
            cin >> tmp;
            g[tmp] = { i,j };
        }
    }

    bool vis[n + 1][m + 1];
    per(i, 1, n) {
        per(j, 1, m) {
            vis[i][j] = false;
        }
    }

    int p = -1;
    while (p < n * m - 1 and vis[g[p + 1].x][g[p + 1].y] == false) {
        p++;//注意下标的使用,谨防越界

        vis[g[p].x][g[p].y] = true;
        for (int x = g[p].x + 1; x <= n; ++x) {
            //if (g[p].y == 1 or vis[x][g[p].y - 1])break;//注意下标的使用,谨防越界
            for (int y = g[p].y - 1; y >= 1; --y) {
                if (vis[x][y])break;
                vis[x][y] = true;
            }
        }

        for (int x = g[p].x - 1; x >= 1; --x) {
            //if (g[p].y == m or vis[x][g[p].y + 1])break; //注意下标的使用, 谨防越界
            for (int y = g[p].y + 1; y <= m; ++y) {
                if (vis[x][y])break;
                vis[x][y] = true;
            }
        }
    }

    cout << p + 1 << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)solve();
    return 0;
}