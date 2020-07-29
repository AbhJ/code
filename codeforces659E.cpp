#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <numeric>
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
const int N=1e5+1;
const int inf = /*0x3f3f3f3f*/1e15;
// const ll M = 998244353 ; // Mulo
const int M = 1e9+7 ; // Mulo
#define F first
#define S second
int n,m,x,y,ans,t,cycle_encountered,timestamp[N];vector<int>a[N];
void dfs(int u,int p=0){
  timestamp[u]=t++;
  for(auto v:a[u])if(v!=p){
    if(timestamp[v]!=0 and timestamp[v]<timestamp[u])cycle_encountered=1;
    if(timestamp[v]==0)dfs(v,u);
  }
}
void solve(){
  cin>>n>>m;
  for(int i=1;i<=m;i++){
    cin>>x>>y;
    a[x].pb(y),a[y].pb(x);
  }
  //ans is number of components having no cycles
  for(int i=1;i<=n;i++)
    if(timestamp[i]==0){
      cycle_encountered=0;
      dfs(i);
      if(cycle_encountered==0)ans++;
    }
  cout<<ans;
}
int32_t main()
{
  ibs;cti;
  solve(),cout<<"\n";
  int x=0;
  // int t;cin>>t;while(t--){/*x++;cout<<"Case #"<<x<<": ";*/solve();cout<<"\n";}
  return 0;
}