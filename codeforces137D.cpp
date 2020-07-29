#include <bits/stdc++.h>
// #include <numeric>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=5e2+10;
const ll M = 1e9+7; // Mulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
string s;int c[N][N],dp[N][N],p[N][N];
void f(int r,int k){
  if(!k)return;
  f(p[r][k],k-1);
  if(p[r][k])cout<<"+";
  for (int i = p[r][k]+1,S=0; i <= r; ++i,++S)
  {
    cout<<s[min(i,r-S)];
  }
}
int k,n;
void solve(){
  memset(dp,0x3f,sizeof(dp));dp[0][0]=0;
  cin>>s>>k;n=s.length();
  s='#'+s;
  for(int l=1;l<=n;l++)
    for(int i=1;i<=n;i++){
      int j=i+l-1;
      if(j>n)continue;
      c[i][j]=c[i+1][j-1]+(s[i]!=s[j]);
    }
  //c i,j is cost of making s(i,j) a palindrome
  for(int i=1;i<=n;i++)
    for(int j=1;j<=k;j++)
      for(int K=0;K<i;K++){
        if(dp[i][j]>dp[K][j-1]+c[K+1][i])
         dp[i][j]=dp[K][j-1]+c[K+1][i],p[i][j]=K;
      }
  int j=0;
  for(int i=1;i<=k;i++){
        if(dp[n][j]>dp[n][i]){
            j=i;
        }
  }
  cout<<dp[n][j]<<"\n";
  f(n,j);
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