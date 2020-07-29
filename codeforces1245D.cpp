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
const int N=2e3+10;
const int inf = /*0x3f3f3f3f*/1e9+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int n,a[N][2],B[N],A[N],ans;vector<pair<int,pair<int,int>>>e;
vector<pair<int,int>>c;vector<int>g;
int parent[N],ind[N];
int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
void make_set(int v) {
    parent[v] = v;
    ind[v] = rand();
}
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (ind[a] < ind[b])
            swap(a, b);
        parent[b] = a;
    }
}
int f(int i,int j){
  return (abs(a[i][0]-a[j][0])+abs(a[i][1]-a[j][1]))*(B[i]+B[j]);
}
void solve(){
  cin>>n;
  for(int i=1;i<=n;i++)cin>>a[i][0]>>a[i][1];
  for(int i=1;i<=n;i++)cin>>A[i];
  for(int i=1;i<=n;i++)cin>>B[i];
  for(int i=0;i<=n;i++)make_set(i);
  //creating dummy variable 0 and pushing edges
  for(int i=1;i<=n;i++){
    e.pb({A[i],{0,i}});
  }
  for(int i=1;i<=n;i++){
    for(int j=i+1;j<=n;j++)
      e.pb({f(i,j),{i,j}});
  }
  sort(e.begin(),e.end());
  for(auto i:e){
    if(find_set(i.S.F)!=find_set(i.S.S)){
      ans+=i.F;
      if(i.S.F==0)g.pb(i.S.S);
      else c.pb(i.S);
      union_sets(i.S.F,i.S.S);
    }
  }
  cout<<ans<<"\n"<<g.size()<<"\n";
  for(auto i:g)cout<<i<<" ";
  cout<<"\n"<<c.size()<<"\n";
  for(auto i:c)cout<<i.F<<" "<<i.S<<" \n";
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