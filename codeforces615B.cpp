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
const int N=1e5+10;
const int inf = 0x3f3f3f3f;
const ll M = 998244353 ; // Mulo
// const ll M = 1e9+7 ; // Mulo
#define F first
#define S second
vector<int>a[N];bool vis[N];int dp[N],adj[N];
void dfs(int x){
  if(vis[x]==1)return;
  vis[x]=1;
  for(auto i:a[x]){
    // if(i>x)continue;
    dfs(i);
    dp[x]=max(dp[x],dp[i]+1);
  }
}
void solve(){
  int n,m,u,v;cin>>n>>m;
  for(int i=1;i<=m;i++){cin>>u>>v;adj[u]++,adj[v]++;if(u>v)swap(u,v);a[v].pb(u);}
  for(int i=1;i<=n;i++){
    if(vis[i]==0)dfs(i);
  }
  ll ma=-1;
  for(int i=1;i<=n;i++)
    ma=max(ma,(ll)(dp[i]+1)*(adj[i]));
  cout<<ma;
}
int main()
{
  ibs;cti;
  solve(),cout<<"\n";
  // int t;cin>>t;
  // while(t--){solve();cout<<"\n";}
  return 0;
}