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
int main() {
	int k = read();
	while (k--) {
		vector<P> v;
		int n = read();
		int l = 0, r = n - 1;
		ll ans = 0;
		for (int i = 1; i <= n; i++) {
			int a = read(), b = read();
			v.push_back(make_pair(a, b));
		}
		if (n == 1) {
			cout << 0 << '\n';
			continue;
		}
		sort(v.begin(), v.end());
		while (l < r) {
			if (v[l].first == v[r].first) break;
			ans += 1LL * min(v[l].second, v[r].second) * (v[r].first - v[l].first);
			if (v[l].second == v[r].second) {
				l++, r--;
			}
			else if (v[l].second < v[r].second) {
				v[r].second -= v[l].second;
				l++;
			}
			else {
				v[l].second -= v[r].second;
				r--;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}