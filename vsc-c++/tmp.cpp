#include <bits/stdc++.h>
using namespace std;

int fuctionName(int x,int y)
{
    int z = 0;
    z = x * y;
    return 0;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int num1 = 0, num2 = 0;
    scanf_s("%d%d", &num1, &num2);
    int sum = fuctionName(num1, num2);
    printf("%d", sum);
    return 0;
}