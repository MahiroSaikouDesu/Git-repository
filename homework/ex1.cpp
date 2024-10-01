#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> P;
const int inf = 0x3f3f3f3f << 1;
vector<int> v;

void print(vector<int> a)
{
    for (auto i : a)
        cout << i << ' ';
    cout << "\n\n";
}

void selectsort(vector<int> a, int op) // 0 = less 1 = greater
{
    vector<int> ans(a.begin(), a.end());
    for (int i = 0; i < a.size(); i++)
    {
        int value = a[i], it = i;
        for (int j = i + 1; j < a.size(); j++)
            value = (op == 1 ? value > a[j] : value < a[j]) ? it = j, a[j] : value;
        swap(a[i], a[it]);
        ans[i] = value;
    }
    cout << "selectsort\n";
    print(ans);
}

void insertsort(vector<int> a, int op) // 0 = less 1 = greater
{
    for (int i = 0; i < a.size(); i++)
        for (int j = i, flag = 1; j && flag; j--)
            flag = (op ? a[j - 1] > a[j] : a[j - 1] < a[j]) ? swap(a[j - 1], a[j]), 1 : 0;
    cout << "insertsort\n";
    print(a);
}

void heapsort(vector<int> a, int op) // 0 = less 1 = greater
{
    vector<int> ans(a.begin(), a.end());
    if (op == 0)
        make_heap(ans.begin(), ans.end(), greater<int>());
    else
        make_heap(ans.begin(), ans.end(), less<int>());
    cout << "Heap:\n";
    print(ans);
    cout << "Heap Sort:\n";
    if (op == 0)
        sort_heap(ans.begin(), ans.end(), greater<int>());
    else
        sort_heap(ans.begin(), ans.end(), less<int>());
    print(ans);
}

void maopaosort(vector<int> a, int op) // 0 = less 1 = greater
{
    vector<int> ans(a.begin(), a.end());
    for (int i = 0; i < a.size() - 1; i++)
        for (int j = 0; j < a.size() - 1 - i; j++)
            if (op ? ans[j] > ans[j + 1] : ans[j] < ans[j + 1])
                swap(ans[j], ans[j + 1]);
    cout << "Maopaosort:\n";
    print(ans);
}

// 快速幂运算函数，计算a的b次方对p取模的结果
ll qmi(ll a, ll b, ll p)
{
    ll res = 1;
    while (b)
    {
        if (b & 1 == 1)
            res = res * a % p; // 如果b是奇数，则累乘到结果中
        a = a * a % p;         // a自身平方
        b >>= 1;               // b右移一位，相当于除以2
    }
    return res;
}
// 计算组合数C(a, b)对p取模的结果
ll C(ll a, ll b, ll p)
{
    ll res = 1;
    for (int i = 1, j = a; i <= b; ++i, --j)
    {
        res = res * j % p;                // 计算阶乘部分
        res = res * qmi(i, p - 2, p) % p; // 计算阶乘的逆元部分
    }

    return res;
}
// Lucas定理，用于计算大组合数取模的问题
ll lucas(ll a, ll b, ll p)
{
    if (a < p && b < p)
        return C(a, b, p); // 如果a和b都小于p，直接计算C(a, b)
    else
        return C(a % p, b % p, p) * lucas(a / p, b / p, p) % p; // 否则，递归计算
}

ll f(string s)
{
    ll res = 1;
    for (int i = 1; i < s.length(); i++)
        res += lucas(26, i, 1e9 + 7);

    for (int i = 1; i <= s.length(); i++)
        for (int j = i == 1 ? 'a' : s[i - 2] + 1; j <= s[i - 1] - 1; j++)
            res += lucas('z' - j, s.length() - i, 1e9 + 7);

    return res;
}

signed main()
{
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    // Problem 1
    int n, tmp, op = 0; // n 为数组的个数 || op 为排序方式
    cout << "1 is greater and 0 is less\n";
    cout << "Type the amount of number and sort's operator : \n";
    cin >> n >> op;
    v.resize(n);
    for (int i = 0; i < n; i++)
        cin >> v[i]; // 输入数组的数字

    maopaosort(v, op); // 冒泡排序
    heapsort(v, op);   // 堆排序
    insertsort(v, op); // 插入排序
    selectsort(v, op); // 选择排序
    cout << '\n';

    // Problem 2
    cout << "Type the total of the page: ";
    cin >> n; // n 为页码总数
    vector<int> mp(20);
    for (int i = 1; i <= n; i++)
    {
        tmp = i;
        while (tmp)
        {
            mp[tmp % 10]++;
            tmp /= 10;
        }
    }
    for (int i = 0; i <= 9; i++)
        cout << "The number \'" << i << "\' has been used " << mp[i] << " times.\n";
    cout << '\n';

    // Problem 3
    cout << "Type the string need decode:\n";
    string s;
    cin >> s;
    transform(s.begin(), s.end(), s.begin(), ::tolower); // 转小写
    cout << f(s) << '\n';

    return 0;
}
