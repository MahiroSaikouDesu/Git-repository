#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;

string mae;
stack<int> kakko;

string cha(string s)
{
    string r;
    for (auto it = s.rbegin(); it != s.rend(); it++)
    {
        if ((*it) == '(' || (*it) == ')')
            r += (*it);
        else
            r += (*it) >= 97 ? (*it) - 32 : (*it) + 32;
    }
    return r;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> mae;
    for (int i = 0; i < mae.length(); i++)
    {
        if (mae[i] == '(')
        {
            kakko.push(i);
        }
        else if (mae[i] == ')')
        {
            string bef = cha(mae.substr(kakko.top() + 1, i - kakko.top() - 1));
            int cnt = 0;
            for (int j = kakko.top() + 1; j < i; j++)
                mae[j] = bef[cnt++];
            kakko.pop();
            //cout << mae << '\n';
        }
    }
    for (auto i : mae)
    {
        if (i != '(' && i != ')')
            cout << i;
    }
    return 0;
}