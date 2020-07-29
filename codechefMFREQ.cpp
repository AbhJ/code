#include <bits/stdc++.h>
// #include <xeric>QC
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=1e5+10;
const ll M = 998244353 ; // Mulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
int a[N],n,dp[2][N];
void f(){
  for (int i = 1; i <= n; ++i)
  {
    if(a[i]==a[i-1])dp[0][i]=dp[0][i-1];
    else dp[0][i]=i;
  }
  for(int i=n;i>=1;i--){
    if(a[i]==a[i+1])dp[1][i]=dp[1][i+1];
    else dp[1][i]=i;
  }
}
void solve(){
  int m;cin>>n>>m;
  for (int i = 1; i <= n; ++i)cin>>a[i];
  f();
  while(m--){
    int l,r,k;cin>>l>>r>>k;
    int i=(r+l+1)/2;
    int len=min(dp[1][i],r)+1-max(dp[0][i],l);
    if(len>=k)cout<<a[i];else cout<<-1;
    if(m)cout<<"\n";
  }
}
int main()
{
    ibs;cti;
    // int t;cin>>t;
    // while(t--){
      solve();
      // cout<<len;
      cout<<"\n";
    // }
    return 0;
}