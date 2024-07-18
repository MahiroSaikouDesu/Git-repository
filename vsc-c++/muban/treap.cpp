struct node
{
    int lc, rc;
    int val, pri;
    int num, size;
} tr[N];

int cnt, root;
int New(int val)
{
    tr[++cnt].val = val;
    tr[cnt].pri = rand();
    tr[cnt].num = tr[cnt].size = 1;
    tr[cnt].lc = tr[cnt].rc = 0;
    return cnt;
}

void update(int p)
{
    tr[p].size = tr[tr[p].lc].size + tr[tr[p].rc].size + tr[p].num;
}

void zig(int &p) // 右旋
{
    int q = tr[p].lc;
    tr[p].lc = tr[q].rc;
    tr[q].rc = p;
    tr[q].size = tr[p].size;
    update(p);
    p = q;
}

void zag(int &p) // 左旋
{
    int q = tr[p].rc;
    tr[p].rc = tr[q].lc;
    tr[q].lc = p;
    tr[q].size = tr[p].size;
    update(p);
    p = q;
}

void Insert(int &p, int val)
{
    if (!p)
    {
        p = New(val);
        return;
    }
    tr[p].size++;
    if (val == tr[p].val)
        tr[p].num++;
    else if (val < tr[p].val)
    {
        Insert(tr[p].lc, val);
        if (tr[p].pri < tr[tr[p].lc].pri)
            zig(p);
    }
    else
    {
        Insert(tr[p].rc, val);
        if (tr[p].pri < tr[tr[p].rc].pri)
            zag(p);
    }
}

void Delete(int &p, int val)
{
    if (!p)
        return;
    tr[p].size--;
    if (val == tr[p].val)
    {
        if (tr[p].num > 1)
            tr[p].num--;

        else if (!tr[p].lc || !tr[p].rc)
            p = tr[p].lc + tr[p].rc;

        else if (tr[tr[p].lc].pri > tr[tr[p].rc].pri)
        {
            zig(p);
            Delete(tr[p].rc, val);
        }
        else
        {
            zag(p);
            Delete(tr[p].lc, val);
        }
    }

    else if (val < tr[p].val)
        Delete(tr[p].lc, val);

    else
        Delete(tr[p].rc, val);
}

int getpre(int val)
{
    int p = root, res = 0;
    while (p)
    {
        if (tr[p].val < val)
        {
            res = tr[p].val;
            p = tr[p].rc;
        }
        else
            p = tr[p].lc;
    }
    return res;
}

int getnext(int val)
{
    int p = root, res = 0;
    while (p)
    {
        if (tr[p].val <= val)
            p = tr[p].rc;
        else
        {
            res = tr[p].val;
            p = tr[p].lc;
        }
    }
    return res;
}

int getrank(int p, int val)
{
    if (!p)
        return 0;
    if (tr[p].val == val)
        return tr[tr[p].lc].size + 1;
    else if (tr[p].val < val)
        return getrank(tr[p].rc, val) + tr[p].num + tr[tr[p].lc].size;
    else
        return getrank(tr[p].lc, val);
}

int getval(int p, int rank)
{
    if (!p)
        return 0;
    if (tr[tr[p].lc].size >= rank)
        return getval(tr[p].lc, rank);
    if (tr[tr[p].lc].size + tr[p].num >= rank)
        return tr[p].val;
    return getval(tr[p].rc, rank - tr[tr[p].lc].size - tr[p].num);
}

void getall(int p)
{
    queue<int> q;
    q.push(p);
    while (!q.empty())
    {
        int f = q.front();
        cout << "Index :" << f << '\n';
        cout << "LC: " << tr[f].lc << " RC: " << tr[f].rc << '\n';
        cout << "Val: " << tr[f].val << " Num: " << tr[f].num << " Size: " << tr[f].size << '\n';

        if (tr[f].lc)
            q.push(tr[f].lc);

        if (tr[f].rc)
            q.push(tr[f].rc);
        q.pop();
    }
}