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
const int inf = /*0x3f3f3f3f*/1e15;
// const ll M = 998244353 ; // Mulo
const int M = 1e9+7 ; // Mulo
#define F first
#define S second
int n,m,l,r,j,a[N],dp[N][N];
//dp[i][j] is the ans for starting at i coloring it with j
void solve(){
  cin>>n;
  for(int i=1;i<=n;i++){cin>>j;if(l!=j)a[++m]=j,l=j;}
  for(int i=1;i<=m;i++){
    for(l=1;l<=m-i;l++){
      r=i+l;
      if(a[l]==a[r])dp[l][r]=dp[l+1][r-1]+1;
      else dp[l][r]=1+min(dp[l+1][r],dp[l][r-1]);
    }
  }
  cout<<dp[1][m];
}
int32_t main()
{
  ibs;cti;
  solve(),cout<<"\n";
  // int t;cin>>t;
  // int x=0;
  // while(t--){solve();cout<<"\n";}
  return 0;
}