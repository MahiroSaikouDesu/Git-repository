#include <stdio.h>
#include <string.h>
int f(int m, int n)
{
    int sum = 1, sum1 = 1;
    int i;
    for (i = 1; i <= n; i++)
        sum *= i;
    for (i = m; i > m - n; i--)
        sum1 *= i;
    return sum1 / sum;
}
int main()
{
    int t;
    int sum;
    int i, j, len;
    char s[10];
    int a[10];
    scanf("%d", &t);
    while (t--)
    {
        getchar();
        sum = 1;
        scanf("%s", s);
        len = strlen(s);
        for (i = 1; i < len; i++)
        {
            sum += f(26, i); // 小于字符串长度的所有情况
        }
        for (i = 0; i < len; i++)
        {
            a[i] = s[i] - 96; // 计算每个字符从a开始的数值
            // printf("%d ",a[i]);
        }
        // printf("%d\n",f(26,2));
        int temp = 1;
        for (i = len; i > 0; i--)
        {
            for (j = temp; j < a[len - i]; j++)
            {
                sum += f(26 - j, i - 1); // 依次扫描字符，计算所有情况
            }
            temp = a[len - i] + 1;
        }
        printf("%d\n", sum);
    }
    return 0;
}