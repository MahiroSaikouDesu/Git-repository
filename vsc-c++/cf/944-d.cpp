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
        int cnt = 0;
        string line;
        cin >> line;
        for (int i = 0; i < line.size(); i++)
        {
            if (i == line.size() - 1)
                cnt++;
            else if (line[i] == '1' && line[i + 1] == '0')
                cnt++;
        }
        cout << cnt << '\n';
    }
    return 0;
}