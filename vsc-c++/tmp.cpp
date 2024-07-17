#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;
const int N = 0;

struct node
{
    int b;
    friend operator<(const node &n1, const node &n2)
    {
        return n1.b < n2.b;
    }
};

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    node a;
    a.b = 1;
    set<node> ans;
    ans.insert(a);
    cout << (*ans.begin()).b;
    return 0;
}