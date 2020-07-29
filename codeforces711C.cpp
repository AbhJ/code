#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <cstring>
#include <cstdio>
// #include <numeric>
#include <vector>
// #include <iterator> 
// #include <map>
// #include <set>
// #include <climits>
// #include <queue>
// #include <iomanip>
// #include <cmath>
// #include <stack>
#include <cctype>
// #include <bits/stdc++.h>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=1e2+10;
const int inf = 0x3f3f3f3f;
const ll M = 998244353 ; // Mulo
// const ll M = 1e9+7 ; // Mulo
#define F first
#define S second
int n,m,B;
ll dp[N][N][N],A[N][N],C[N];
//dp[i][j][k] is cost of colouting first i trees such that ith tree has kth colour
//and number of beauty till i is j
void solve(){
  cin>>n>>m>>B;
  for(int i=1;i<=n;i++)cin>>C[i];
  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
      cin>>A[i][j];
  C[0]=-1;
  for(int i=1;i<=n;i++)
    for(int j=0;j<=n;j++)
      for(int k=1;k<=m;k++){
          ll c=1e18;
          if(j==0 or j>i){dp[i][j][k]=1e18;continue;}
          for(int y=1;y<=m;y++){
            c=min(c,dp[i-1][j-(k!=y)][y]);
          }
          if(C[i]==0) dp[i][j][k]=c+A[i][k];
          else if(k==C[i])dp[i][j][k]=c;
          else dp[i][j][k]=1e18;
      }
  ll ans=1e18;
  for(int i=1;i<=m;i++)ans=min(ans,dp[n][B][i]);
  if(ans<1e18)cout<<ans;else cout<<-1;
}
int main()
{
  ibs;cti;
  solve(),cout<<"\n";
  // int t;cin>>t;
  // while(t--){solve();cout<<"\n";}
  return 0;
}