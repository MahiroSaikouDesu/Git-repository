#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> P;
const int inf = 0x3f3f3f3f << 1;
const int N = 2e5 + 10;

int t, n, k, tmp;
map<int, int> mp;

bool check(int x)
{
    auto it = mp.begin(), lst = it;
    it++;
    int cnt = 1, res = (*lst).second, ans = res;
    queue<int> v;
    v.push((*lst).second);
    while (it != mp.end())
    {
        if ((*it).first == (*lst).first + 1)
        {
            cnt++;
            if (cnt <= k)
            {
                v.push((*it).second);
                cnt++;
            }
            else
            {
                res -= v.front();
                v.pop();
            }
            res += (*it).second;
        }
        else
        {
            cnt = 1;
            res = (*it).second;
        }
        ans = max(ans, res);
        it++;
        if (it == mp.end())
        {
        }
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        mp.clear();
        for (int i = 1; i <= n; i++)
        {
            cin >> tmp;
            mp[tmp]++;
        }
        int l = 0, r = n, mid, res;
        while (l <= r)
        {
            mid = (l + r) >> 1;
            if (check(mid))
                l = mid + 1, res = mid;
            else
                r = mid - 1;
        }
        cout << res << '\n';
    }
    return 0;
}