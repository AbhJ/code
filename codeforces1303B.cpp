#include <bits/stdc++.h>
#include <numeric> 
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
using namespace std;//coded by abhijay mitra
void solve(){
   ll n,g,b;cin>>n>>g>>b;
   ll ans=(n+1)/2;ans/=g;ans*=b+g;
   if(((n+1)/2)%g==0)ans-=b;else ans+=((n+1)/2)%g;
   cout<<max(n,ans);
}
int main()
{   
    ibs;cti;
    int t;cin>>t;
    while(t--)
    solve(),cout<<"\n";
    return 0;
}