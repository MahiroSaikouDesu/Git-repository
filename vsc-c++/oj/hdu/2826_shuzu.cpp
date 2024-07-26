#include <bits/stdc++.h>
using namespace std;
const int N = 100005, K = 95;

int trie[N][K], cnt[N], fail[N], pos, vid[N];
char s[N], p[250];
void insert(char *p, int id)
{ // 构建字典树
    int u = 0;
    int ls = strlen(p);
    for (int i = 0; i < ls; i++)
    {
        int v = p[i] - 33;
        if (trie[u][v] == 0)
            trie[u][v] = ++pos;
        u = trie[u][v];
    }
    cnt[u]++; // 当前节点单词数+1
    vid[u] = id;
}
queue<int> q;
void build_ac()
{ // 求fail
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
set<int> ans;
void query()
{ // 查询s中出现几个p
    int cur = 0, ls = strlen(s);
    for (int i = 0; i < ls; i++)
    {
        cur = trie[cur][s[i] - 33];
        for (int j = cur; j && cnt[j]; j = fail[j])
        {                       // 一直向下寻找,直到匹配失败
            ans.insert(vid[j]); // 更新答案
            // cnt[j] = 0;          // 防止重复计算
        }
    }
}
void init()
{
    memset(trie, 0, sizeof trie);
    memset(cnt, 0, sizeof cnt);
    memset(vid, 0, sizeof vid);
    fail[0] = pos = 0;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, cnt = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", p);
        insert(p, i);
    }
    build_ac();
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", s);
        ans.clear();
        query();
        if (!ans.empty())
        {
            cnt++;
            cout << "web " << i << ": ";
            for (auto j : ans)
            {
                cout << j << " ";
            }
            cout << '\n';
        }
    }
    cout << "total: " << cnt;
    return 0;
}