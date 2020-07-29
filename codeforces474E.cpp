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
const int N=1e5+10;
const int inf = /*0x3f3f3f3f*/ 1e18+12;
// const ll M = 998244353 ; // Mulo
// const ll M = 1e9+7 ; // Mulo
#define F first
#define S second
int n,d, t[3*N],ma,how[N],ok[N],dp[N];pair<int,int>h[N];
//building the tree
// void build(int a[],int v=1, int tl=1, int tr=n) {
//     if (tl == tr) {
//         t[v]=a[tl];
//     } else {
//         int tm = (tl + tr) / 2;
//         /*if(pos<=tm)*/build(a,v*2, tl, tm);
//         /*else*/ build(a,v*2+1, tm+1, tr);
//         //
//         // for (int i = 0; i <26; ++i){
//         //     t[v][i]=t[v*2+1][i]+t[v*2][i];
//         // }
//         t[v]=__gcd(t[2*v],t[2*v+1]);
//         // cout<<"F";
//     }
// }
//queries
void sum(int l,int r, int v=1,int tl=1, int tr=n ) {
    // if(l>r)return;
    if(l>h[tr].F or r<h[tl].F)return;
    if(l<=h[tl].F and r>=h[tr].F){
      if(ma==-1 or dp[ma]<dp[t[v]])ma=t[v];return;
    }
    int tm = (tl + tr) / 2;
    // cout<<"F";
     sum( l, r,v*2, tl,tm);sum(l, r,v*2+1,tm+1, tr );
}
//update
// void update(int l, int r,int v=1, int tl=1, int tr=n ) {
//     if(l<tl or l>tr)return;
//     if (tl == tr) {//node
//         t[v]=r;
//         return;
//     } else {
//         int tm = (tl + tr) / 2;
//         // if (pos <= tm)
//             update(l,r,v*2, tl, tm);
//         // else
//             update(l,r,v*2+1, tm+1, tr);
//         t[v]=t[v*2+1];
//         if(dp[t[v]]<dp[t[v*2]])t[v]=t[v*2];
//         return;
//     }
// }
void update(int l,int r,int tl=1,int tr=n,int v=1){
  if(tl>l||tr<l)return ;
  if(tl==tr){t[v]=r;return ;}
  int mid=(tr+tl)/2;
  update(l,r,tl,mid,v*2);
  update(l,r,mid+1,tr,v*2+1);
  t[v]=t[v*2+1];
  if(dp[t[v]]<dp[t[v*2]])t[v]=t[v*2];
}
void prn(int x){
  cout<<x<<" ";
  if(how[x])prn(how[x]);
}
int m,p,v,l,r;
void solve(){
  cin>>n>>d;
  for (int i = 1; i <= n; ++i){cin>>h[i].F;h[i].S=i;}
  sort(h+1,h+1+n);
  for (int i = 1; i <= n; ++i)ok[h[i].S]=i;
  for(int i=n;i>=1;i--){
     ma=0;
     sum(h[ok[i]].F+d,inf);
     sum(-inf,h[ok[i]].F-d);
     dp[i]=dp[ma]+1;
     how[i]=ma;
     update(ok[i],i);
   }
   ma=0;
  for (int i = 1; i <= n ; ++i)
  {
    if(dp[ma]<dp[i])ma=i;
  }
  cout<<dp[ma]<<"\n";
   prn(ma);
}
int32_t main()
{
  // ibs;cti;
  solve(),cout<<"\n";
  // int t;cin>>t;
  // while(t--){solve();cout<<"\n";}
  return 0;
}