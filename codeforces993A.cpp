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
const int N=2e3+10;
const int inf = /*0x3f3f3f3f*/1e15;
const int M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
#define F first
#define S second
//dp[i][j] is longest increasing subsequence from i to j
int n;int dp[N][4],a[N];
void solve(){
  cin>>n;
  int c=0,d=0;
  for (int i =1;i<=n; ++i){cin>>a[i];if(a[i]==2)c=1;else d=1;}
  for(int i=1;i<=n;i++){
    for(int j=0;j<4;j++)dp[i][j]=dp[i-1][j];
    for(int j=1;j<4;j++)dp[i][j]=max(dp[i][j],dp[i][j-1]);
    if(a[i]==1)dp[i][0]++,dp[i][2]++;
    else dp[i][1]++,dp[i][3]++;
    // if(a[i]==1)dp[i][0]=max(dp[i][0],1);

    // for(int j=1;j<4;j++)dp[i][j]=max(dp[i][j],dp[i][j-1]+1);
  }
  // if(c==0)cout<<dp[n][0];
  // else if(d==0)cout<<dp[n][1]
  cout<<max(dp[n][3],max(dp[n][2],max(dp[n][1],dp[n][0])));
}
int32_t main()
{
  ibs;cti;
  solve(),cout<<"\n";
  // int t;cin>>t;
  // while(t--){solve();cout<<"\n";}
  return 0;
}