#include <bits/stdc++.h>
#include <numeric> 
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
using namespace std;//coded by abhijay mitra
void solve(){
    ll n,k;cin>>n>>k;std::vector<ll> v(n);bool check=1;ll ma=0,store=-1;
    for (ll i = 0; i < n; ++i)cin>>v[i];
    for(ll z=0;z<70*n;z++){
        ma=0;
        for (ll i = 0; i < n; ++i)
        {
            ll j=0;
            for(j=0;(ll)pow(k,j)<=v[i];j++);
            ma=max(ma,j-1);/*cout<<ma;*/
        }
        if(ma==store)break;
        ll count=0;
        for (ll i = 0; i < n; ++i)
        {
            if(((ll)pow(k,ma)<=v[i]))
                count++,v[i]-=(ll)pow(k,ma);
        }
        if(count>1){
            cout<<"NO\n";return;}
        if(!ma)break;
        store=ma;
    }
    for (ll i = 0; i < n; ++i)
    {
        if(v[i]){
            cout<<"NO\n";return;
        }
    }
    cout<<"YES\n";
}
int main()
{   
    ibs;cti;
    int t;cin>>t;
    while(t--)
    solve(),cout<<"\n";
    return 0;
}