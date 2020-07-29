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
#define int long long int
#define ll long long int8_t
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
int parent[N],ind[N];
int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
int powM(int b, int p) {
  int r=1;
  for(; p; b=b*b%M, p/=2)
    if(p&1)
      r=r*b%M;
  return r;
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
int n,m,k;
void solve(){
  cin>>n>>m>>k;
  for(int i=1;i<=n;i++)make_set(i);
  for(int i=1;i<=n-k+1;i++){
    int l=i,r=i+k-1;
    while(l<r){
      union_sets(l++,r--);
    }
  }
  set<int>s;
  for(int i=1;i<=n;i++)s.insert(find_set(i));
  cout<<powM(m,s.size());
}
int32_t main()
{
  ibs;cti;
  solve(),cout<<"\n";
  // int t;cin>>t;while(t--){solve();cout<<"\n";}
  // int x=0;
  return 0;
}