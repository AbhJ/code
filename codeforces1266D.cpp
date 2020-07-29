#include <bits/stdc++.h>
#define ll long long
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define pb push_back
using namespace std;//coded by abhijay mitra
#define watch(x) cout << (#x) << " is " << (x) << endl
int main()
{
    ibs;cti;
    int n,m;cin>>n>>m;std::vector<std::vector<ll>> v;ll a,b,c;std::vector<ll> v1(n+1,0);
    for (int i = 0; i < m; ++i)
    {
        cin>>a>>b>>c;v1[a]-=c;v1[b]+=c;
    }std::vector<ll>::iterator  j;j = v1.begin()+1;
    for (std::vector<ll>::iterator i = v1.begin()+1; i != v1.end(); ++i){
        while(*i>0){
        for (; j != v1.end() and *j>=0; ++j){}
            ll x=min(*i,-*j);
            *j+=x;*i-=x;
            std::vector<ll> y;
            y.pb(j-v1.begin());y.pb(i-v1.begin());y.pb(x);
            v.pb(y);
        }
    }cout<<v.size()<<"\n";
    for(auto i:v)cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<"\n";return 0;   
}