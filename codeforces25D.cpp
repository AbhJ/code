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
const int N=2e3+10;
const int inf = /*0x3f3f3f3f*/1e9;
// const ll M = 998244353 ; // Mulo
const int M = 1e9+7 ; // Mulo
#define F first
#define S second
int n,x,y,parent[N],ind[N];vector<pair<int,int>>f,F;
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
    int A=a,B=b;
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (ind[a] < ind[b])
            swap(a, b);
        parent[b] = a;
    }
    else f.pb({A,B});
}
void solve(){
  cin>>n;
  for(int i=1;i<=n;i++)make_set(i);
  for(int i=1;i<=n-1;i++){
    cin>>x>>y;
    union_sets(x,y);
  }
  for(int i=1;i<=n;i++)
    for(int j=i+1;j<=n;j++)
      if(find_set(i)!=find_set(j)){
        union_sets(i,j);
        F.pb({i,j});
      }
  cout<<min(F.size(),f.size())<<"\n";
  for(int i=0;i<min(F.size(),f.size());i++)
    cout<<f[i].F<<" "<<f[i].S<<" "<<F[i].F<<" "<<F[i].S<<"\n";
}
int32_t main()
{
  ibs;cti;
  solve()
  /*,cout<<"\n"*/;
  int x=0;
  // int t;cin>>t;while(t--){/*x++;cout<<"Case #"<<x<<": ";*/solve();cout<<"\n";}
  return 0;
}