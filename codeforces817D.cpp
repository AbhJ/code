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
const int N=1e6+1;
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
        //we are removing two segments to get one
        // s.erase(s.find(ind[a]));
        // s.erase(s.find(ind[b]));
        // s.insert(ind[a]+ind[b]);
        ind[a]+=ind[b];
        parent[b] = a;
    }
}
int n,a[N];int ma,l[N],r[N];
int f(){
  stack<int>s;
  int ans=0;
  for(int i=0;i<n;i++){
    while(s.empty()==0 and a[s.top()]<=a[i])l[s.top()]=i-1,s.pop();
    s.push(i);
  }
  while(s.empty()==0)l[s.top()]=n-1,s.pop();
  for(int i=n-1;i>=0;i--){
    while(s.empty()==0 and a[s.top()]<a[i])r[s.top()]=i+1,s.pop();
    s.push(i);
  }
  while(s.empty()==0)r[s.top()]=0,s.pop();
  //l[i] is rightmost index such that in the range i to l[i], a[i] is strictly greatest
  //r[i] is leftmost index such that in range r[i] to i, a[i] is greatest (note:= not strictly)
  // for(int i=0;i<n;i++){
  //   cout<<r[i]<<" ";
  // }
  // cout<<"\n";
  for(int i=0;i<n;i++){
    ans+=a[i]*((l[i]-i+1)*(i-r[i]+1));
  }
  return ans;
}
void solve(){
  cin>>n;
  for(int i=0;i<=n-1;i++){
    cin>>a[i];
  }
  int ans=0;
  ans+=f();
  for(int i=0;i<n;i++){
    a[i]*=-1;
  }
  ans+=f();
  cout<<ans;
}
int32_t main()
{
  ibs;cti;
  solve(),cout<<"\n";
  int x=0;
  // int t;cin>>t;while(t--){solve();cout<<"\n";}
  return 0;
}