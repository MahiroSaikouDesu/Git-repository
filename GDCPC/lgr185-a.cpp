#include <bits/stdc++.h>
#define il inline
#define ll long long
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		v.push_back(t);
	}
	sort(v.begin(), v.end());
	int l = 0, r = n - 1;
	vector<int> ans1, ans2;
	while (l < r) {
		ans1.push_back(v[r]);
		ans1.push_back(v[l]);
		ans2.push_back(v[l]);
		ans2.push_back(v[r]);
		l++;
		r--;
	}
	ans1.push_back(v[n / 2]);
	ans2.push_back(v[n / 2]);
	for (int i = 0; i < n; i++) {
		cout << ans1[i] << " ";
	}
	cout << '\n';
	for (int i = 0; i < n; i++) {
		cout << ans2[i] << ' ';
	}
	return 0;
}
