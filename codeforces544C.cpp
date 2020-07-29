#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <cstring>
#include <cstdio>
// #include <numeric>
#include <vector>
// #include <iterator> 
// #include <map>
#include <set>
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
const int N=5e2+10;
const int inf = 0x3f3f3f3f;
// const ll M = 998244353 ; // Mulo
// const ll M = 1e9+7 ; // Mulo
#define F first
#define S second
int a,dp[2][N][N];bool z,y;
int n,m,b;ll M,ans;
ll add(ll a,ll b){
  return ((a%M)+(b%M))%M;
}
void solve(){
  cin>>n>>m>>b>>M;
  dp[0][0][0]=1;
  for(int i=1;i<=n;i++){
    cin>>a;
    for(int j=0;j<=m;j++)
      for(int k=0;k<=b;k++){
        z=i&1;y=!z;
        dp[z][j][k]=dp[y][j][k];
        if(j!=0 and k>=a)dp[z][j][k]=add(dp[z][j][k],dp[z][j-1][k-a]);
      }
  }
  for(int i=0;i<=b;i++)ans=add(ans,dp[z][m][i]);
  cout<<ans;
}
int main()
{
  ibs;cti;
  solve(),cout<<"\n";
  // int t;cin>>t;
  // while(t--){solve();cout<<"\n";}
  return 0;
}