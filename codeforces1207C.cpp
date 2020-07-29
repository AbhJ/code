#include <bits/stdc++.h>
// #include <numeric>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=1e6+10;
const ll M =  1e9+7; // Mulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
void solve(){
  int n,a,b;cin>>n>>a>>b;string s; cin>>s;
  ll dp[n+2][2]={0};dp[0][0]=b;dp[0][1]=1e18;
  for (int i = 1; i <= n; ++i)
  {
    if(s[i-1]=='0'){
      dp[i][0]=min(dp[i-1][0]+a,dp[i-1][1]+2*a)+b;//height 1
      dp[i][1]=min(dp[i-1][0]+2*a,dp[i-1][1]+a)+2*b;//height 2
    }
    else{
      dp[i][0]=1e18;//height 1
      dp[i][1]=dp[i-1][1]+a+2*b;//height 2
    }
  }
  cout<<dp[n][0];
}
int main()
{
    ibs;cti;
    int t;cin>>t;
    while(t--){
      solve();
      cout<<"\n";
    }
    return 0;
}