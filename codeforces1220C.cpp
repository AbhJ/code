#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
using namespace std;//coded by abhijay mitra
void solve(){
    string s;cin>>s;char c=s[0];
    cout<<"Mike\n";
    for (int i = 1; i < s.length(); ++i)
    {
        if(c<s[i])cout<<"Ann\n";//then ann choses i as l else she has no choice
        else c=s[i],cout<<"Mike\n";
    }
}
int main()
{   
    ibs;cti;
    solve();
    return 0;
}