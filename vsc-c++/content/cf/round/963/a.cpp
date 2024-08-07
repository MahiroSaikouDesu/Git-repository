#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> Pii;
const int inf = (1 << 30) + 1;

int work()
{
    int n;
    cin >> n;
    vector<int> ans(6);
    int t = n << 2, res = 0;
    char tmp;
    while (t--)
    {
        cin >> tmp;
        if (tmp == '?')
            continue;
        else
            ans[tmp - 'A']++;
    }
    for (int i = 0; i < 4; i++)
        res += min(n, ans[i]);
    return res;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--)
        cout << work() << '\n';
    return 0;
}