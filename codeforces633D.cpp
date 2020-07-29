#include <bits/stdc++.h>
// #include <numeric>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=5e3+10;
const ll M = 1e9+7; // Mulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
ll ans;std::map<ll, ll> Ma;
void f(ll a,ll b, ll l=2){
  ans=max(l,ans);
  if(Ma[a+b]==0)return;
  ll ma=2;
  Ma[a+b]--;
  f(b,a+b,l+1);
  Ma[a+b]++;
}
void solve(){
  ll n;cin>>n;vector<ll> v(n);
  ll m=0,y=0;
  for (ll i = 0; i < n; ++i)
  {
    cin>>v[i];
    if(v[i]==0)m++;
    Ma[v[i]]++;
  }
  ans=2;
  sort(v.begin(), v.end());
  for (ll i = 0; i < n; ++i)
  {
    for(ll j=0;j<n;j++){
      if((v[i]==0) and (v[j]==0))continue;
      if((i==j) and (Ma[v[i]]<=1))continue;
      Ma[v[i]]--;Ma[v[j]]--;
      f(v[i],v[j]);
      Ma[v[i]]++,Ma[v[j]]++;
    }
  }
  cout<<max(ans,m);
}
int main()
{
    // ibs;cti;
    // int t;cin>>t;
    // while(t--){
      solve();
      // cout<<len;
      cout<<"\n";
    // }
    return 0;
}