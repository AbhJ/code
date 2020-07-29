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
const int N=2e5+10;
const int inf = /*0x3f3f3f3f*/1e9;
// const ll M = 998244353 ; // Mulo
const int M = 1e9+7 ; // Mulo
#define F first
#define S second
int n, t[4*N];
//building the tree
void build(int a[], int v=1, int tl=1, int tr=n) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = min( t[v*2] , t[v*2+1]);
    }
}
//queries
int sum(int l, int r,int v=1, int tl=1, int tr=n ) {
    if (l > r) 
        return inf;
    if (l == tl && r == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    return min(sum( l, min(r, tm),v*2, tl, tm)
           , sum(max(l, tm+1), r,v*2+1, tm+1, tr ));
}
//
void update(int pos, int new_val,int v=1, int tl=1, int tr=n ) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(pos,new_val,v*2, tl, tm);
        else
            update(pos,new_val,v*2+1, tm+1, tr);
        t[v] = t[v*2] + t[v*2+1];
    }
}
int a[N],q,l,r;
void solve(){
  cin>>n;
  for(int i=1;i<=n;i++)cin>>a[i];
  cin>>q;build(a);
  while(q--){
    cin>>l>>r;
    cout<<sum(l+1,r+1)<<"\n";
  }
}
int32_t main()
{
  ibs;cti;
  solve()
  /*,cout<<"\n"*/;
  int xx=0;
  // int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<":\n"*/;solve();/*cout<<"\n";*/}
  return 0;
} 