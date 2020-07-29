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
const int N=5e5+10;
const int inf = /*0x3f3f3f3f*/1e15;
// const ll M = 998244353 ; // Mulo
const int M = 1e9+7 ; // Mulo
#define F first
#define S second
int n, t[4*N];
// bool operator <(pair<int,pair<int,int>> a, pair<int,pair<int,int>> b ) {
//     if ( a.F == b.F ) {
//         return a.S.S > b.S.S;
//     }
//     return a.F > b.F;
// }
// //building the tree
// void build(int a[], int v=1, int tl=1, int tr=n) {
//     if (tl == tr) {
//         t[v] = a[tl];
//     } else {
//         int tm = (tl + tr) / 2;
//         build(a, v*2, tl, tm);
//         build(a, v*2+1, tm+1, tr);
//         t[v] = t[v*2] + t[v*2+1];
//     }
// }
//queries
int sum(int l, int r,int v=1, int tl=1, int tr=n ) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    return sum( l, min(r, tm),v*2, tl, tm)
           + sum(max(l, tm+1), r,v*2+1, tm+1, tr );
}
//
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
int q,ans[N];pair<int,pair<int,int>>a[N];
void solve(){
  cin>>n;
  map<pair<int,pair<int,int>>,int>m;
  for(int i=1;i<=n;i++){
    cin>>a[i].F;a[i].S.S=i;
    a[i].S.F=-1;
  }
  cin>>q;
  for(int i=n+1;i<=n+q;i++){
    int l,r,k;
    cin>>l>>r>>k;
    a[i]={k,{r,l}};
    m[{k,{r,l}}]=i;
  }
  sort(a+1,a+1+n+q);
  reverse(a+1,a+1+n+q);
  for(int i=1;i<=n+q;i++){
    int l=a[i].S.S,r=a[i].S.F,k=a[i].F;
    if(r==-1)update(l,1);
    else ans[m[{k,{r,l}}]]=sum(l,r);
  }
  for(int i=n+1;i<=n+q;i++)cout<<ans[i]<<"\n";
}
int32_t main()
{
  ibs;cti;
  solve()/*,cout<<"\n"*/;
  int x=0;
  // int t;cin>>t;while(t--){/*x++;cout<<"Case #"<<x<<": ";*/solve();cout<<"\n";}
  return 0;
}