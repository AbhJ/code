#include <bits/stdc++.h>
// #include <xeric>
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
ll powM(ll b, int p) {
  ll r=1;
  for(; p; b=b*b%M, p/=2)
    if(p&1)
      r=r*b%M;
  return r;
}
ll add(ll a,ll b){
  return ((a%M)+(b%M))%M;
}
ll mul(ll a,ll b){
  return ((a%M)*(b%M))%M;
}
int x;
void solve(){
  x=1;
  ll n,a;cin>>n>>a;
  ll ans=0;
  while(1){
    // cout<<a<<" "<<x<<"\n";
    ans=add(ans,powM(a,x));
    a=mul(a,powM(a,x));
    x+=2;
    if(x==2*n+1)break;
  }
  cout<<ans;
}
int main()
{
    ibs;cti;
    int t;cin>>t;
    while(t--){
      solve();
      // cout<<len;
      cout<<"\n";
    }
    return 0;
}