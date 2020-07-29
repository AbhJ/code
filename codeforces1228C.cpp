#include <bits/stdc++.h>
#include <numeric>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=2e6+10;
const ll M =  1e9+7; // Mulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
ll powM(ll a,ll b)
{
  ll ans=1;
  while(b)
  {
    if(b&1LL)ans=ans*a%M;
    a=a*a%M;
    b>>=1;
  }
  return ans;
}
void solve(){
  ll x,n;cin>>x>>n;ll c=0,i=0,ans=1;
  for (i = 2; i <= sqrt(x); ++i)
  {
    if(!(x%i)){
      while(!(x%i))x/=i;
      c=n;
      while(c/i)ans=ans*(powM(i,c/i))%M,c/=i;
    }
  }
  if(x!=1){
    i=x,c=n;while(c/i)ans=ans*(powM(i,c/i))%M,c/=i;
  }
  cout<<ans;
}
int main()
{   
    ibs;cti;
    // int t;cin>>t;
    // while(t--){
      solve();
      cout<<"\n";
    // }
    return 0;
}