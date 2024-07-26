int trie[N][N], end[N], tot = 1;
void Insert(string s)
{
    int p = 1;
    for (auto i : s)
    {
        int ch = i - 'a';
        if(!trie[p][ch]])
            trie[p][ch] = ++tot;
        p = trie[p][ch];
    }
    end[p] = tot;
}
bool search(string s)
{
    int p = 1;
    for (auto i : s)
    {
        int ch = i - 'a';
        p = trie[p][ch];
        if (!p)
            return false;
    }
    return end[p];
}