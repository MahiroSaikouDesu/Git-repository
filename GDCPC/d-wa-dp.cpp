#include <bits/stdc++.h>
#define il inline
#define ll long long
using namespace std;
typedef pair<int, int> P;
int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, m;
		ll ans = 0;
		cin >> n >> m;
		cout << 2 * n << ' ' << m << '\n';
		if (n == m) {
			for (int i = 1; i <= n; i++) {
				int a, b;
				cin >> a >> b;
				ans += (ll)a;
			}
			cout << ans << '\n';
		}
		else {
			int flag = 0, k = m - n + 1;
			vector<P> v;
			vector<vector<ll> > ans;
			for (int i = 1; i <= n; i++) {
				int a, b;
				cin >> a >> b;
				if (a > b) flag++;
				v.push_back({ a,b });
			}
			//可以任选 并且 可以选择邻居
			if (2 * n >= m + 1 && flag != 1) {
				ll cnt = 0;
				for (auto& t : v) {
					cnt += (ll)max(t.first, t.second);
				}
				cout << cnt << '\n';
			}
			else {
				// first - haing  | second - not having
				for (int i = 0; i < n; i++) {
					vector<ll> tt;
					tt.push_back(1LL * v[i].first);
					//第一个
					if (i == 0) {
						for (int j = 1; j <= k; j++)
							tt.push_back(1LL * max(v[i].first, v[i].second));
					}
					//第二个之后
					else {
						tt[0] += ans[i - 1][0];
						for (int j = 1; j <= k; j++) {
							tt.push_back(1LL * max(ans[i - 1][j] + v[i].first, ans[i - 1][j - 1] + v[i].second));
						}
					}
					ans.push_back(tt);
				}
				/*for (auto& t : ans) {
					for (auto& tt : t)
						cout << tt << " ";
					cout << '\n';
				}*/
				cout << ans.back().back() << '\n';
			}
		}
	}
	return 0;
}

/*
1
2 3
100 50
1 1000
*/

/*
1
3 5
1 2
100 2
1 2

*/
