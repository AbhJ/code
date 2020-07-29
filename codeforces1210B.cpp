#include <bits/stdc++.h>
#include <numeric>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
using namespace std;//coded by abhijay mitra
#define F first
#define S second
void solve(){
  int n;cin>>n;
  std::map<ll, ll> m;
  ll a[n],b[n];
  for (int i = 0; i < n; ++i)
  {
    ll x;cin>>x;m[x]++;
    a[i]=x;
  }
  for (int i = 0; i < n; ++i)
  {
    cin>>b[i];
  }
  set<ll>s;
  for (auto i:m)
  {
    if(i.S<2)continue;
    for (int I = 0; I < n; ++I)
    {
      if((a[I] | i.F)==i.F)s.insert(I);
    }
  }
  ll ans=0;
  for(auto i:s)ans+=b[i];
  cout<<ans;
}
int main()
{   
    ibs;cti;
    solve();
    cout<<"\n";
    return 0;
}