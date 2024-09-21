#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> P;

string s;
vector<int> a;

vector<int> fuc(string s)
{
    vector<int> tmpv;
    for (int i = 0; i < s.length();i++)
        tmpv.push_back(s[i]);
    return tmpv;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> s;
    a = fuc(s);
    for(auto i:a)
        cout << i << '\n';
    return 0;
}