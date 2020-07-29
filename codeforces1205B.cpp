#include <bits/stdc++.h>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=2e2+30;
const int inf = 0x3f3f3f3f;
// const ll M = 998244353 ; // Mulo
const ll M = 1e9+7 ; // Mulo
#define F first
#define S second
int n,c[60];ll a[(int)1e5+10];int dp[N][N], x[N][N];//c[j] count number of times j th bit is set
void solve(){
  cin>>n;
  for(int i=1;i<=n;i++){
    cin>>a[i];
    for(int j=0;j<60;j++)if((a[i]>>j)&1)c[j]++;
    if(a[i]==0)i--,n--;
  }
  for(int i=0;i<60;i++)if(c[i]>=3 or n>226){cout<<3;return;}
  memset(dp,63,sizeof(dp));memset(x,63,sizeof(x));
  for(int i=1;i<=n;i++)
    for(int j=1;j<=i;j++)
      if((a[i]&a[j])!=0 and i!=j)x[i][j]=1,x[j][i]=1,dp[j][i]=1,dp[i][j]=1;
  for(int i=1;i<=n;i++)dp[i][i]=0;
  int ans=inf;
  for(int k=1;k<=n;k++)//k acts as connector
  {
    for(int i=1;i<k;i++)for(int j=1;j<k;j++)if(i!=j)ans=min((ll)ans,(ll)dp[i][j]+x[i][k]+x[j][k]);
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
  }
  if(ans<=n)cout<<ans;
  else cout<<-1;
}
int main()
{
  ibs;cti;
  solve(),cout<<"\n";
  // int t;cin>>t;
  // while(t--){solve();cout<<"\n";}
  return 0;
}