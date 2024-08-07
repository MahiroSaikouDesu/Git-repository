#include <bits/stdc++.h>
using namespace std;
#define int long long
int work()
{
    priority_queue<int, vector<int>, greater<int>> q;
    int l, r, res = 0;
    cin >> l >> r;
    for (int i = l; i <= r; i++)
        q.push(i);
    while (q.size() > 1)
    {
        res++;
        int t1 = q.top();
        q.pop();
        int t2 = q.top();
        q.pop();
        if (t1 == 1 || t2 == 1)
        {
            if (t1 == 1)
                t1 = 0, t2 *= 3;
            else
                t1 *= 3, t2 = 0;
        }
        else if (!t1)
            t2 /= 3;
        else
        {
            if (t1 % 3 >= t2 % 3)
                t1 /= 3, t2 *= 3;
            else
                t1 *= 3, t2 /= 3;
        }
        if (!t1 && !t2)
            q.push(t1);
        else
            q.push(t1), q.push(t2);
    }
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