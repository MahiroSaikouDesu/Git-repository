#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> Pii;
const int inf = 0x3f3f3f3f;
const int N = ;
// 大数除法
string DivString(string num1, string num2, int n)
{
    if (num2 == "0") // 除数不能为0
        return "error";
    string ret; // 存储两个字符串相除后的结果
    string tmp; // 余数

    // 1、先计算小数点前面的数
    if (num1.size() < num2.size()) // num1的位数小于num2
    {
        ret += "0."; // 商为0
        tmp = num1;  // 余数为num1
    }
    else // num1的位数大于等于num2
    {
        size_t len = num2.size();  // 除数的长度
        tmp = num1.substr(0, len); // 先取出被除数的高len位
        while (1)
        {
            // a、计算tmp当中最多有多少个num2（tmp除以num2的商）
            int count = 0;
            while (Cmp(tmp, num2) != -1) // tmp大于等于num2，则说明商可以更大
            {
                tmp = SubString(tmp, num2);
                count++;
            }

            // b、将商值尾插到ret当中
            ret += (count + '0');

            // c、如果num1的所有位都被取完了，则小数点之前的结果计算完毕
            if (len >= num1.size())
                break;

            // d、如果num1当中还有未取的位，则继续从num1中一位尾插到tmp当中
            tmp += num1[len];
            len++; // 下一次待取位下标
        }
        ret += "."; // 小数点之前的结果计算完毕，加上小数点

        // 如果ret最高位为0，且该位后面不是小数点，则需要将这个0过滤掉
        if (ret.size() != 2 && ret[0] == '0')
            ret = ret.substr(1);
    }

    // 2、再计算小数点后面的数（保留n位小数）
    for (int i = 0; i < n; i++)
    {
        if (tmp == "0") // tmp为0（余数为0）
        {
            ret += "0"; // 则直接在ret后面补0即可
        }
        else // tmp不为0（余数不为0）
        {
            tmp += "0"; // 在余数后面补0，继续进行计算

            // a、计算tmp当中最多有多少个num2（tmp除以num2的商）
            int count = 0;
            while (Cmp(tmp, num2) != -1)
            {
                tmp = SubString(tmp, num2);
                count++;
            }

            // b、将商值尾插到ret当中
            ret += (count + '0');
        }
    }
    return ret; // 返回两个字符串相除后的结果
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    return 0;
}