#include <iostream>
// #include <stdlib.h>
// #include <algorithm>
#include <cstring>
// #include <cstdio>
// #include <numeric>
#include <vector>
// #include <iterator> 
// #include <map>
// #include <set>
// #include <cstdio>
// #include <climits>
// #include <queue>
// #include <iomanip>
// #include <cmath>
// #include <stack>
// #include <cctype>
// #include <bits/stdc++.h>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=5e3+10;
const int inf = 0x3f3f3f3f;
const ll M = 998244353 ; // Mulo
// const ll M = 1e9+7 ; // Mulo
#define F first
#define S second
vector<pair<int,int> >a[N];
int n,m,T;
int dp[N][N];int A[N][N];bool vis[N];
//dp[i][j] is minimum time to reach i if we visit j vertices on the way
//A[i][j] is child of i after covering j vertices from vertex 1
void dfs(int x){
  if(vis[x]==1 or x==n)return;
  vis[x]=1;
  for(auto i:a[x]){
    dfs(i.F);//fill out deepest first
    for(int j=2;j<=n;j++)
      if(dp[i.F][j-1]+i.S<dp[x][j])
        dp[x][j]=dp[i.F][j-1]+i.S,A[x][j]=i.F;
  }
}
void solve(){
  cin>>n>>m>>T;
  for(int i=0;i<m;i++){
    int x,y,z;cin>>x>>y>>z;
    a[x].pb({y,z});
  }
  dp[n][1]=0;
  dfs(1);int i,j=1;
  for(i=n;i>=1;i--)
    if(dp[1][i]<=T){//choose path with highest number of vertices
      cout<<i<<"\n1 ";break;
    }
  while(i-1)
    cout<<(j=A[j][i--])<<" ";
}
int main()
{
  ibs;cti;
  memset(dp,inf,sizeof(dp));
  solve(),cout<<"\n";
  // int t;cin>>t;
  // while(t--){solve();cout<<"\n";}
  return 0;
}