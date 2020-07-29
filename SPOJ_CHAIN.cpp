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
// #define int long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=2e5+10;
const int inf = /*0x3f3f3f3f*/1e9;
// const ll M = 998244353 ; // Mulo
const int M = 1e9+7 ; // Mulo
#define F first
#define S second
int n,m,suor,x,y,parent[N],eat[N];
int find_set(int v) {
    if (v == parent[v])
        return v;
    int par=parent[v];
    parent[v]=find_set(parent[v]);
    eat[v]+=eat[par];
    return parent[v];
}
void make_set(int v) {
    parent[v] = v;
    eat[v]=0;
}
// void union_sets(int a, int b) {
//     a = find_set(a);
//     b = find_set(b);
//     if (a != b) {
//         if (ind[a] < ind[b])
//             swap(a, b);
//         parent[b] = a;
//     }
// }
void solve(){
  cin>>n>>m;memset(parent,0,sizeof parent);
  memset(eat,0,sizeof eat);
  for(int i=1;i<=n;i++)make_set(i);
  int ans=0;
  while(m--){
    cin>>suor>>x>>y;
    if(x>n or y>n){ans++;continue;}
    suor--;
    int X=find_set(x),Y=find_set(y),Z;
    if(X==Y){
      Z=(eat[x]-eat[y])%3;
      if(Z<0)Z+=3;
      if(Z!=suor)ans++;
    }
    else{
      parent[X]=Y;
      Z=(eat[x]-eat[y]-suor)%3;
      if(Z<0)eat[X]=-Z;
      else eat[X]=3-Z;
    }
  }
  cout<<ans;
}
int32_t main()
{
  ibs;cti;
  // solve()
  /*,cout<<"\n"*/;
  int x=0;
  int t;cin>>t;while(t--){/*x++;cout<<"Case #"<<x<<": ";*/solve();cout<<"\n";}
  return 0;
}