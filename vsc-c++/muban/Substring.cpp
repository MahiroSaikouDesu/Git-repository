int Cmp(string &num1, string &num2)
{
    if ((num1.size() > num2.size()) || (num1.size() == num2.size() && num1 > num2))
        return 1; // num1 > num2
    else if ((num1.size() < num2.size()) || (num1 < num2))
        return -1; // num1 < num2;
    else
        return 0; // num1 == num2
}
string Substring(string num1, string num2)
{
    if (Cmp(num1, num2) == -1)
        return "-" + Substring(num2, num1);
    int end1 = num1.size() - 1, end2 = num2.size() - 1, a, b, differ;
    string ret;     // 存储两个字符串相减后的结果
    int borrow = 0; // 借位（初始时借位设置为0）
    while (end1 >= 0)
    {
        // 1、取出num1中本次待相减的数字
        a = num1[end1--] - '0';
        // 2、取出num2中本次待相减的数字
        b = 0;
        if (end2 >= 0)
            b = num2[end2--] - '0';
        // 3、将这两个数字相减（注意减去借位）
        differ = a - b - borrow;
        // 4、判断是否需要进位
        if (differ < 0) // 需要借位，将borrow设置为1
            differ += 10, borrow = 1;
        else
            borrow = 0; // 不需要借位，将borrow设置为0
        ret += (differ + '0');
    }
    reverse(ret.begin(), ret.end());         // 将ret字符串进行反转
    size_t pos = ret.find_first_not_of('0'); // 过滤掉ret字符串前面的'0'
    if (pos == string::npos)                 // ret中全部为'0'，则两个数相减后的结果为0
    {
        return "0";
    }
    return ret.substr(pos); // 返回两个字符串相减后的结果
}