#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
int read()
{
    int sum = 0, f = 1;
    char a = getchar();
    while (a < '0' || a > '9')
    {
        if (a == '-')
            f *= -1;
        a = getchar();
    }
    while (a >= '0' && a <= '9')
    {
        sum = (sum << 3) + (sum << 1) + a - '0';
        a = getchar();
    }
    return f * sum;
}

int main()
{
    int n = read();
    while (n--)
    {
        string tmp;
        cin >> tmp;
        int flag = 1;
        for (int i = 1; i < tmp.size(); i++)
            if (tmp[i] != tmp[0])
            {
                flag = 0;
                cout << "YES\n";
                swap(tmp[i], tmp[0]);
                cout << tmp << '\n';
                break;
            }

        if (flag)
            cout << "NO\n";
    }
    return 0;
}