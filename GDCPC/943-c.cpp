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
	int n = read();
	vector<ll>a(n + 1), x(n + 1);
	for (int i = 2; i <= n; i++)
		x[i] = read();
	a[1] = x[2] + 1;
	for (int i = 2; i <= n; i++) {
		if (x[i] >= a[i - 1]) {
			ll temp = (x[i] - x[i - 1]) / a[i - 2];
			while (a[i - 2] * temp + x[i - 1] <= x[i])
				temp++;
			a[i - 1] = a[i - 2] * temp + x[i - 1];
		}
		a[i] = x[i];
	}
	for (int i = 1; i <= n; i++)
		cout << a[i] << ' ';
	cout << '\n';
}
int main() {
	int t = read();
	while (t--)
		work();
	return 0;
}
