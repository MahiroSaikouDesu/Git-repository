#include <bits/stdc++.h>
using namespace std;
const int K = 94;
struct node
{
    node *fail;
    node *ch[K];
    int id;
    node()
    {
        fail = NULL;
        memset(ch, 0, sizeof ch);
    }
};
node *root;
string str;
vector<int> ans;
queue<node *> q;
void insert(int id)
{
    node *t = root;
    for (int i = 0; i < str.length(); i++)
    {
        int x = str[i] - 33;
        if (t->ch[x] == NULL)
            t->ch[x] = new node();
        t = t->ch[x];
    }
    t->id = id;
}
void build_ac()
{
    node *p = root;
    root->fail = root;
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
void query()
{
    ans.clear();
    node *p = root;
    for (int i = 0; i < str.length(); i++)
    {
        int id = str[i] - 33;
        if (p->ch[id])
        {
            p = p->ch[id];
            node *tmp = p;
            while (tmp->id || tmp->fail != root)
            {
                if (tmp->id)
                {
                    ans.push_back(tmp->id);
                    if (ans.size() >= 3)
                        return;
                }
                tmp = tmp->fail;
            }
        }
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    root = new node();
    int n, m, cnt = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> str;
        insert(i);
    }
    build_ac();
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        ans.clear();
        cin >> str;
        query();
        if (!ans.empty())
        {
            cnt++;
            cout << "web " << i << ": ";
            sort(ans.begin(), ans.end());
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