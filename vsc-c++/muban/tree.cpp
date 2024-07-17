int pre[N], in[N], post[N];

struct node
{
    int val;
    node *l, *r;
    node(int value = 0, node *l = nullptr, node *r = nullptr) : val(val), l(l), r(l) {};
};

void buildtree(int l, int r, int &t, node *&root)
{
    int flag = -1;
    for (int i = l; i <= r; i++)
        if (in[i] == pre[t])
        {
            flag = i;
            break;
        }
    if (flag == -1)
        return;
    root = new node(in[flag]);
    t++;
    if (flag > l)
        buildtree(l, flag - 1, t, root->l);
    if (flag < r)
        buildtree(flag + 1, r, t, root->r);
}