#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> Pii;
const int inf = 0x3f3f3f3f << 1;
const int N = 2e5 + 10;

string line;
map<int, int> mp1, mp2;
int a[N], n, T, m, flag, now;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];

        cin >> m;
        while (m--)
        {
            flag = 1;
            cin >> line;
            mp1.clear();
            mp2.clear();
            if (line.size() != n)
                flag = 0;
            else
            {
                for (int i = 0; i < n; i++)
                {
                    now = (int)line[i];
                    auto it1 = mp1.find(now), it2 = mp2.find(a[i]);
                    if (it1 == mp1.end() || it2 == mp2.end())
                    {
                        if (it1 == mp1.end() && it2 == mp2.end())
                            mp1[now] = a[i], mp2[a[i]] = now;
                        else
                        {
                            flag = 0;
                            break;
                        }
                    }
                    else
                    {
                        Pii i1 = (*it1), i2 = (*it2);
                        if (i1.second != i2.first || i2.second != i1.first)
                        {
                            flag = 0;
                            break;
                        }
                    }
                }
            }
            cout << (flag ? "YES" : "NO") << '\n';
        }
    }
    return 0;
}