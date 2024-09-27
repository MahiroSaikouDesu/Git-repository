#include <string.h>
#include <iostream>
#include <vector>
using namespace std;
string s;
vector<string> v;
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    while (getline(cin, s))
    {
        v.push_back(s);
    }
}