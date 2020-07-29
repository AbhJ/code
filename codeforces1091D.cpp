#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
using namespace std;//coded by abhijay mitra
const int N=2e7+3;
const int M = 1000000007; // modulo
ll powM(ll b, int p) {
  ll r=1;
  for(; p; b=b*b%M, p/=2)
    if(p&1)
      r=r*b%M;
  return r;
}
void solve(){
      int n;cin>>n;
      ll dp[n+1],fact[n+1];
      dp[0]=1;fact[0]=1;
      for (ll i = 1; i < n+1; ++i)
      {
        fact[i]=(i*fact[i-1])%998244353;
      }
      for (int i = 1; i !=n+1; ++i)
      {
        dp[i]=((dp[i-1]+fact[i-1]-1)%998244353*i)%998244353;
      }
      cout<<dp[n]<<"\n";
}
int main()
{   
    ibs;cti;
    solve();
    return 0;
}