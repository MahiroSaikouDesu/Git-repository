#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int dpscore[N], dpnxtchar[N], dpnxtidx[5];
vector<string> s(N);

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t, n, m;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        memset(dpnxtchar, 0, sizeof dpnxtchar);
        memset(dpscore, 0, sizeof dpscore);
        memset(dpnxtidx, 0, sizeof dpnxtidx);
        for (int i = 1; i <= n; i++)
            cin >> s[i];

        for (int i = 1, nxtchar = -1, scoren = 0, scorec = 0, nownxt = 0, sn, sc, cnt = 0; i <= n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                switch (s[i][j])
                {
                case 'n':
                    nxtchar = nxtchar == -1 ? 0, nownxt = 0 : nxtchar;
                    if (nownxt == 0)
                        cnt++, nownxt++;
                    else
                        scorec++;
                    break;

                case 'a':
                    nxtchar = nxtchar == -1 ? 1, nownxt = 1 : nxtchar;
                    if (nownxt == 1)
                        cnt++, nownxt++;
                    else
                        scorec++;
                    break;

                case 'r':
                    nxtchar = nxtchar == -1 ? 2, nownxt = 2 : nxtchar;
                    if (nownxt == 2)
                        cnt++, nownxt++;
                    else
                        scorec++;
                    break;

                case 'e':
                    nxtchar = nxtchar == -1 ? 3, nownxt = 3 : nxtchar;
                    if (nownxt == 0)
                        cnt++, nownxt++;
                    else
                        scorec++;
                    break;

                case 'k':
                    nxtchar = nxtchar == -1 ? 4, nownxt = 4 : nxtchar;
                    if (nownxt == 4)
                        scoren += cnt + 1, cnt = nownxt = 0;
                    else
                        scorec++;
                    break;

                default:
                    break;
                }
            }
            if (nxtchar == -1)
                continue;
            for (int j = 0, to; j < 5; j++)
            {
                to = dpnxtidx[j], sn = scoren, sc = scorec;
                if (nxtchar <= dpnxtchar[to])
                {
                    scoren -= dpnxtchar[to] - nxtchar;
                    scorec += dpnxtchar[to] - nxtchar;
                    if (scoren - scorec + dpscore[to] > dpscore[i])
                    {
                        dpscore[i] = scoren - scorec + dpscore[to];
                        dpnxtchar[i] = nownxt;
                        dpnxtidx[j] = i;
                    }
                }
                else
                {
                    if(scoren<)
                }
            }
        }
    }
    return 0;
}