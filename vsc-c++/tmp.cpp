#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int a, b, c;
    cout << s;
    sscanf("a:=%d;b:=%d;c:=%d;", s.c_str(), &a, &b, &c);
    cout << a << ' ' << b << " " << c;
    return 0;
}