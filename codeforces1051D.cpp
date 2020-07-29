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
const int M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
#define F first
#define S second
int add(int a,int b){
  return ((a%M)+(b%M))%M;
}
int n,m;int dp[N][2*N][4];
void solve(){
  //0 WW 1 WB 2 BW 3 BB
  //for pattern watch https://www.youtube.com/watch?v=lSyQQ1T6iQ8
  cin>>n>>m;dp[1][1][0]=dp[1][2][1]=dp[1][2][2]=dp[1][1][3]=1;
  //dp i j k is answer for i columns j components and k state
  for(int i=2;i<=n;i++)
    for(int j=1;j<=2*i;j++){
          dp[i][j][0]=add(dp[i-1][j][0],add(dp[i-1][j][1],add(dp[i-1][j][2],dp[i-1][j-1][3])));
          dp[i][j][1]=add(dp[i-1][j-1][0],add(dp[i-1][j-2][1],add(dp[i-1][j][2],dp[i-1][j-1][3])));
          dp[i][j][2]=add(dp[i-1][j-1][0],add(dp[i-1][j][1],add(dp[i-1][j-1][3],dp[i-1][j-2][2])));
          dp[i][j][3]=add(dp[i-1][j][3],add(dp[i-1][j][1],add(dp[i-1][j][2],dp[i-1][j-1][0])));
    }
  cout<<add(dp[n][m][1],add(dp[n][m][0],add(dp[n][m][2],dp[n][m][3])));
}
int32_t main()
{
  ibs;cti;
  solve(),cout<<"\n";
  // int t;cin>>t;
  // while(t--){solve();cout<<"\n";}
  return 0;
}