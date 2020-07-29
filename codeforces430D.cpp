#include <bits/stdc++.h>
// #include <numeric>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=1e3+10;
const ll M = 1e9+7; // Mulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
ll dp[5][N][N];ll a[N][N];
void solve(){
  int n,m;cin>>n>>m;
  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
      cin>>a[i][j];
  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
      dp[1][i][j]=max(dp[1][i-1][j],dp[1][i][j-1])+a[i][j];
  for(int i=1;i<=n;i++)
    for(int j=m;j>=1;j--)
      dp[2][i][j]=max(dp[2][i][j+1],dp[2][i-1][j])+a[i][j];
  for(int i=n;i>=1;i--)
    for(int j=1;j<=m;j++)
      dp[3][i][j]=max(dp[3][i+1][j],dp[3][i][j-1])+a[i][j];
  for(int i=n;i>=1;i--)
    for(int j=m;j>=1;j--)
      dp[4][i][j]=max(dp[4][i+1][j],dp[4][i][j+1])+a[i][j];
  ll ans=0;
  for(int i=2;i<n;i++)
    for(int j=2;j<m;j++)
      ans=max(ans,max(dp[1][i][j-1]+dp[4][i][j+1]+dp[2][i-1][j]+dp[3][i+1][j],dp[1][i-1][j]+dp[4][i+1][j]+dp[3][i][j-1]+dp[2][i][j+1]));
  cout<<ans;
}
int main()
{
    // ibs;cti;
    // int t;cin>>t;
    // while(t--){
      solve();
      // cout<<len;
      // cout<<"\n";
    // }
    return 0;
}