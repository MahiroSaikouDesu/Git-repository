#include <bits/stdc++.h>
#define il inline
#define ll long long
using namespace std;
void work() {
	int cnt = 0;
	ll ans = 0;
	string l;
	vector<int> aft;
	getline(cin, l);
	for (int i = 0; i < l.size(); i++) {
		if (l[i] == '0') {
			if (cnt)
				aft.push_back(cnt);

			cnt = 0;
			aft.push_back(0);
		}
		else
			cnt++;
	}
	if (cnt)
		aft.push_back(cnt);
	cnt = 0;
	for (auto& t : aft) {
		if (t)
			cnt += t;
		else
			if(cnt)
				ans += (ll)(cnt + 1);
	}
	cout << ans << '\n';
}
int main() {
	int t;
	cin >> t;
	getchar();
	while (t--)
		work();
	return 0;
}
