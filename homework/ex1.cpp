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
            value = (op == 1 && value > a[j]) || (op == 0 && value < a[j]) ? it = j, a[j] : value;
        swap(a[i], a[it]);
        ans[i] = value;
    }
    cout << "selectsort\n";
    print(ans);
}

void insertsort(vector<int> a, int op) // 0 = less 1 = greater
{
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = i; j; j--)
            if (op == 1)
            {
                if (a[j - 1] > a[j])
                    swap(a[j - 1], a[j]);
                else
                    break;
            }
            else
            {
                if (a[j - 1] < a[j])
                    swap(a[j - 1], a[j]);
                else
                    break;
            }
    }
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
            if ((op == 1 && ans[j] > ans[j + 1]) || (op == 0 && ans[j] < ans[j + 1]))
                swap(ans[j], ans[j + 1]);
    cout << "Maopaosort:\n";
    print(ans);
}

ll C(int n, int m)
{
    ll res = 1;
    m = min(m, n - m);
    for (int i = 0; i < m; ++i)
    {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

ll f(string s)
{
    ll res = 1;
    for (int i = 1; i < s.length(); i++)
        res += C(26, i);

    for (int i = 1; i <= s.length(); i++)
        for (int j = i == 1 ? 'a' : s[i - 2] + 1; j <= s[i - 1] - 1; j++)
            res += C('z' - j, s.length() - i);

    return res;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

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
