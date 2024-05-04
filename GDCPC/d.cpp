#include <bits/stdc++.h>
#define il inline
#define ll long long
using namespace std;
typedef pair<int, int> P;
void work() {
	//k - 有多少人有邻居 [0,N]
	vector<int>k(1);
	int n, m, limit;
	ll ans = 0, cnt = 0;
	cin >> n >> m;
	if (2 * n - 1 <= m) limit = 0;
	else limit = 2 * n - m;
	for (int i = 1; i <= n; i++) {
		// a - having b - not having
		int a, b;
		cin >> a >> b;
		cnt += (ll)b;
		k.push_back(a - b);
	}
	sort(k.begin() + 1, k.end(), greater<int>());
	/*for (int i = 0; i <= n; i++) {
		cout << k[i] << " ";
	}
	cout << '\n';*/
	if (2 * n - 1 <= m)
		ans = cnt;
	cnt += (ll) k[1];
	for (int i = 2; i <= n; i++) {
		cnt += (ll)k[i];
		//cout << i << ' ' << cnt << ' ' << ans << '\n';
		if (2 * n - i <= m)
			ans = max(cnt, ans);
	}
	//cout << limit << ' ' << cnt << ' ' << ans << '\n';
	cout << ans << '\n'; 
}
int main() {
	int T;
	cin >> T;
	while (T--)
		work();
	return 0;
}
/*
1
2 3
100 50
1 1000
*/
