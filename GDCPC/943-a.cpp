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
int gcd(int a, int b)
{
	if (b) while ((a %= b) && (b %= a));
	return a + b;
}
int aans[2000];
void work(int t) {
	if (aans[t]) {
		cout << aans[t] << '\n';
		return;
	}
	int cnt = t - 1, minn = 1, ansnum = 0, maxx = 0;
	while (cnt >= minn) {
		int temp = gcd(t, cnt);
		if (maxx < temp + cnt) {
			ansnum = cnt;
			maxx = temp + cnt;
			minn = max(minn, temp);
		}
		cnt--;
	}
	aans[t] = ansnum;
	cout << ansnum << '\n';
}
int main() {
	int t = read();
	while (t--) 
		work(read());
	return 0;
}
