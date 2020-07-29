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
pair<int,pair<int,int>>a[N];
int parent[N],ind[N];
int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
void make_set(int v) {
    parent[v] = v;
    ind[v] = 0;
}
bool ok=0;int k;
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        // if (ind[a] < ind[b])
        //     swap(a, b);
        parent[b] = a;
        ind[a]+=ind[b];
        // ind[b]=0;
        if(ind[a]==k)ok=1;
    }
}
//using kruskals mst algorithm
int n,m,x,y,w,A[N],ans;
void solve(){
  cin>>n>>m>>k;
  for(int i=1;i<=k;i++)cin>>A[i];
  for(int i=1;i<=m;i++){
    cin>>x>>y>>w;
    a[i]={w,{x,y}};
  }
  sort(a+1,a+1+m);
  for(int i=1;i<=n;i++)parent[i]=i;
  for(int i=1;i<=k;i++)ind[A[i]]=1;
  for(int i=1;i<=m;i++){
    int x=a[i].S.F,y=a[i].S.S,w=a[i].F;
    ans=max(ans,w);
    union_sets(x,y);
    if(ok==1){break;}
  }
  for(int i=1;i<=k;i++)cout<<ans<<" ";
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