#include <bits/stdc++.h>
using namespace std;
int T, n;
const int K = 40;
struct node
{
    node *fail;
    node *ch[K];
    int count;
    node()
    {
        fail = NULL;
        memset(ch, 0, sizeof ch);
        count = 0;
    }
};
node *root;
void insert(string str)
{
    node *t = root;
    for (int i = 0; i < str.length(); i++)
    {
        int x = str[i] - 'a';
        if (t->ch[x] == NULL)
            t->ch[x] = new node();
        t = t->ch[x];
    }
    t->count++;
}
void build_ac()
{
    node *p = root;
    root->fail = root;
    queue<node *> q;
    for (int i = 0; i < K; i++)
    {
        if (p->ch[i])
        {
            p->ch[i]->fail = root;
            q.push(p->ch[i]);
        }
        else
            p->ch[i] = root;
    }
    while (!q.empty())
    {
        p = q.front();
        q.pop();
        for (int i = 0; i < K; i++)
            if (p->ch[i])
            {
                p->ch[i]->fail = p->fail->ch[i];
                q.push(p->ch[i]);
            }
            else
                p->ch[i] = p->fail->ch[i];
    }
}
int query(string str)
{
    int ans = 0;
    queue<pair<node *, int>> status;
    node *p = root;
    for (int i = 0; i < str.length(); i++)
    {
        int id = str[i] - 'a';
        if (p->ch[id])
        {
            p = p->ch[id];
            node *tmp = p;
            while (tmp->count || tmp->fail != root)
            {
                if (tmp->count)
                {
                    ans += tmp->count;
                    status.push(make_pair(tmp, tmp->count));
                    tmp->count = 0;
                }
                tmp = tmp->fail;
            }
        }
    }
    while (status.size())
    {
        pair<node *, int> tmp = status.front();
        status.pop();
        tmp.first->count = tmp.second;
    }
    return ans;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> T;
    string tmp, qu;
    while (T--)
    {
        cin >> n;
        root = new node();
        for (int i = 1; i <= n; i++)
        {
            cin >> tmp;
            insert(tmp);
        }
        build_ac();
        cin >> qu;
        cout << query(qu) << '\n';
    }
    return 0;
}