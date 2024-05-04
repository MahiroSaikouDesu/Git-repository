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
	int al = read(), bl = read(), cnt = 0;
	string a, b;
	cin >> a >> b;
	for (auto& t : b) {
		if (a[cnt] == t)
			cnt++;
	}
	cout << cnt << '\n';
}
int main() {
	int t = read();
	while (t--)
		work();
	return 0;
}
