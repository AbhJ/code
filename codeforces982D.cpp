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
const int N=1e5+1;
const int inf = /*0x3f3f3f3f*/1e15;
// const ll M = 998244353 ; // Mulo
const int M = 1e9+7 ; // Mulo
#define F first
#define S second
int parent[N],ind[N];
multiset<int>s;
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
        s.erase(s.find(ind[a]));
        s.erase(s.find(ind[b]));
        s.insert(ind[a]+ind[b]);
        ind[a]+=ind[b];
        parent[b] = a;
    }
}
int n;pair<int,int>a[N];int ans,ma,b[N];
void solve(){
  cin>>n;
  for(int i=1;i<=n;i++){
    cin>>a[i].F;a[i].S=i;
    make_set(i);
  }
  sort(a+1,a+1+n);
  for(int i=1;i<=n;i++){
    int x=a[i].F,pos=a[i].S;
    b[pos]=1;
    s.insert(1);
    if(b[pos-1]==1)union_sets(pos,pos-1);
    //if we visited the previous position
    if(b[pos+1]==1)union_sets(pos,pos+1);
    //if we visited the next position
    //s has stored the sizes of all the segments we have
    if(*s.begin()==*s.rbegin() and ma<s.size()){
      ma=s.size(),ans=x+1;
    }
  }
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