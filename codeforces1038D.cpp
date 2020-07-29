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
const int N=5e5+10;
const int inf = /*0x3f3f3f3f*/ 1e18+12;
// const int M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
#define F first
#define S second
int n;int a[N],dp[N][2],DP[N][2];
void solve(){
  cin>>n;
  for(int i=1;i<=n;i++)cin>>a[i];
  int ma=-inf;
  for(int i=1;i<=n;i++){
    dp[i][0]=max(dp[i-1][0],dp[i-1][1])-a[i];
    dp[i][1]=max(dp[i-1][1],dp[i-1][0])+a[i];
    if(i>=2)
    DP[i][0]=max(DP[i-1][0],dp[i-1][1])-a[i];
    if(i>=2)
    DP[i][1]=max(DP[i-1][1],dp[i-1][0])+a[i];
    if(i==1)
      DP[i][0]=a[i];
    if(i==1)
      DP[i][1]=-a[i];
    // cout<<dp[i][0]<<" "<<dp[i][1]<<"\n";
  }
  if(n>1)cout<<max(DP[n][1],DP[n][0]);
  else cout<<a[1];
}
int32_t main()
{
    ibs;cti;
    // int t;cin>>t;
    // while(t--){
      solve();
      cout<<"\n";
    // }
    return 0;
}