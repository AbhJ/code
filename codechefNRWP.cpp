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
#include <bits/stdc++.h>
#define int long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=1e3+10;
const int inf = /*0x3f3f3f3f*/ 1e18+12;
// const int M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
#define F first
#define S second
int n,h,w,val[N][N];
set<pair<int,int>>s;set<pair<pair<int,int>,pair<int,int>>>adj;
int a[N][2];
map<pair<int,int>, int> p,position;
int sign[N],mi=-inf,ok[N];
void calc_cost(){
  int cos=0;
  for (int i = 1; i <= n; ++i)
  {
    cos+=(ok[i])*(p[{a[i][0],a[i][1]}])*(val[a[i][0]][a[i][1]]);
  }
  for (auto i:adj)
  {
    cos+=p[i.F]*p[i.S]*ok[position[i.F]]*ok[position[i.S]];
  }
  // cout<<cos<<"\n";
  if(cos>mi){
    mi=cos;
    for(int i=1;i<=n;i++)
      sign[i]=ok[i];
  }
}
void f(int i){
  if(i==n+1){
    calc_cost();return;
  }
  for (int j = -1; j <= 1; j+=2)
  {
    ok[i]=j;f(i+1);
  }
}
void solve(){
  mi=-inf;memset(ok,0,sizeof(ok));memset(sign,0,sizeof(sign));
  memset(val,0,sizeof(val));memset(a,0,sizeof(a));
  cin>>h>>w>>n;
  for (int i = 1; i <= h; ++i)
  {
    for(int j=1;j<=w;j++)
      cin>>val[i][j];
  }
  p.clear(),s.clear(),adj.clear();position.clear();
  for(int i=1;i<=n;i++){
    int x,y,cost;
    cin>>x>>y>>cost;
    p[{x,y}]=cost;
    position[{x,y}]=i;
    s.insert({x,y});
    a[i][0]=x,a[i][1]=y;
  }
  for (auto i:s)
  {
    int x=i.F,y=i.S;
    // for(int o=-1;o<=1;o+=2)
      for(int oo=-1;oo<=1;oo+=2){
        if(s.count({x,y+oo}) and adj.count({i,{x,y+oo}})==0)adj.insert({{x,y+oo},i});
        if(s.count({x+oo,y}) and adj.count({i,{x+oo,y}})==0)adj.insert({{x+oo,y},i});
      }
  }
  // for(auto i:adj){
  //   cout<<i.F.F<<" "<<i.F.S<<" "<<i.S.F<<" "<<i.S.S<<"\n";
  // }
  f(1);
  cout<<mi<<"\n";
  for(int i=1;i<=n;i++)cout<<sign[i]<<" ";
}
int32_t main()
{
    ibs;cti;
    int t;cin>>t;
    while(t--){
      solve();
      cout<<"\n";
    }
    return 0;
}