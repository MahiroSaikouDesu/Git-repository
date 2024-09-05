#include <bits/stdc++.h>
using namespace std;

int isequal(char a[], char b[])
{
    int it = 0;
    while (a[it] != '\0' && b[it] != '\0')
        if (a[it] != b[it])
            return 0;
        else
            it++;
    return 1;
}

signed main()
{
    char a[40], b[40];
    scanf("%s", a);
    scanf("%s", b);
    cout << "a: " << a << '\n';
    cout << "b: " << b << '\n';
    cout << (isequal(a, b) ? 1 : 0) << '\n';
    cout << &a << ' ' << &b << '\n';
    return 0;
}