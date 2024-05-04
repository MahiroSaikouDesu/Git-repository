#include <bits/stdc++.h>
#define il inline
#define ll long long
using namespace std;
il int read() {
	int sum = 0, f = 1; char a = getchar();
	while (a < '0' || a>'9') {
		if (a == '-') f *= -1;
		a = getchar();
	}
	while (a >= '0' && a <= '9') {
		sum = (sum << 3) + (sum << 1) + a - '0';
		a = getchar();
	}
	return f * sum;
}
typedef pair<int, int> P;
const int N = 1e3 + 10;
int mp[N][N], mov[N][N], vis[N][N], ans, h, w;
int fx[4] = { 1,-1,0,0 }, fy[4] = { 0,0,1,-1 };
int main() {
	h = read(), w = read();
	for (int i = 1; i <= h; i++) {
		string now;
		getline(cin, now);
		for (int j = 0; j < w; j++)
			if (now[j] == '.')
				mp[i][j + 1] = 0;
			else {
				mov[i - 1][j + 1] = 1;
				mov[i + 1][j + 1] = 1;
				mov[i][j] = 1;
				mov[i][j + 2] = 1;
				mp[i][j + 1] = 1;
			}
	}
	for(int i=1;i<=h;i++)
		for (int j = 1; j <= w; j++) {
			if (vis[i][j] || mp[i][j])
				continue;
			if (mov[i][j]) {
				ans = max(ans, 1);
				continue;
			}
			int flag = 0, nowflag = i * w + j;
			queue<P> q;
			q.push({ i,j });
			while (!q.empty()) {
				P now = q.front();
				q.pop();
				if (vis[now.first][now.second] == nowflag) continue;
				vis[now.first][now.second] = nowflag;
				flag++;
				int x = now.first, y = now.second;
				//cout << x << ' ' << y << ' ' << flag << '\n';
				if (mov[x][y]) continue;
				for (int k = 0; k < 4; k++) {
					int nx = fx[k] + x, ny = fy[k] + y;
					if (nx<1 || ny<1 || nx>h || ny>w || vis[nx][ny]) continue;
						q.push({ nx,ny });
				}
			}
			ans = max(ans, flag);
		}
	cout << ans;
	return 0;
}