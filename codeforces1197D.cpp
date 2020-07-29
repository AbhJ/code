#include <bits/stdc++.h>
// #include <numeric>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=3e5+10;
const ll M = 1e9+7; // Mulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
ll v[N];
void solve(){
  int m,n,k;cin>>n>>m>>k;
  for(ll i=0;i<n;i++)cin>>v[i];
  ll ans=0,sum=0,mi=0;
  for (ll i = 0; i < m; ++i)
  {
    sum=mi=0;
    for(ll j=i;j<n;j++){
      if(j%m==i)mi=min(mi,sum),sum-=k;//sum decreases once in every interval of length m
      sum+=v[j];
      ans=max(ans,sum-mi);
    }
  }
  cout<<ans;
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