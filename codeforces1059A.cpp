#include <bits/stdc++.h>
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
using namespace std;//coded by abhijay mitra
void solve(){
    int n,L,a,l,t;cin>>n>>L>>a;int x,ans=0,last=0;
    while(n--){
        cin>>x>>t;
        ans+=(x-last)/a;
        last=x+t;
    }
    ans+=(L-last)/a;
    cout<<ans;
}
int main()
{   
    ibs;cti;
    solve();cout<<"\n";
    return 0;
}