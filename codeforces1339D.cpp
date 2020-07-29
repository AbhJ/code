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
// #include <bits/stdc++.h>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=1e5+10;
const int inf = 0x3f3f3f3f;
// const ll M = 998244353 ; // Mulo
const ll M = 1e9+7 ; // Mulo
#define F first
#define S second
set<int>leaf,leafer_parent;vector<int>a[N];
bool dfs(int u,int v=0,int depth=0){
  bool x=0;
  for(auto i:a[u])if(i!=v)if(dfs(i,u,depth+1)==1)return 1;
  if(leaf.count(u) and depth%2==1)return 1;
  return 0;
}
void solve(){
  int n;cin>>n;
  for (int i = 1; i <= n; ++i)leaf.insert(i);
  for (int i = 0; i < n-1; ++i)
  {
    int x,y;cin>>x>>y;
    a[x].pb(y),a[y].pb(x);
    if(a[x].size()>1)leaf.erase(x);
    if(a[y].size()>1)leaf.erase(y);
  }
  for(auto i:leaf)
    leafer_parent.insert(a[i][0]);
  int ma=n-1-leaf.size()+leafer_parent.size();
  int mi=1;
  for (int i = 1; i <= n; ++i)
    if(leaf.count(i)){
      if(dfs(i))mi=3;break;
    }
  cout<<mi<<" "<<ma;
}
int main()
{
  ibs;cti;
  solve(),cout<<"\n";
  // int t;cin>>t;
  // while(t--){solve();cout<<"\n";}
  return 0;
}