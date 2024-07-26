#include <stdio.h>
#include <iostream>
#include <map>
#include <cstring>
using namespace std;
#define ll long long
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;

signed main()
{
    map<string, string> mp;
    char str1[15], str2[15], str[40];
    while (gets(str))
    {
        if (strlen(str) == 0)
            break;
        sscanf(str, "%s %s", str1, str2);
        mp[str2] = str1;
    }
    string now;
    while (cin >> now)
    {
        map<string, string>::iterator it = mp.find(now);
        if (it == mp.end())
            cout << "eh" << '\n';
        else
            cout << (*it).second << '\n';
    }
    return 0;
}