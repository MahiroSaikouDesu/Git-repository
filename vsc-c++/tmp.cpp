#include <bits/stdc++.h>
using namespace std;
#define '\n' endl
int ans;
int mset, cnt;

int solve(int x, int y)
{
    if (x >= mset)
        x++;
    if (y >= mset)
        y++;
    return x * y;
}

void work()
{
    int l = 1, r = 1000, len;
    while (1)
    {
        len = (r - l) / 3;
        int ask1 = l + len - 1, ask2 = ask1 + len;
        int res = ask1 * (ask2 + 1), in;
        if (len <= 1)
        {
            int op = r - l;
            switch (op)
            {
            case 5:
            {
                cout << "? " << l << ' ' << l + 2 << '\n';
                cout.flush();
                res = l * (l + 3);
                in = solve(l, l + 2);
                cout << in;
                cout.flush();
                if (res != in)
                    l += 2;
                cout << "? " << l << ' ' << l + 1 << '\n';
                cout.flush();
                res = l * (l + 1);
                in = solve(l, l + 1);
                cout << in;
                cout.flush();
                ans = in == res ? l + 2 : l + 1;
                return;
            }
            case 4:
            {
                cout << "? " << l << ' ' << l + 2 << '\n';
                cout.flush();
                res = l * (l + 3);
                in = solve(l, l + 2);
                cout << in;
                cout.flush();
                if (in != res)
                {
                    ans = l + 3;
                    return;
                }
                cout << "? " << l << ' ' << l + 1 << '\n';
                cout.flush();
                res = l * (l + 1);
                in = solve(l, l + 1);
                cout << in;
                cout.flush();
                ans = in == res ? l + 2 : l + 1;
                return;
            }
            case 3:
            {
                cout << "? " << l << ' ' << l + 1 << '\n';
                cout.flush();
                res = l * (l + 1);
                in = solve(l, l + 1);
                cout << in;
                cout.flush();
                ans = in == res ? l + 2 : l + 1;
                return;
            }
            }
        }
        cout << "? " << ask1 << ' ' << ask2 << '\n';
        cout.flush();
        in = solve(ask1, ask2);
        cout << in;
        cout.flush();
        if (in == res)
        {
            l = ask1;
            r = ask2 + 1;
        }
        else if (in > res)
        {
            r = ask1 + 1;
        }
        else
            l = ask2;
        if (r - l == 2)
        {
            ans = l + 1;
            return;
        }
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int flag = 1;
    for (mset = 2; mset <= 999; mset++, cnt = 0)
    {
        ans = 0;
        work();
        if (ans != mset || cnt > 7)
        {
            flag = 0;
            break;
        }
    }
    if (flag)
        cout << "\nac";
    else
    {
        cout << "\nwa\n"
             << mset;
    }
    return 0;
}