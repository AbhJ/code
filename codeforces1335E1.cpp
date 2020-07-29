#include <bits/stdc++.h>
// #include <xeric>QC
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=2e3+10;
const ll M = 998244353 ; // Mulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
int a[N];int dp[40][N];
int f(int x,int l, int r){
  if(l==-1)return dp[x][r+1];
  return dp[x][r+1]-dp[x][l];
}
void solve(){
  int n;cin>>n;
  memset(a,0,sizeof(a));memset(dp,0,sizeof(dp));
  for (int i = 0; i < n; ++i){
    cin>>a[i];
    for(int j=0;j<40;j++)dp[j][i+1]=dp[j][i];
    dp[a[i]-1][i+1]++;
  }
  int ans=0;
  for(int j=0;j<40;j++)ans=max(ans,f(j,-1,n-2));
  for (int i = 0; i < n; ++i)
  {
    for (int j= i; j < n; ++j)
    {
      int x=0,y=0;
      for(int J=0;J<40;J++){
        x=max(x,f(J,i,j));
        y=max(y,min(f(J,-1,i-1),f(J,j+1,n-1)));
      }
      ans=max(ans,x+2*y);
    }
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