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
#define pb emplace_back
#define koto_memory(a) cout<<(sizeof(a)/1048576.0)<<" MB";
#define res(v) sort(all(v)),v.erase(unique(all(v)), v.end());
#define timer cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
#define deb(x) cout<<"\n["<<#x<<" = "<<x<<"]\n";
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
const int N=2e5+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int n,m,x,y,val,l,r,A[N],B[N],en[N],ex[N],T,d[N],t[8*N],lazy[8*N];vi a[N];
void dfs(int u,int p=-1,int dep=0){
  en[u]=T++;d[u]=dep;
  for(auto i:a[u])if(i!=p){
    dfs(i,u,dep^1);
  }
  ex[u]=T++;
}
void f(int v,int tl,int tr){
  t[v]+=lazy[v];
  if(tl!=tr){
    lazy[v*2]+=lazy[v];
    lazy[v*2+1]+=lazy[v];
  }
  lazy[v]=0;
}
//queries
int sum(int l, int r,int v=1, int tl=0, int tr=2*n+10 ) {
    f(v,tl,tr);
    if (l>tr or r<tl) 
        return 0;
    if (l <= tl and r >= tr)
        return t[v];
    int tm = (tl + tr) / 2;
    return sum( l, r,v*2, tl, tm)
           + sum(l, r,v*2+1, tm+1, tr );
}
//
void update(int l, int r, int new_val,int v=1, int tl=0, int tr=2*n+10 ) {
   f(v,tl,tr);
   if(l>tr or r<tl)return;
   if(l<=tl and r>=tr){
    lazy[v]+=new_val;
    f(v,tl,tr);
    return;
   }
   int tm=tl+tr>>1;
   update(l,r,new_val,v*2,tl,tm);
   update(l,r,new_val,v*2+1,tm+1,tr);
   t[v]=t[v*2]+t[v*2+1];
}
void solve(){
  cin>>n>>m;
  rep(i,1,n)cin>>A[i];
  rep(i,1,n-1)cin>>x>>y,a[x].pb(y),a[y].pb(x);
  dfs(1);
  while(m--){
    cin>>y>>x;
    if(y==1){
      l=en[x],r=ex[x];
      cin>>val;
      if(d[x]){
        update(l,r,val);
      }
      if(d[x]^1){
        update(l,r,-val);
      }
    }
    if(y==2){
      l=en[x],r=ex[x];
      if(d[x]){
        cout<<A[x]+sum(l,l);
      }
      if(d[x]^1){
        cout<<A[x]-sum(l,l);
      }
      cout<<"\n";
    }
  }
}
int32_t main()
{
  ibs;cti;
  solve();return 0;
  /*,cout<<"\n"*/;
  // cout<<"\n";
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<":\n"*/;solve();cout<<"\n";}
  return 0;
}