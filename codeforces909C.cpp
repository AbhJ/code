#include <bits/stdc++.h>
// #include <xeric>QC
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=5e3+10;
// const ll M = 998244353 ; // Mulo
const ll M = 1e9+7 ; // Mulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
ll add(ll a,ll b){
  return ((a%M)+(b%M))%M;
}
int n;string s;ll dp[N];ll F[N];
void solve(){
  cin>>n;char c;dp[0]=1;s="";F[0]=1;
  for(int i=0;i<n;i++){cin>>c,s+=c;if(i)F[i]=F[i-1];if(c=='f')F[i]++;}
  for (int I = 0; I < n; ++I)
  {
    if(s[I]=='s'){
      for(int i=1;i<F[I];i++)dp[i]=add(dp[i-1],dp[i]);
    }//no code can end with for so we wait till next simple comes
  }
  cout<<dp[F[n-1]-1];
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