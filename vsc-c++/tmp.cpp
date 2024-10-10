#include <bits/stdc++.h>
using namespace std;

string b, split = "."; // split 为分割子字符串

void test(string s)
{
    vector<string> v;

    while (1)
    {
        int fi = s.find(split);
        if (fi == string::npos)
        {
            v.push_back(s);
            break;
        }

        v.push_back(s.substr(0, fi));
        s = s.substr(fi + split.length());
    }

    for (auto i : v)
        cout << i << '\n';
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> b;
    test(b);
    return 0;
}