#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <numeric>
#include <vector>
#include <iterator> 
#include <map>
#include <set>
#include <climits>
#include <queue>
#include <iomanip>
#include <cmath>
#include <stack>
#include <cctype>
#include <bitset>
// #include <bits/stdc++.h>
#define int long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=1e3+10;
const int inf = /*0x3f3f3f3f*/1e15;
// const ll M = 998244353 ; // Mulo
const int M = 1e9+7 ; // Mulo
#define F first
#define S second
int n,m,dp[N][N],x[N],y[N];
void solve(){
  cin>>n>>m;
  for(int i=1;i<=n-1;i++)cin>>x[i];
  for(int i=1;i<=m-1;i++)cin>>y[i];
  sort(x+1,x+n),sort(y+1,y+m);
  reverse(x+1,x+n),reverse(y+1,y+m);
  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++){
      if(i==1)dp[i][j]=y[j-1]+dp[i][j-1];
      else if(j==1)dp[i][j]=x[i-1]+dp[i-1][j];
      else dp[i][j]=min(dp[i-1][j]+x[i-1]*j,dp[i][j-1]+y[j-1]*i);
    }
  cout<<dp[n][m];
}
int32_t main()
{
  ibs;cti;
  // solve(),cout<<"\n";
  int t;cin>>t;
  // int x=0;
  while(t--){solve();cout<<"\n";}
  return 0;
}