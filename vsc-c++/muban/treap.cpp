struct node
{
    int lc, rc;
    int val, pri;
    int num, size;
} tr[N];

int cnt;
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