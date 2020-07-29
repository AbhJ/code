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
#define double long double
#define int long long int
#define ll int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=1e6+10;
const int inf = /*0x3f3f3f3f*/1e9;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int n,m,x,y,w,F[N],ans;vector<pair<int,pair<int,int>>>a;pair<int,int>q[N];
int parent[N],ind[N];
int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
void make_set(int v) {
    parent[v] = v;
    ind[v] = 1;
}
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (ind[a] < ind[b])
            swap(a, b);
        parent[b] = a;
        ans+=ind[a]*ind[b];
        ind[a]+=ind[b];
    }
}
void f(){
  cin>>x>>y>>w;
  a.pb({w,{x,y}});
}
void solve(){
  cin>>n>>m;make_set(n);
  for(int i=1;i<=n-1;i++)f(),make_set(i);
  for(int i=1;i<=m;i++)cin>>q[i].F,q[i].S=i;
  sort(a.begin(), a.end());sort(q+1,q+1+m);
  auto v=a.begin();
  for(int i=1;i<=m;i++){
    while(v!=a.end() and q[i].F>=(*v).F)
      union_sets((*v).S.F,(*v).S.S),v++;
    F[q[i].S]=ans;
  }
  for(int i=1;i<=m;i++)cout<<F[i]<<" ";
}
int32_t main()
{
  // ibs;cti;
  solve()
  /*,cout<<"\n"*/;
  // cout<<"\n";
  int xx=0;
  // int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<":\n"*/;solve();/*cout<<"\n";*/}
  return 0;
}