#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s, t;
    cin >> s >> t;
    int cnt = 1, it = 0;
    for(auto &a:t){
        if(it>=s.size())
            break;
        if(a==s[it]){
            cout << cnt << " ";
            it++;
        }
        cnt++;
    }
    return 0;
}