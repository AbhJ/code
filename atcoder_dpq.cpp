//Coded by Abhijay Mitra
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <numeric>
#include <vector>
#include <iterator> 
#include <map>
#include <set>
#include <climits>
#include <queue>
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
#define res(v) v.resize(unique(v.begin(), v.end()) - v.begin());
#define cnt_res(v) std::distance(v.begin(),std::unique(v.begin(), v.end())); 
#define timer cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
using vi = std::vector<int>;
using vvi = std::vector<vi>;
using pii = std::pair<int,int>;
using vpii = std::vector<pii>;
using vvpii = std::vector<vpii>;
#define mp         make_pair
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define per(i,b,a) for (int i = b; i >= a; i--)
#define all(x)     x.begin(), x.end()
using namespace std;
const int N=2e6+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int n,a[N],h[N],dp[N],t[4*N];
// void build(int l=1,int r=n,int v=1){
//   if(l==r){t[v]=a[l];return;}
//   int m=l+r>>1;
//   build(l,m,v*2);build(m+1,r,v*2+1);
//   t[v]=max(t[v*2],t[v*2+1]);
// }
// int ma(int l,int r,int v=1,int tl=1,int tr=n){
//   if(l<=tl and r>=tr){return t[v];}
//   int m=tl+tr>>1;
//   return max(ma(l,r,v*2,tl,m),ma(l,r,v*2+1,m+1,tr));
// }
// void u(int pos,int val,int v=1,int tl=1,int tr=n){
//   if(tl==tr){t[v]=val;}
//   int m=tl+tr>>1;
//   if(pos<=m)u(pos,val,v*2,tl,m);
//   else u(pos,val,v*2+1,m+1,tr);
//   t[v]=max(t[v*2],t[v*2+1]);
// }
void build(int a[], int v=0, int tl=1, int tr=n) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = t[v*2] + t[v*2+1];
    }
}
//queries
int sum(int l, int r,int v=1, int tl=0, int tr=N ) {
    if (l > r) 
        return -inf;
    if (l == tl && r == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    return max(sum( l, min(r, tm),v*2, tl, tm)
               , sum(max(l, tm+1), r,v*2+1, tm+1, tr ));
}
//
void update(int pos, int new_val,int v=1, int tl=0, int tr=N ) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(pos,new_val,v*2, tl, tm);
        else
            update(pos,new_val,v*2+1, tm+1, tr);
        t[v] = max(t[v*2] , t[v*2+1]);
    }
}
void solve(){
  cin>>n;
  rep(i,1,n)cin>>h[i];
  rep(i,1,n)cin>>a[i];
  rep(i,1,n){
    // rep(total_beauty,0,h[i]-1)
    //   dp[h[i]]=max(dp[h[i]],dp[total_beauty]+a[i]);
    dp[h[i]]=sum(0,h[i]-1)+a[i];
    update(h[i],dp[h[i]]);
  }
  cout<<sum(1,n);
}
int32_t main()
{
  ibs;cti;
  solve()
  /*,cout<<"\n"*/;
  // cout<<"\n";
  int xx=0;
  // int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<":\n"*/;solve();cout<<"\n";}
  return 0;
}