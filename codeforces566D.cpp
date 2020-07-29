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
const int inf = /*0x3f3f3f3f*/1e15;
// const ll M = 998244353 ; // Mulo
const int M = 1e9+7 ; // Mulo
#define F first
#define S second
int n,q,x,y,z,parent[N],nex[N],ind[N];
int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
void make_set(int v) {
    parent[v] = v;
    nex[v]=v+1;
    // ind[v] = rand();
}
void union_sets(int a, int b) {
    nex[a]=nex[b];
    a = find_set(a);
    b = find_set(b);
    // if (a != b) {
        // if (ind[a] < ind[b])
        //     swap(a, b);
        // nex[a]=nex[b];
        parent[a] = b;
    // }
}
void unio(int a,int b){
  a=find_set(a);
  b=find_set(b);
  if(a!=b)parent[a]=b;
}
void solve(){
  cin>>n>>q;
  for(int i=1;i<=n;i++)make_set(i);
  for(int i=1;i<=q;i++){
    cin>>x>>y>>z;
    if(x==3){
      if(find_set(y) == find_set(z))cout<<"YES\n";
      else cout<<"NO\n";
    }
    if(x==2){
      for(int i=y;i<=z;){
        int I=i;
        i=nex[i];
        union_sets(I,z);
      }
    }
    if(x==1){
      unio(y,z);
    }
  }
}
int32_t main()
{
  ibs;cti;
  solve()/*,cout<<"\n"*/;
  int x=0;
  // int t;cin>>t;while(t--){/*x++;cout<<"Case #"<<x<<": ";*/solve();cout<<"\n";}
  return 0;
}