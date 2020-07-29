#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
using namespace std;//coded by abhijay mitra
const int N=2e5+3;
const long M = 1000000007; // modulo
// int m[2][N];//the grid
ll x[N],fac[N],ifac[N],n;
long long inv(int a,int p=M){return a==1?1:(1+p*(a-inv(p%a,a)))/a%p;}
int solve(ll s){
  int c=0;
  for (int i = 0; i < 2*n; ++i)
    if(x[i]==s)c<2?x[i]=INT_MAX:1,c++;
  if(c<2)return 0;
  sort(x,x+n*2);
  ll ans=1;
  for (int i = 0; i < n-1; ++i)
  {
    if(x[n*2-3-i]+x[i]!=s)return 0;
    if(x[n*2-3-i]!=x[i])ans=(ans<<1)%M;
  }
  for(ll i=*fac=1;i<n;i++)fac[i]=fac[i-1]*i%M;
  ifac[n-1]=inv(fac[n-1]);
  for(ll i=n-1;i;i--)ifac[i-1]=ifac[i]*i%M;
  ans=ans*fac[n-1]%M;
  for(int i=0,j=0;i<n-1;i=j){
    for(;j<n-1 and x[i]==x[j];j++);
    ans=ans*ifac[j-i]%M;
  }
  return ans;
}
int main()
{   
    ibs;cti;int t;cin>>t;while(t--){
      ll s=0;cin>>n;
      for (ll i = 0; i < 2*n; ++i)cin>>x[i],s+=x[i];
      cout<<(!(s%(n+1))?solve(s/(n+1)):0)<<"\n";
    }
    return 0;
}