#include <bits/stdc++.h>
using namespace std;

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

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        string sum = "0", a;
        while (getline(cin, a) && a != "0")
            sum = Addstring(sum, a);

        cout << sum << '\n';
        if (T)
            cout << '\n';
    }
    return 0;
}