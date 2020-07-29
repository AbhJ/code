#include <bits/stdc++.h>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
using namespace std;//coded by abhijay mitra
const int M=1<<30;
void solve(){
    ll a,b,c,d[1000001]={0};cin>>a>>b>>c;ll ans=0;
    for(int i=1;i<=1000000;i++)
        for(int j=i;j<=1000000;j+=i)
            d[j]++;
    for (ll i = 1; i <= a; ++i)
    {
        for(ll j=1;j<=b;j++){
            for(ll k=1;k<=c;k++)
                ans+=d[i*j*k]%M;
        }
    }
    cout<<ans;
}
int main()
{   
    ibs;cti;
    solve();cout<<"\n";
    return 0;
}