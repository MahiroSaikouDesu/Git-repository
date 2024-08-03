#include <bits/stdc++.h>
using namespace std;
const int N = 2e5, K = 140;
#define ll long long
int n;
ll l1;
int trie[N][K], fail[N], pos;
char s[N], p[110];
ll cnt[N];
void insert(char *p, ll val)
{ // 构建字典树
    int u = 0, ls = strlen(p);
    for (int i = 0; i < ls; i++)
    {
        int v = (int)p[i];
        if (trie[u][v] == 0)
            trie[u][v] = ++pos;
        u = trie[u][v];
    }
    cnt[u] += val; // 当前节点单词数+1
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
ll query(char *s)
{ // 查询s中出现几个p
    int cur = 0, ls = strlen(s);
    ll ans = 0;
    for (int i = 0; i < ls; i++)
    {
        cur = trie[cur][s[i]];
        for (int j = cur; j; j = fail[j])
        {                  // 一直向下寻找,直到匹配失败
            ans += cnt[j]; // 更新答案
                           // cnt[j] = 0;    // 防止重复计算
        }
    }
    return ans;
}
void init()
{
    memset(trie, 0, sizeof trie);
    memset(cnt, 0, sizeof cnt);
    fail[0] = pos = 0;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    init();
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> p >> l1;
        insert(p, l1);
    }
    cin >> s;
    build_ac();
    cout << query(s);
    return 0;
}