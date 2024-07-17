#include <bits/stdc++.h>
using namespace std;

int main()
{
    ll ans = 0;
    string s;
    cin>>s;
    for (int i = 1; i < s.size();i++){
        if(s[i-1]=='A'&&s[i]=='B')
            ans++;
    }
        return 0;
}