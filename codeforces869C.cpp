#include <bits/stdc++.h>
// #include <xeric>QC
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=5e3+10;
const ll M = 998244353 ; // Mulo
// const ll M = 1e9+7 ; // Mulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
ll mul(ll a,ll b){
  return ((a%M)*(b%M))%M;
}
ll C[N][N],f[N];
ll add(ll a,ll b){
  return ((a%M)+(b%M))%M;
}
ll solve(ll a, ll b){
  if(a>b)swap(a,b);
  ll ans=0,t;
  for (int i = 0; i <= a; ++i)
  {
    ans=add(ans,mul(C[a][i],mul(C[b][i],f[i])));
  }
  return ans;
}
ll a,b,c;
int main()
{
    ibs;cti;
    // int t;cin>>t;
    // while(t--){
    cin>>a>>b>>c;
    f[0]=1;
    for (int i =0; i <= N-1; ++i){
      if(i)f[i]=mul(i,f[i-1]);
      for(int j=0;j<=i;j++){
        if(j==0 or j==i)C[i][j]=1;
        else C[i][j]=add(C[i-1][j-1],C[i-1][j]);
      }
    }
      cout<<mul(solve(a,b),mul(solve(b,c),solve(c,a)));
      // cout<<len;
      cout<<"\n";
    // }
    return 0;
}