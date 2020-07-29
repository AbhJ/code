#include <bits/stdc++.h>
// #include <numeric>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=2e3+10;
const ll M = 998244353; // Mulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
ll dp[N][N];
void solve(){
  int n,m,K;cin>>n>>m>>K;
  dp[1][0]=m;
  for(int i=2;i<=n;i++){
    for(int k=0;k<=K;k++){
      // if(i==1 or k==0)dp[i][k]=m;
      dp[i][k]=((dp[i-1][k-1]*(m-1))%M+dp[i-1][k]%M)%M;
    }
  }
  cout<<dp[n][K];
  // else cout<<m;
}
int main()
{
    ibs;cti;
    // int t;cin>>t;
    // while(t--){
      solve();
      cout<<"\n";
    // }
    return 0;
}