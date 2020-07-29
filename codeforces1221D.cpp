#include <bits/stdc++.h>
#include <numeric>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=3e5+10;
const ll M =  1e9+7; // Mulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
ll dp[3][N],a[N],b[N];
void solve(){
  a[0]=-10;
  int n;cin>>n;
  // memset(dp,0,sizeof(dp));
  for (int i = 1; i <= n; ++i)cin>>a[i]>>b[i],dp[0][i]=dp[1][i]=dp[2][i]=1e18;
  // for (int i = 1; i <= n; ++i)cin>>b[i];
  for (int i = 1; i <= n; ++i)
  {
    for(int j=0;j<3;j++){
      ll mi=1e18;
      for(int k=0;k<3;k++)
        if(a[i-1]+k!=a[i]+j)mi=min(dp[k][i-1],mi);
      dp[j][i]=mi+j*b[i];
    }
  }
  ll mi=1e18;
  for (int i = 0; i < 3; ++i)
  {
    mi=min(mi,dp[i][n]);
  }
  cout<<mi;
}
int main()
{
    ibs;cti;
    int t;cin>>t;
    int x=1;
    while(t--){
      // cout<<"Case #"<<x<<": ";
      // x++;
      solve();
      cout<<"\n";
    }
    return 0;
}