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
	int n = read();
	string mp[110];
	for (int i = 1; i <= n; i++) {
		getline(cin, mp[i]);
	}
	for (int i = 1; i <= n; i++) {
		string now;
		getline(cin, now);
		for (int j = 0; j < n; j++) {
			if (mp[i][j] != now[j]) {
				cout << i << ' ' << j + 1;
				break;
			}
		}
	}
	return 0;
}
