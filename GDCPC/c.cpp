#include <bits/stdc++.h>
#define il inline
#define ll long long
using namespace std;
const int N = 1e6 + 10;
struct node {
	int v, b;
	bool operator<(const node& a)const {
		return v < a.v;
	}
}p[N];
int main() {
	int k;
	cin >> k;
	while (k--) {
		int n;
		cin >> n;
		int ans = 0, l = 1, r = n;
		for (int i = 1; i <= n; i++) {
			cin >> p[i].v >> p[i].b;
		}
		sort(p + 1, p + 1 + n);
		for (int i = 1; i <= n; i++) {
			cout << p[i].v << ' ' << p[i].b << '\n';
		}
		while (l < n) {
			if (p[l].b < p[r].b) {
				p[r].b -= p[l].b;
				ans += p[l].b * (p[r].v - p[l].v);
				l++;
			}
			else if (p[l].b > p[r].b) {
				p[l].b -= p[r].b;
				ans += p[r].b * (p[r].v - p[l].v);
				r--;
			}
			else {
				ans += p[r].b * (p[r].v - p[l].v);
				l++, r--;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
