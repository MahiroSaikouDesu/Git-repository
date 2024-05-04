#include <bits/stdc++.h>
#define il inline
#define ll long long
using namespace std;
const int N = 2e6 + 10;
ll p[N], a[N];
int n, k, ps, pb;
ll getscore(int x) {
	ll pre = 0, cnt = a[x] * k;
	for (int i = 1; i <= min(n, k); i++) {
		pre += a[x];
		x = p[x];
		cnt = max(cnt, pre + a[x] * (k - i));
	}
	return cnt;
}
void work() {
	cin >> n >> k >> pb >> ps;
	for (int i = 1; i <= n; i++) cin >> p[i];
	for (int i = 1; i <= n; i++) cin >> a[i];
	ll score_b = getscore(pb);
	ll score_s = getscore(ps);
	//cout << score_s << ' ' << score_b << '\n';
	if (score_b > score_s)
		cout << "Bodya\n";
	else if (score_b < score_s)
		cout << "Sasha\n";
	else
		cout << "Draw\n";
}
int main() {
	int t;
	cin >> t;
	while (t--)
		work();
	return 0;
}
