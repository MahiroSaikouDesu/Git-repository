#include <bits/stdc++.h>
using namespace std;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T, flag, cnt;
    cin >> T;
    string line, be;
    while (T--)
    {
        flag = 1, cnt = 0;
        cin >> line;
        if (line[0] != '1' || line[1] != '0' || line[2] == '0')
            flag = 0;
        else
        {
            be = line.substr(2);
            for (auto i : be)
                cnt *= 10, cnt += i - '0';
            if (cnt < 2)
                flag = 0;
        }
        cout << (flag ? "YES" : "NO") << '\n';
    }
    return 0;
}