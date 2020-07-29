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
void build(int a[],int level, int v=1, int tl=1, int tr=n) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a,level+1, v*2, tl, tm);
        build(a,level+1, v*2+1, tm+1, tr);
        if(level%2!=0)t[v] = t[v*2] | t[v*2+1];
        else t[v] = t[v*2] ^ t[v*2+1];
    }
}
//queries
int sum(int v=1,int level=0, int tl=1, int tr=n ) {
    // if (l > r) 
    //     return 0;
    // if (l == tl && r == tr)
        return t[v];
    // int tm = (tl + tr) / 2;
    // int x= sum( l, min(r, tm),v*2, tl, tm);
    // int y= sum(max(l, tm+1), r,v*2+1, tm+1, tr );
    // if(level%2!=0)return x|y;
    // else return x^y;
}
//update
void update(int pos, int new_val,int level,int v=1, int tl=1, int tr=n ) {
    // if(pos<tl or pos>tr)return;
    if (tl == tr) {
        t[v] = new_val;return;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(pos,new_val,level+1,v*2, tl, tm);
        else
            update(pos,new_val,level+1,v*2+1, tm+1, tr);
        if(level%2!=0)t[v] = t[v*2] | t[v*2+1];
        else t[v] = t[v*2] ^ t[v*2+1];
    }
}
int m,p,v,a[N];
void solve(){
  cin>>n>>m;
  int x=n%2;
  n=pow(2,n);
  for(int i=1;i<=n;i++)
    cin>>a[i];
  /*if(n%2)*/build(a,x);
    // else build(a,n+1);
  for (int i = 0; i < m; ++i,cout<<"\n")
  {
    cin>>p>>v;
    /*if(n%2)*/update(p,v,x);
    // else update(p,v,n+1);
    cout<<sum();
  }
}
int main()
{
  ibs;cti;
  solve()/*,cout<<"\n"*/;
  // int t;cin>>t;
  // while(t--){solve();cout<<"\n";}
  return 0;
}