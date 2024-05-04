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
	int n = read(), flag = 0;
	vector<int> v(n + 1);
	for (int i = 1; i <= n; i++) {
		v[i] = read();
		if (v[v[i]] == i) flag = 1;
	}
	if (flag)
		cout << 2 << '\n';
	else
		cout << 3 << '\n';
}
int main() {
	int t = read();
	while (t--)
		work();
	return 0;
}
