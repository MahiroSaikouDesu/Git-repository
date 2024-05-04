#include <bits/stdc++.h>
#define il inline
#define ll long long
using namespace std;
const int N = 1e6 + 10;
struct node {
	int x, y;
}num[N];
void work() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int t;
			cin >> t;
			num[t] = { i,j };
		}
	}

	vector<vector<int> > mp;
	for (int i = 0; i <= n; i++) {
		vector<int> line(m + 1);
		mp.push_back(line);
	}

	int flag = m * n;
	for (int i = 0; i <= n * m - 1; i++) {
		if (mp[num[i].x][num[i].y]) {
			flag = i;
			break;
		}
		else {
			int x = num[i].x, y = num[i].y;

			for (int i = x + 1; i <= n; i++) {
				if (y == 1 || mp[i][y - 1]) break;
				for (int j = y - 1; j > 0; j--)
					if (mp[i][j]) break;
					else mp[i][j] = 1;
			}

			for (int i = x - 1; i >= 1; i--) {
				if (y == m || mp[i][y + 1]) break;
				for (int j = y + 1; j <= m; j++) {
					if (mp[i][j]) break;
					else mp[i][j] = 1;
				}
			}
		}
	}
	cout << flag << '\n';
}
int main() {
	int T;
	cin >> T;
	while (T--) 
		work();
	
	return 0;
}
