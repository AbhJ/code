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
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=2e5+10;
const int inf = /*0x3f3f3f3f*/1e9;
// const ll M = 998244353 ; // Mulo
const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int n,m,x,y,w,parent[N],ind[N],a[N],ans;vector<pair<int,pair<int,int>>>e;
int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
void make_set(int v) {
    parent[v] = v;
    ind[v] = rand();
}
void union_sets(pair<int,pair<int,int>> A) {
    int a=A.S.F,b=A.S.S,w=A.F;
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (ind[a] < ind[b])
            swap(a, b);
        parent[b] = a;
        ans+=w;
    }
}
void solve(){
  cin>>n>>m;
  for(int i=1;i<=n;i++)cin>>a[i],make_set(i);
  int c=min_element(a+1,a+1+n)-a;
  for(int i=1;i<=m;i++){
    cin>>x>>y>>w;
    e.pb({w,{x,y}});
  }
  for(int i=1;i<=n;i++){
    if(i!=c)
      e.pb({a[i]+a[c],{c,i}});
  }
  sort(e.begin(), e.end());
  for(auto i:e) union_sets(i);
  cout<<ans;
}
int32_t main()
{
  ibs;cti;
  solve()
  /*,cout<<"\n"*/;
  // cout<<"\n";
  int xx=0;
  // int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<":\n"*/;solve();/*cout<<"\n";*/}
  return 0;
}