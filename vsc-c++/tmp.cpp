#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;
const int N = 0;

double stQuery(int l, int r)
{
    double k = log2(r - l + 1);
    return k;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int l = 1, r = 5;
    cout << stQuery(l, r);
    return 0;
}