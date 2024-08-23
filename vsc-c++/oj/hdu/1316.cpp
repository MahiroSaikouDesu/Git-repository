#include <bits/stdc++.h>
using namespace std;
vector<string> fib(600);

int Cmp(string &num1, string &num2)
{
    if ((num1.size() > num2.size()) || (num1.size() == num2.size() && num1 > num2))
        return 1; // num1 > num2
    else if ((num1.size() < num2.size()) || (num1 < num2))
        return -1; // num1 < num2;
    else
        return 0; // num1 == num2
}

string Addstring(string num1, string num2)
{
    int len1 = num1.length() - 1, len2 = num2.length() - 1;
    string res;
    int carry = 0, a, b, sum;
    while (len1 >= 0 || len2 >= 0)
    {
        a = 0, b = 0;
        if (len1 >= 0)
            a = num1[len1--] - '0';
        if (len2 >= 0)
            b = num2[len2--] - '0';
        sum = a + b + carry;
        if (sum > 9)
            sum -= 10, carry = 1;
        else
            carry = 0;
        res += sum + '0';
    }
    if (carry)
        res += '1';
    reverse(res.begin(), res.end());
    return res;
}

void init()
{
    fib[1] = "1";
    fib[2] = "2";
    for (int i = 3; i < 570; i++)
        fib[i] = Addstring(fib[i - 1], fib[i - 2]);
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string a, b;
    init();
    int ans, r1, r2;
    while (cin >> a >> b)
    {
        if (a[0] == '0' && b[0] == '0')
            break;
        ans = 0;
        for (int i = 1; i < 570; i++)
        {
            r1 = Cmp(fib[i], a), r2 = Cmp(fib[i], b);
            if (r1 >= 0 && r2 <= 0)
                ans++;
            if (r1 > 0 && r2 > 0)
                break;
        }
        cout << ans << '\n';
    }
    return 0;
}