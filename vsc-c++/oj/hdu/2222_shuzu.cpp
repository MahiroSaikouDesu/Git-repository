#include <bits/stdc++.h>
using namespace std;
const int N = 1000006, K = 26;

int trie[N][K], cnt[N], fail[N], pos;
void insert(char *p)
{ // 构建字典树
    int u = 0;
    int ls = strlen(p);
    for (int i = 0; i < ls; i++)
    {
        int v = p[i] - 'a';
        if (trie[u][v] == 0)
            trie[u][v] = ++pos;
        u = trie[u][v];
    }
    cnt[u]++; // 当前节点单词数+1
}
void build_ac()
{ // 求fail
    queue<int> q;
    for (int i = 0; i < K; i++)
    { // 入队root子节点(第二层)
        if (trie[0][i])
        {
            fail[trie[0][i]] = 0;
            q.push(trie[0][i]);
        }
    }
    while (!q.empty())
    {
        int cur = q.front(); // 当前父节点
        q.pop();
        for (int i = 0; i < K; i++)
        { // 26个字母
            if (trie[cur][i])
            { // 存在子节点，将其fail指向对应匹配节点(父节点fail所指节点的对应子节点)
                fail[trie[cur][i]] = trie[fail[cur]][i];
                q.push(trie[cur][i]);
            }
            else // 若不存在相关子节点，字典树中赋值为fail所指节点
                trie[cur][i] = trie[fail[cur]][i];
        }
    }
}
int query(char *s)
{ // 查询s中出现几个p
    int cur = 0, ans = 0, ls = strlen(s);
    for (int i = 0; i < ls; i++)
    {
        cur = trie[cur][s[i] - 'a'];
        for (int j = cur; j && cnt[j]; j = fail[j])
        {                  // 一直向下寻找,直到匹配失败
            ans += cnt[j]; // 更新答案
            cnt[j] = 0;    // 防止重复计算
        }
    }
    return ans;
}

signed main()
{
    int t, n;
    scanf("%d", &t);
    char s[1000100], p[60];
    while (t--)
    {
        scanf("%d", &n);
        memset(trie, 0, sizeof trie);
        memset(cnt, 0, sizeof cnt);
        fail[0] = pos = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%s", p);
            insert(p);
        }
        build_ac();
        scanf("%s", s);
        printf("%d", query(s));
    }
    return 0;
}