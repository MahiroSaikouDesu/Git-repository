#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> Pii;
string res;

int work()
{
    string s, t;
    cin >> s >> t;
    int it = 0, i;
    for (i = 0; i < t.length(); i++, it++)
    {
        for (; it < s.length(); it++)
        {
            if (s[it] == t[i])
                break;
            if (s[it] == '?')
            {
                s[it] = t[i];
                break;
            }
        }
        if (it == s.length())
            break;
    }
    res = s;
    return i == t.length() ? 1 : 0;
}

string solve(string s)
{
    string ans;
    for (auto i : s)
    {
        if (i != '?')
            ans += i;
        else
            ans += 'a';
    }
    return ans;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--)
        if (work())
            cout << "Yes\n"
                 << solve(res) << '\n';
        else
            cout << "NO\n";
    return 0;
}