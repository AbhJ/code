#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
using namespace std;//coded by abhijay mitra
void solve(){
    ll n,d;cin>>n>>d;ll a,b,x,y;cin>>a>>b;
    std::vector<ll> ans;std::vector<pair<ll,ll>> v(n);
    for (int i = 0; i < n; ++i)cin>>x>>y,v[i]={x*a+y*b,i+1};
    sort(v.begin(), v.end());
    for (int i = 0; i < n; ++i)
        if(d>=v[i].first)
            d-=v[i].first,ans.pb(v[i].second);
    cout<<ans.size()<<"\n";
    for (int i = 0; i < ans.size(); ++i)
        cout<<ans[i]<<" ";
}
int main()
{   
    ibs;cti;
    solve();cout<<"\n";
    return 0;
}