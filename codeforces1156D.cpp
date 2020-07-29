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
const int inf = /*0x3f3f3f3f*/1e9+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int parent[2][N],ind[2][N],ans;
int find_set(int v,int c) {
    if (v == parent[c][v])
        return v;
    return parent[c][v] = find_set(parent[c][v],c);
}
void make_set(int v) {
    parent[0][v] =parent[1][v]= v;
    ind[0][v] = ind[1][v]=1;
}
void union_sets(int a, int b,int c) {
    a = find_set(a,c);
    b = find_set(b,c);
    if (a != b) {
        parent[c][b] = a;
        // ans+=ind[c][a]*ind[c][b];
        ind[c][a]+=ind[c][b];
    }
}
int x,n,y,w;
void solve(){
  cin>>n;
  for(int i=1;i<=n;i++)make_set(i);
  for(int i=1;i<=n-1;i++){
    cin>>x>>y>>w;
    union_sets(x,y,w);
  }
  for(int i=1;i<=n;i++){
    ans+=ind[0][find_set(i,0)]*ind[1][find_set(i,1)]-1;
  }
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