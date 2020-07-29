#include <bits/stdc++.h>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
using namespace std;//coded by abhijay mitra
ll dist(pair<ll,ll>a,pair<ll,ll>b){
    return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);
}
void solve(){
    ll n,x1,y1,x2,y2,r1=0,r2=0;pair<ll,ll>f1,f2;
    cin>>n>>x1>>y1>>x2>>y2;f1={x1,y1};f2={x2,y2};
    std::vector<pair<ll,ll>> v(n);
    for (ll i = 0; i < n; ++i)
        cin>>v[i].first>>v[i].second;
    ll ans=LLONG_MAX,j;
    for (int i = 0; i < n; ++i)
    {
        r1=dist(v[i],f1);r2=0;
        for(j=0;j<n;j++){
            if(dist(v[j],f1)>r1)
            r2=max(dist(v[j],f2),r2);
        }
        ans=min(r1+r2,ans);
    }
    r1=0;r2=0;
    for(j=0;j<n;j++){
            r2=max(dist(v[j],f2),r2);
        }
    ans=min(r1+r2,ans);
    cout<<ans<<"\n";
}
int main()
{   
    ibs;cti;
    solve();
    return 0;
}