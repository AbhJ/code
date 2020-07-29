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
const int N=1e6+10;
const int inf = /*0x3f3f3f3f*/ 1e18+12;
// const ll M = 998244353 ; // Mulo
// const ll M = 1e9+7 ; // Mulo
#define F first
#define S second
int n,m,t[4*N],ma[4*N],d[N];
int dd(int );
void f(){
    for(int i=1;i<N;i++){
        for(int j=i;j<N;j+=i)d[j]++;
    }
}
//building the tree
void build(int a[],int v=1, int tl=1, int tr=n) {
    if (tl == tr) {
        t[v]=ma[v]=a[tl];return;
    }
    int tm = (tl + tr) / 2;
    build(a,v*2, tl, tm);
    build(a,v*2+1, tm+1, tr);
    t[v]=t[2*v]+t[2*v+1];
    ma[v]=max(ma[v*2],ma[v*2+1]);
}
//queries
int sum(int l, int r,int v=1, int tl=1, int tr=n ) {
    if (l > r) 
        return 0;
    if (l <= tl && r >= tr)
        return t[v];
    int tm = (tl + tr) / 2;
    return sum( l, min(r, tm),v*2, tl, tm)
           + sum(max(l, tm+1), r,v*2+1, tm+1, tr );
}
void update(int l,int r,int tl=1,int tr=n,int v=1){
  if(ma[v]<=2)return ;
  if(tl==tr){
    t[v]=ma[v]=d[t[v]];return ;
  }
  int mid=(tr+tl)/2;
  if(l<=mid)update(l,min(r,mid),tl,mid,v*2);
  if(r>mid)update(max(l,mid+1),r,mid+1,tr,v*2+1);
  t[v]=t[v*2]+t[v*2+1];
  ma[v]=max(ma[v*2],ma[v*2+1]);
}
int dd(int n)
{
    int c=0;
    for(int i=1;i<=sqrt(n);++i)
    {
        if(n%i==0)
        {
            c++;
            if(i*i!=n)
                c++;
        }
    }
    return c;
}
int x,l,r,a[N];
void solve(){
  cin>>n>>m;f();
  for (int i = 1; i <=n; ++i){cin>>a[i];/*a[i]=d(a[i]);*/}
  build(a);
  while(m--){
    cin>>x>>l>>r;
    if(x==2)cout<<sum(l,r)<<"\n";
    else update(l,r);
  }
}
int32_t main()
{
  ibs;cti;
  solve(),cout<<"\n";
  // int t;cin>>t;
  // while(t--){solve();cout<<"\n";}
  return 0;
}