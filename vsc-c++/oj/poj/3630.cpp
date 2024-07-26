#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;
const int N = 1e5 + 10;
int trie[N][10], tot, flag;
bool fi[N];
char tmp[20];
void Insert(string s)
{
    int p = 1, len = s.length();
    for (int i = 0; i < len; i++)
    {
        if (fi[p])
        {
            flag = 0;
            return;
        }
        int ch = s[i] - '0';
        if (!trie[p][ch])
            trie[p][ch] = ++tot;
        else if (i == len - 1)
        {
            flag = 0;
            return;
        }
        p = trie[p][ch];
    }
    fi[p] = true;
}

signed main()
{
    int T, n;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        flag = 1, tot = 1;
        memset(trie, 0, sizeof trie);
        memset(fi, false, sizeof fi);
        while (n--)
        {
            scanf("%s", tmp);
            if (flag)
                Insert(tmp);
        }
        if (flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}