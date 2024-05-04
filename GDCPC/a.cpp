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
int main() {
	int t = read();
	while (t--) {
		int y1 = read(), n = read();
		vector<int> stop;
		while (n--) {
			stop.push_back(read());
		}
		int ch = read(), cnt = 0;
		for (auto& t : stop) {
			if (t > ch) break;
			else cnt++;
		}
		cout << ch - y1 - cnt + 1 << '\n';
	}
	return 0;
}
