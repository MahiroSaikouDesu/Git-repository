#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
int read()
{
    int sum = 0, f = 1;
    char a = getchar();
    while (a < '0' || a > '9')
    {
        if (a == '-')
            f *= -1;
        a = getchar();
    }
    while (a >= '0' && a <= '9')
    {
        sum = (sum << 3) + (sum << 1) + a - '0';
        a = getchar();
    }
    return f * sum;
}
const int N = 5e4 + 10;
int n, m;
ll x;
ll a[N], b[N];
stuct node
{
    int i;
};
bool cmp(const int x, const int y)
{
    if (a[x] != a[y])
        return a[x] > a[y];
    else
        return b[x] > b[y];
}

int main()
{
    priority_queue<int, vector<int>, cmp> q;
    priority_queue<int> q2;
    cin >> n >> m >> x;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i];
        q.push(i);
    }
    while(!q.empty()){
        int now=q.top();
        q.pop();
        if(a[now]>x){
            q.push(now);
            break;
        }else{
            x -= a[now];
            q2.push(now);
        }
    }
    while(!q2.empty()){
        cout<<q2.top()<<' ';
        q2.pop();
    }
    return 0;
}