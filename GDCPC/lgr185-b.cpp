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
void work() {
	ll n, m, ans = 1;
	cin >> n >> m;
	if (n == 1)
		ans = m + 1;
	else {
		vector<int> mp(m + 1);
		for (int i = 2; i <= m; i++) {
			if (mp[i]) continue;
			//if ((n % i == 0||(n % (i % n) == 0&&i%n!=1)) && (i % 2 == n % 2)) {
			if((i % 2 == n % 2)  && ((n % i == 0 || i % n == 0) || (i % n != 1 && n % (i % n) == 0))){
				mp[i] = 1;
			}
		}
		for (auto& t : mp)
			ans = t ? ans + 1 : ans;
		for (int i = 0; i <= m; i++) {
			cout << "x=" << i << " " << mp[i] << '\n';
			for (int j = 0; j < n; j++) {
				cout << j << ',' << (i * j) % n << ' ';
			}
			cout << '\n';
		}
		mp[0] = 1;
		for (auto& t : mp)
			cout << t << ' ';
	}
	cout << ans << '\n';
}
int main() {
	int T = read();
	while (T--)
		work();
	return 0;
}
