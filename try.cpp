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
#define double long double
#define int long long int
#define ll int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=1e6+10;
const int inf = /*0x3f3f3f3f*/1e9;
// const ll M = 998244353 ; // Mulo
const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int n,m,w,a1,b,ans;vector<int>a[N];
bool u[N],v[N];
void dfs1(int x){
    u[x]=1;
    if(x==b)return;
    // u[x]=1;
    for(int y:a[x])if(!u[y])
        dfs1(y);
}
void dfs2(int x){
  v[x]=1;
    if(x==a1)return;
    for(int y:a[x])if(!v[y])
        dfs2(y);
}
int x,y;
void solve(){
  cin>>n>>m>>a1>>b;
  for(int i=1;i<=n;i++){
   a[i].clear();
  }
  for(int i=1;i<=m;i++){
    cin>>x>>y;
    a[x].pb(y),a[y].pb(x);
  }
  memset(u,0,sizeof u), memset(v,0,sizeof v);
  dfs1(a1);
  dfs2(b);
  int A=0,B=0;
  for(int i=1;i<=n;i++){
    if(u[i]==1 and v[i]==0)A++;
    if(u[i]==0 and v[i]==1)B++;
  }
  // cout<<A<<" "<<B<<"\n";
  cout<<A*B;
}
int32_t main()
{
  ibs;cti;
  // solve()
  /*,cout<<"\n"*/;
  // cout<<"\n";
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<":\n"*/;solve();cout<<"\n";}
  return 0;
}