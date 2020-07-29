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
const int N=1e6+1;
const int inf = /*0x3f3f3f3f*/1e15;
// const ll M = 998244353 ; // Mulo
const int M = 1e9+7 ; // Mulo
#define F first
#define S second
int n, t[4*N],a[N];
//building the tree
void build( int v=1, int tl=1, int tr=n) {
    if (tl == tr) {
        // cout<<"F";
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build( v*2, tl, tm);
        build( v*2+1, tm+1, tr);
        t[v] = t[v*2] + t[v*2+1];
        // cout<<"F";
    }
}
int get(int k,int v=1,int tl=1,int tr=n){
  if(tl==tr)return tl;
  int tm=tl+tr>>1;
  if(t[2*v]>=k)return get(k,2*v,tl,tm);
  return get(k-t[2*v],2*v+1,tm+1,tr);
}
void update(int pos, int new_val,int v=1, int tl=1, int tr=n ) {
    if (tl == tr) {
        t[v] += new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(pos,new_val,v*2, tl, tm);
        else
            update(pos,new_val,v*2+1, tm+1, tr);
        t[v] = t[v*2] + t[v*2+1];
    }
}
int x,k,m;
void solve(){
  cin>>n>>m;
  for(int i=1;i<=n;i++){cin>>x;a[x]++;}
  build();
  for(int i=1;i<=m;i++){
    cin>>k;
    if(k<0){int pos=get(abs(k));
        update(pos,k/abs(k));}
    else update(k,1);
  }
  if(t[1]==0)cout<<0;else
  cout<<get(1);
}
int32_t main()
{
  ibs;cti;
  solve(),cout<<"\n";
  int x=0;
  // int t;cin>>t;while(t--){solve();cout<<"\n";}
  return 0;
}