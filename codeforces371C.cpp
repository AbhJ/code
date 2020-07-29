#include <bits/stdc++.h>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
using namespace std;//coded by abhijay mitra
void solve(){
    string s1;cin>>s1;ll B=0,S=0,C=0;
    int b,s,c;cin>>b>>s>>c;
    int pb,ps,pc;cin>>pb>>ps>>pc;
    ll p;cin>>p;
    for (int i = 0; i < s1.length(); ++i)
    {
        if(s1[i]=='B')B++;
        if(s1[i]=='C')C++;
        if(s1[i]=='S')S++;
    }
    ll l=0,r=1e14,x=0;
    while(l<=r){
        x=(l+r)/2;ll f=max(0ll,B*x-b)*pb+max(0ll,S*x-s)*ps+
            max(0ll,C*x-c)*pc;
        if(f<=p)l=x+1;
        else r=x-1;
    }
    cout<<l-1;
}
int main()
{   
    ibs;cti;
    solve();cout<<"\n";
    return 0;
}