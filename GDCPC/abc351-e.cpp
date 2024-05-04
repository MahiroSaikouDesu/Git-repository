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
const int N = 2e5 + 10;
int px[N], py[N];
int main() {
	int t = read();
	for (int i = 1; i <= t; i++) cin >> px[i] >> py[i];
	ll ans = 0;
	for (int i = 1; i < t; i++) {
		int flag = (px[i] + py[i]) % 2;
		for (int j = i + 1; j <= t; j++) {
			if ((px[j] + py[j]) % 2 != flag) continue;
			int disx = abs(px[j] - px[i]);
			int disy = abs(py[j] - py[i]);
			ans += 1LL * max(disx, disy);
		}
	}
	cout << ans;
	return 0;
}
