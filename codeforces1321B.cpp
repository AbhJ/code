#include <bits/stdc++.h>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
using namespace std;//coded by abhijay mitra
void solve(){
    int n;cin>>n;std::vector<ll> v(n);ll ans=0;std::map<ll, ll> map;
    for (int i = 0; i < n; ++i){
        cin>>v[i];if(map.find(v[i]-i)==map.end())map.insert({v[i]-i,v[i]}),ans=max(ans,v[i]);
        else ans=max(ans,map[v[i]-i]+=v[i]);
    }
    cout<<ans;
}
int main()
{   
    ibs;cti;
    solve();cout<<"\n";
    return 0;
}