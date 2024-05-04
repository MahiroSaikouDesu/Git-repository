#include <bits/stdc++.h>
#define il inline
#define ll long long
using namespace std;
const int N = 2e5 + 10;
typedef pair<ll, ll> P;
P v[N];
ll pcnt[2] = { 0 }, psum[2] = { 0 };
int main() {
	int t;
	cin >> t;
	ll ans = 0;
	for (int i = 1; i <= t; i++) {
		ll a, b;
		cin >> a >> b;
		v[i].first = a + b;
		v[i].second = b - a;
	}
	
	sort(v + 1, v + 1 + t, [](P a, P b) {
		return a.first < b.first;
		});
	for (int i = 1; i <= t; i++) {
		int tmp = v[i].first & 1;
		ans += pcnt[tmp] * v[i].first - psum[tmp];
		pcnt[tmp]++, psum[tmp] += v[i].first;
	}

	memset(pcnt, 0, sizeof pcnt);
	memset(psum, 0, sizeof psum);

	sort(v + 1, v + 1 + t, [](P a, P b) {
		return a.second < b.second;
		});
	for (int i = 1; i <= t; i++) {
		int tmp = v[i].first & 1;
		ans += pcnt[tmp] * v[i].second - psum[tmp];
		pcnt[tmp]++, psum[tmp] += v[i].second;
	}
	cout << ans / 2 <<endl;
	return 0;
}
