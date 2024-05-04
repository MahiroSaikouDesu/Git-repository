#include <bits/stdc++.h>
#define il inline
#define ll long long
using namespace std;
struct node {
	int x, y, vis;
}p[10];

int n, m, k, ans;
int mp[10][10];
int fx[4] = { 1,-1,0,0 }, fy[4] = { 0,0,1,-1 };

int check(int x, int y) {
	if (x<1 || y<1 || x>n || y>m) return 1;
	else return 0;
}
void print() {
	cout << '\n';
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			cout << mp[i][j] << ' ';
		cout << '\n';
	}
}
void dfs(int pp) {
	ans = min(ans, pp);
	for (int i = 1; i <= k; i++) {
		// 被吃掉
		if (p[i].vis) continue;
		int x = p[i].x, y = p[i].y;
		for (int j = 0; j < 4; j++) {
			int cx = fx[j] + x, cy = fy[j] + y;
			//旁边有棋子
			if (check(cx, cy) || !mp[cx][cy]) continue;
			//落点无棋子
			int nx = 2 * fx[j] + x, ny = 2 * fy[j] + y;
			if (check(nx, ny) || mp[nx][ny]) continue;
			//print();

			int cnum = mp[cx][cy];
			p[mp[cx][cy]].vis = 1;
			p[i].x = nx, p[i].y = ny;
			mp[x][y] = 0;
			mp[cx][cy] = 0;
			mp[nx][ny] = i;
			//print();
			dfs(pp-1);

			p[cnum].vis = 0;
			p[i].x = x, p[i].y = y;
			mp[x][y] = i;
			mp[cx][cy] = cnum;
			mp[nx][ny] = 0;
			//print();
		}
	}
}
int main() {
	int T;
	cin >> T;
	while (T--) {
		memset(mp, 0, sizeof(mp));
		cin >> n >> m >> k;
		for (int i = 1; i <= k; i++) {
			cin >> p[i].x >> p[i].y;
			p[i].vis = 0;
			mp[p[i].x][p[i].y] = i;
		}
		ans = 6;
		dfs(k);
		cout << ans << '\n';
	}
	return 0;
}
