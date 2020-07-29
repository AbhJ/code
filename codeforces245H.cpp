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
int dp[N][N],n;string s;bool p[N][N];
void solve(){
  cin>>s;n=s.length();s='#'+s;
  for (int l = 1; l <= n; ++l)
  {
    for (int i = 1; i <= n; ++i){
      int j=i+l-1;
      if(j>n)continue;
      if(l==1)p[i][j]=1;
      if(l==2)p[i][j]=(s[i]==s[j]);
      if(l<3)continue;
      p[i][j]=p[i+1][j-1]&(s[i]==s[j]);
    }
  }
  for (int l = 1; l <= n; ++l)
  {
    for (int i = 1; i <= n; ++i)
    {
      int j=i+l-1;
      if(j>n)continue;
      if(l==1)dp[i][j]=1;
      if(l==2)dp[i][j]=2+(s[i]==s[j]);
      if(l<3)continue;
      dp[i][j]=dp[i+1][j]+dp[i][j-1]+p[i][j]-dp[i+1][j-1];
    }
  }
  int m;cin>>m;
  while(m--){
    int x,y;cin>>x>>y;
    cout<<dp[x][y]<<"\n";
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