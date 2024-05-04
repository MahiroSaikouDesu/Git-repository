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
	int now;
	unsigned ll val; 
	int k;
	bool operator<(const node& a)const {
		if (k != a.k)
			return k > a.k;
		else
			return val < a.val;
	}
};
void work() {
	int n = read(), k = read(), pb = read(), ps = read();
	unsigned ll bans = 0, sans = 0;
	vector<int> p(n + 1), a(n + 1);
	vector<unsigned ll>ab(n + 1), as(n + 1);
	for (int i = 1; i <= n; i++)
		p[i] = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	priority_queue<node> q;
	q.push(node{ pb,0,1 });
	while (!q.empty()) {
		node now = q.top();
		q.pop();
		if (ab[now.now] > now.val)
			continue;
		if (now.k > k) {
			bans = max(bans, 1uLL * now.val);
			break;
		}
		if (now.now == p[now.now]) {
			unsigned ll temp = now.val + 1uLL * a[now.now] * (k - now.k + 1);
			//cout << k - now.k + 1 << '\n';
			bans = max(bans, temp);
			continue;
		}
		now.val += a[now.now];
		ab[now.now] = now.val;
		q.push(node{ now.now,now.val,now.k + 1 });
		q.push(node{ p[now.now],now.val,now.k + 1 });
	}
	while (!q.empty())
		q.pop();
	q.push(node{ ps,0,1 });
	while (!q.empty()) {
		node now = q.top();
		q.pop();
		if (as[now.now] > now.val)
			continue;
		if (now.k > k) {
			sans = max(sans, 1uLL * now.val);
			break;
		}
		if (now.now == p[now.now]) {
			unsigned ll temp = now.val + 1uLL * a[now.now] * (k - now.k + 1);
			sans = max(sans, temp);
			continue;
		}
		now.val += a[now.now];
		as[now.now] = now.val;
		q.push(node{ now.now,now.val,now.k + 1 });
		q.push(node{ p[now.now],now.val,now.k + 1 });
	}
	//cout << bans << ' ' << sans << '\n';
	if (bans > sans)
		cout << "Bodya\n";
	else if (bans < sans)
		cout << "Sasha\n";
	else
		cout << "Draw\n";
}
int main() {
	int t = read();
	while (t--)
		work();
	return 0;
}

/*
1
2 1000000000 1 2
1 2
2 1000000000
*/