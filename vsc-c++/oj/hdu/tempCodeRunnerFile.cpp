fa(x) = z;
    tr[y].s[k] = tr[x].s[k ^ 1];
    fa(tr[x].s[k ^ 1]) = y;
    tr[x].s[k ^ 1] = y;
    fa(y) = x;