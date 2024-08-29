#include <bits/stdc++.h>
using namespace std;

int a;//全局变量默认初始为0
void test()
{
    a++;
    printf("%d ", a);
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int i = 0;
    while(i<10)
    {
        test();
        i++;
    }
    return 0;
}