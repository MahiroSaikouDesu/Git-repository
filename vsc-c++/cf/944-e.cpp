#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
int read()
{
    int sum = 0, f = 1;
    char a = getchar();
    while (a < '0' || a > '9')
    {
        if (a == '-')
            f *= -1;
        a = getchar();
    }
    while (a >= '0' && a <= '9')
    {
        sum = (sum << 3) + (sum << 1) + a - '0';
        a = getchar();
    }
    return f * sum;
}
struct node
{
    int a, begin, last;
    node(int x, int y, int z) { a = x, begin = y, last = z; }
};
class cmp
{
public:
    bool operator()(const node a, const node b) const
    {
        return a.a > b.a;
    }
};
int main()
{
    int t = read();
    while (t--)
    {
        int n = read(), k = read(), q = read();
        set<node, cmp> s;
        vector<int> v1(1), v2(1);
        for (int i = 0; i < k; i++)
            v1.push_back(read());
        for (int i = 0; i < k; i++)
            v2.push_back(read());
        for (int i = 0; i <= k; i++)
            if(i!=k)
                s.insert(node(v1[i], v2[i], v2[i + 1] - v2[i]));
            else
                s.insert(node(v1[i], v2[i], 0));

        while (q--)
        {
            int d = read();
            auto it = s.lower_bound(node(d, v2.back(), v2.back()));
            // a - first b - second
            node tmp1 = *it;
            it++;
            node tmp2 = *it;

            cout << tmp1.a << ' ' << tmp1.begin << ' ' << tmp1.last << '\n';
            cout << tmp2.a << ' ' << tmp2.begin << ' ' << tmp2.last << '\n';
            cout << fixed << setprecision(0) << floor(tmp1.begin * 1.0 + (d - tmp1.a) * 1.0 / (tmp2.begin - tmp1.begin) * tmp1.last) << '\n';
        }
        cout << '\n';
    }
    return 0;
}