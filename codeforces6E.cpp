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
// #define int long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=1e5+10;
const int inf = /*0x3f3f3f3f*//*1e15*/1e9;
// const ll M = 998244353 ; // Mulo
const int M = 1e9+7 ; // Mulo
#define F first
#define S second
int n,k,a[N], t[4*N][2];
//building the tree
void build(int a[], int v=1, int tl=1, int tr=n) {
    if (tl == tr) {
        t[v][0]=t[v][1] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v][0] = min(t[v*2][0] , t[v*2+1][0]);
        t[v][1] = max(t[v*2][1],t[v*2+1][1]);
    }
}
//queries
pair<int,int> sum(int l, int r,int v=1, int tl=1, int tr=n ) {
    if (l > r) 
        return {inf,-inf};
    if (l == tl && r == tr)
        return {t[v][0],t[v][1]};
    int tm = (tl + tr) / 2;
    pair<int,int> x=sum( l, min(r, tm),v*2, tl, tm),y=sum(max(l, tm+1), r,v*2+1, tm+1, tr );
    return {min(x.F,y.F),max(x.S,y.S)};
}
vector<pair<int,int>>V;
bool f(int m){
  V.clear();
  for(int l=1;l<=n-m+1;l++){
    //l is going to be left boundary and we check for length = m
    int r=l+m-1;
    pair<int,int> x=sum(l,r);
    if(x.S-x.F<=k)V.pb({l,r});
  }
  if(V.empty()==1)return 0;
  return 1;
}
void solve(){
  cin>>n>>k;
  for(int i=1;i<=n;i++)cin>>a[i];
  build(a);
  int l=1,r=n;
  while(l<=r){
    int m=l+r>>1;
    if(f(m)==1)l=m+1;//we allow more difference
    else r=m-1;
    //we restrict distance
  }
  l--;
  f(l);
  cout<<l<<" "<<V.size()<<"\n";
  for(pair<int,int> i:V)cout<<i.F<<" "<<i.S<<"\n";
}
int32_t main()
{
  ibs;cti;
  solve()/*,cout<<"\n"*/;
  int x=0;
  // int t;cin>>t;while(t--){/*x++;cout<<"Case #"<<x<<": ";*/solve();cout<<"\n";}
  return 0;
}