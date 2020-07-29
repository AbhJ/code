#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
using namespace std;//coded by abhijay mitra
const int N=2e7+3;
const int M = 1000000007; // modulo
int dp[N];
ll powM(ll b, int p) {
  ll r=1;
  for(; p; b=b*b%M, p/=2)
    if(p&1)
      r=r*b%M;
  return r;
}
void solve(){
      int n;cin>>n;string s;cin>>s;
      ll ans=0;int o=n;
      memset(dp,0,10*n+25);
      for (int i = 0; i < n; ++i)
      {
        //empty subset, o is offset
        ++dp[o];
        if(s[i]=='(')--o;
        if(s[i]==')'){
          ++o;
          ans+=(ll)dp[o-1]*(n-i);
          dp[o+1]+=dp[o-1];
          dp[o-1]=0;
        }
      }
      ans=ans%M*powM((ll)n*(n+1)/2%M,M-2)%M;
      cout<<ans<<"\n";
}
int main()
{   
    ibs;cti;
    int t;cin>>t;
    while(t--)
      solve();
    return 0;
}