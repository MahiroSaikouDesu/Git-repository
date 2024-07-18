#include <iostream>
#include <map>
using namespace std;
#define ll long long
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;
const int N = 0;

map<int, int> mp;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int op;
    while (cin >> op && op)
    {
        switch (op)
        {
        case 1:
        {
            int k, p;
            cin >> k >> p;
            mp[p] = k;
            break;
        }
        case 2:
        {
            if (mp.empty())
                cout << 0 << '\n';
            else
            {
                map<int, int>::iterator it = --mp.end();
                cout << it->second << '\n';
                mp.erase(it);
            }
            break;
        }
        case 3:
        {
            if (mp.empty())
                cout << 0 << '\n';
            else
            {
                map<int, int>::iterator it = mp.begin();
                cout << it->second << '\n';
                mp.erase(it);
            }
            break;
        }
        }
    }
    return 0;
}