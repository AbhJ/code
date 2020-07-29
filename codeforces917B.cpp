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
const int N=1e2+10;
const int inf = /*0x3f3f3f3f*/1e15;
// const ll M = 998244353 ; // Mulo
const int M = 1e9+7 ; // Mulo
#define F first
#define S second
vector<pair<int,char>>a[N];
bool vis[N][N][3*N];int dp[N][N][3*N];//dp[i][j][k] is who wins if max at i
//lucas at j and last color is k
int ok,mal,lal;
bool dfs(int i,int j,char c){
  if(vis[i][j][c]==1)return dp[i][j][c];
  vis[i][j][c]=1;
  for(auto x:a[i])if(x.S>=c){
    if(dfs(j,x.F,x.S)==0)
    dp[i][j][c]=1;
  }
  return dp[i][j][c];
}
int n,m,d1,d2,x,y;char c;
void solve(){
  cin>>n>>m;
  for (int i = 0; i < m; ++i)
  {
    cin>>x>>y>>c;
    a[x].pb({y,c});
  }
  for (int i = 1; i <= n; ++i)
  {
    for(int j=1;j<=n;j++){
      if(dfs(i,j,'a'))cout<<"A";
      else cout<<"B";
    }
    cout<<"\n";
  }
}
int32_t main()
{
  ibs;cti;
  solve()/*,cout<<"\n"*/;
  // int t;cin>>t;
  // int x=0;
  // while(t--){solve();cout<<"\n";}
  return 0;
}