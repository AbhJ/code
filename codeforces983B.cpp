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
const int N=5e3+10;
const int inf = /*0x3f3f3f3f*/ 1e18+12;
// const int M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
#define F first
#define S second
int a[N],dp[N][N],n,q,l,r;
void solver(){
  for (int i = n; i >=1 ; --i)dp[i][i]=a[i];
  for (int i = n; i >=1 ; --i)
  {
    for(int j=i+1;j<=n;j++){
      dp[i][j]=dp[i+1][j]^dp[i][j-1];
    }
  }
  for (int i = n; i >=1 ; --i)
  {
    for(int j=i+1;j<=n;j++){
      dp[i][j]=max(dp[i][j],max(dp[i+1][j],dp[i][j-1]));
    }
  }
}
int f(){
  return dp[l][r];
}
void solve(){
  cin>>n;
  for(int i=1;i<=n;i++)cin>>a[i];cin>>q;
  solver();
  while(q--){
    cin>>l>>r;
    cout<<f()<<"\n";
  }
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