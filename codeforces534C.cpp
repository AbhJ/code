#include <bits/stdc++.h>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
using namespace std;//coded by abhijay mitra
void solve(){
    ll n,A,sum=0;cin>>n>>A;std::vector<ll> d(n);
    for (int i = 0; i < n; ++i)cin>>d[i],sum+=d[i];
    for (int i = 0; i < n; ++i)
    {
        ll l=max(1LL,A+d[i]-sum);
        ll r=min(d[i],A+1-n);
        cout<<d[i]-(r-l+1)<<" ";
    }
}
int main()
{   
    ibs;cti;
    solve();cout<<"\n";
    return 0;
}