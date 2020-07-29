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
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=3e5+10;
const int inf = 0x3f3f3f3f;
// const ll M = 998244353 ; // Mulo
const ll M = 1e9+7 ; // Mulo
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
        t[v] = t[v*2] + t[v*2+1];
    }
}
//queries
int sum(int l, int r,int v=1, int tl=1, int tr=n ) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    int x,y;
    x=sum( l, min(r, tm),v*2, tl, tm);
    y=sum(max(l, tm+1), r,v*2+1, tm+1, tr );
    if(x==0 and y==0)return t[v];
    return max(x,y);
}
//update
void update(int L,int R,int win,int v=1, int tl=1, int tr=n ) {
    if(L>tr or R<tl or tr<tl)return;
    if(t[v]!=0)return;
    if(tl>=L and tr<=R){t[v]=win;return;}
    int tm = (tl + tr) >> 1;
    update(L,R,win,v*2, tl, tm);
    update(L,R,win,v*2+1, tm+1, tr);
}
int m,l,r,w;
void solve(){
  cin>>n>>m;
  for (int i = 0; i < m; ++i)
  {
    cin>>l>>r>>w;
    update(l,w-1,w);
    update(w+1,r,w);
  }
  for (int i = 1; i <= n; ++i)
  {
    cout<<sum(i,i)<<" ";
  }
}
int main()
{
  ibs;cti;
  solve(),cout<<"\n";
  // int t;cin>>t;
  // while(t--){solve();cout<<"\n";}
  return 0;
}