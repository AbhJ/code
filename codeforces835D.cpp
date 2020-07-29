#include <bits/stdc++.h>
// #include <numeric>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=5e3+10;
const ll M = 1e9+7; // Mulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
int dp[N][N];
void solve(){
  string s;cin>>s;int n=s.length();
  s='#'+s;
  //dp[l][r] is highest k for all substrings s(l,r-1)inclusive 
  for(int len=0;len<=n;len++){
    for(int l=1;l<=n;l++){
      int r=l+len;//r-1 is last char of string and l is first
      if(r>n+1)continue;
      if(len==0){dp[l][r]=0;continue;}
      if(len==1){dp[l][r]=1;continue;}
      if(len==2){
        if(s[l]==s[r-1])dp[l][r]=2;continue;
      }
      int m=l+r>>1;
      if(dp[l+1][r-1]==0 or s[l]!=s[r-1])dp[l][r]=0;
      else if(len%2)dp[l][r]=dp[m+1][r]+1;
      else dp[l][r]=dp[m][r]+1;
    }
  }
  ll c[n+1];memset(c,0,sizeof(c));
  for (int i = 0; i <= n+1; ++i)
  {
    for (int j = 0; j <= n+1; ++j)
    {
      c[dp[i][j]]++;
      // if(dp[i][j]==2)cout<<i<<" "<<j;
    }
  }
  for (int i = n-1; i; --i)
  {
    c[i]+=c[i+1];
  }
  for (int i = 1; i < n+1; ++i)
  {
    cout<<c[i]<<" ";
  }
}
int main()
{
    // ibs;cti;
    // int t;cin>>t;
    // while(t--){
      solve();
      // cout<<len;
      cout<<"\n";
    // }
    return 0;
}