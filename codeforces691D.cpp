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
const int N=1e6+10;
const int inf = /*0x3f3f3f3f*/1e15;
// const ll M = 998244353 ; // Mulo
const int M = 1e9+7 ; // Mulo
#define F first
#define S second
int n,k,m,x,y,a[N];vector<int>v[N];
bool cmp(int A,int B){
  return a[A]<a[B];
}
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
void solve(){
  cin>>n>>m;
  for(int i=1;i<=n;i++){cin>>a[i],make_set(i);}
  for(int i=1;i<=m;i++){
    cin>>x>>y;
    union_sets(x,y);
  }
  set<int>s;
  for(int i=1;i<=n;i++){
    v[find_set(i)].pb(i);
    s.insert(find_set(i));
  }
  for(auto S:s){
    priority_queue<int>q;
    for(auto i:v[S])q.push(a[i]);
    for(auto i:v[S]){
      a[i]=q.top();q.pop();
    }
  }
  for(int i=1;i<=n;i++)cout<<a[i]<<" ";
}
int32_t main()
{
  ibs;cti;
  solve()/*,cout<<"\n"*/;
  int x=0;
  // int t;cin>>t;while(t--){/*x++;cout<<"Case #"<<x<<": ";*/solve();cout<<"\n";}
  return 0;
}