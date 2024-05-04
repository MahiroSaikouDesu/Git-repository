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
	int a = 0;
	for (int i = 1; i <= 9; i++)
		a += read();
	int b = 0;
	for (int i = 1; i <= 8; i++)
		b += read();
	cout << a + 1 - b;
	return 0;
}
