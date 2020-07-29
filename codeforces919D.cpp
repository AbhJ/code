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
const int N=3e5+10;
const int inf = /*0x3f3f3f3f*/1e15;
// const ll M = 998244353 ; // Mulo
const int M = 1e9+7 ; // Mulo
#define F first
#define S second
int n,m,vis[N],ma,dp[N][30],ans;
vector<int>v[N];
int in_loop[N];
vector<int>a[N];string s;
set<int>S;
void dfs(int x){
  vector<int>z(30,0);
  if(v[x].size()==30)z=v[x];
  in_loop[x]=1;
  S.erase(x);
  for(auto i:a[x]){
    if(in_loop[i]==1){cout<<-1<<"\n";exit(0);}
    if(S.count(i))dfs(i);
    auto V=v[i];
    for(int j=0;j<26;j++)
      z[j]=max(z[j],V[j]);
  }
  z[s[x]-'a']++;
  v[x]=z;
  ans=max(ans,*max_element(v[x].begin(), v[x].end()));
  in_loop[x]=0;
}
int x,y;
void solve(){
  cin>>n>>m>>s;s='#'+s;
  for(int i=1;i<=m;i++){
    cin>>x>>y;
    a[x].pb(y);
  }
  for(int i=1;i<=n;i++)S.insert(i);
  for(int i=1;i<=n;i++)
    if(S.count(i)){
      dfs(i);
    }
  cout<<ans;
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