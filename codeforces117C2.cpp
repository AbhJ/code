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
const int N=5e5+10;
const int inf = /*0x3f3f3f3f*/1e15;
// const ll M = 998244353 ; // Mulo
const int M = 1e9+7 ; // Mulo
#define F first
#define S second
int n,k,m,f[N],cnt[N];vector<int>a[N];
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
  cin>>n>>k;
  for(int i=1;i<=n;i++){
    make_set(i);
  }
  for(int i=1;i<=k;i++){
    int x,y;
    cin>>x>>y;
    union_sets(x,y);
  }
  cin>>m;
  set<int>s;
  for(int i=1;i<=n;i++){
    s.insert(find_set(i));cnt[find_set(i)]++;
  }
  //cnt counts component size
  vector<int>v(s.size());
  int ma=0;
  for(int i=1;i<=m;i++){
    int x,y;
    cin>>x>>y;
    if(find_set(x)==find_set(y))f[find_set(x)]=1;
    // for(int j=1;j<=n;j++){
    //   if(find)
    // }
  }
  //if there is distrust in a component we leave it
  for(auto i:s){
    if(f[i]==0){
      ma=max(cnt[i],ma);
    }
  }
  cout<<ma;
}
int32_t main()
{
  ibs;cti;
  solve()/*,cout<<"\n"*/;
  int x=0;
  // int t;cin>>t;while(t--){/*x++;cout<<"Case #"<<x<<": ";*/solve();cout<<"\n";}
  return 0;
}