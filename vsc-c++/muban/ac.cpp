node *root;
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
                    tmp->count = 0;
                }
                tmp = tmp->fail;
            }
        }
    }
    return ans;
}