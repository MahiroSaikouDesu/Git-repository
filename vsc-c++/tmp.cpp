#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll C(int n, int m)
{
    ll res = 1;
    m = min(m, n - m);
    for (int i = 0; i < m; ++i)
    {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

ll f(string s)
{
    ll res = 1;
    for (int i = 1; i < s.length(); i++)
        res += C(26, i);
    
    for (int i = 1; i <= s.length(); i++)
        for (int j = i == 1 ? 'a' : s[i - 2] + 1; j <= s[i - 1] - 1; j++)
            res += C('z' - j, s.length() - i);

    return res;
}
int main()
{
    string s;
    cin >> s;
    cout << f(s) << '\n';
    return 0;
}