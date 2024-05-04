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
struct node {
	// total per number k-use
	int num;
	ll tot;
	double p;
	node(int a, ll b, double c) { num = a, tot = b, p = c; }
	bool operator<(const node& a)const {
		return p < a.p;
	}
};

void work() {
	int n = read(), k = read(), flag = 0;
	vector<int> v(n + 1);
	vector<vector<node> > ku(11);
	priority_queue<node> q;
	for (int i = 1; i <= n; i++)
		v[i] = read();
	for (int i = 1; i <= n; i++) {
		if(flag<10 && (i == 1 || v[i - 1] < v[i]) && (i == n || v[i + 1] >= v[i]))
		if ((i == 1 || v[i - 1] < v[i]) && (i == n || v[i + 1] < v[i] || flag == 10)) {
			//left
			int now = 1;
			ll cnt = 0;
			for (int j = i - 1; j >= 1; j--) {
				cnt += 1LL * now * v[j + 1];
				
			}
		}
	}
	while (!q.empty() && k) {

	}
}
int main() {
	int t = read();
	while (t--)
		work();
	return 0;
}
