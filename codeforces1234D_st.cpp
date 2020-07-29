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
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=1e5+10;
const int inf = 0x3f3f3f3f;
// const ll M = 998244353 ; // Mulo
const ll M = 1e9+7 ; // Mulo
#define F first
#define S second
int n, t[4*N],num[30];string s;
void pushup(int x){
  t[x]=t[2*x+1]|t[2*x];
}
//building the tree
void build(int v=1, int tl=1, int tr=n) {
    if (tl == tr) {
        t[v]=1<<((char)s[tl]-'a');return;
    } else {
        int tm = (tl + tr) / 2;
        /*if(pos<=tm)*/build(v*2, tl, tm);
        /*else*/ build(v*2+1, tm+1, tr);
        //
        pushup(v);
    }
}
//queries
int sum(int l,int r, int v=1,int tl=1, int tr=n ) {
    if(l>tr or r<tl)return 0;
    if(tl>=l and tr<=r){
      return t[v];
    }
    int tm = (tl + tr) / 2;
    return sum( l, r,v*2, tl, tm) | sum(l, r,v*2+1, tm+1, tr );
}
//update
void update(int pos, char c,int v=1, int tl=1, int tr=n ) {
    if(tl==tr){
      t[v]=1<<(c-'a');
      return;
    }
    int tm = (tl + tr) / 2;
    if(tm>=pos) update( pos,c,v*2, tl, tm);
    else update(pos,c,v*2+1, tm+1, tr );
    pushup(v);
}
int m,p,v;
void solve(){
  cin>>s>>m;
  n=s.length();
  s='#'+s;
  build();
  while(m--){
    int x,l;cin>>x>>l;
    if(x==2){
      int r;cin>>r;
      int c=0;
      int z=sum(l,r);
      while(z){
        if(z&1)c++;z/=2;
      }
      cout<<c<<"\n";
    }
    else {
      char c;cin>>c;
      update(l,c);
    }
  }
}
int main()
{
  // ibs;cti;
  solve()/*,cout<<"\n"*/;
  // int t;cin>>t;
  // while(t--){solve();cout<<"\n";}
  return 0;
}