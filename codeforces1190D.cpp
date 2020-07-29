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
int n,x,x1,y,l,r,ans;map<int,multiset<int>>X;set<int>q;
map<int,int>tree,us;
//building the tree
void add(int v) {
    if (us[v] == 1) return;
    us[v] = 1;
    for (; v < inf; v |= v + 1)
        tree[v] += 1;
}
 
int get_sum(int v) {
    int res = 0;
    for (; v >= 0; v = (v & (v + 1)) - 1)
        res += tree[v];
    return res;
}
void solve(){
  cin>>n;
  for(int i=1;i<=n;i++){
    cin>>x>>y;
    q.insert(y);
    X[y].insert(x);
  }
  for(auto I=q.rbegin();I!=q.rend();I++){
    y=*I;
    auto Z=X[y];
    Z.insert(inf);
    x=x1=0;
    for(auto J=Z.begin();x1!=inf;J=next(J)){
      x=*J;
      x1=*(next(J));
      // cout<<x<<" "<<x1<<"\n";
      add(x);
      l=get_sum(x);
      r=get_sum(x1-1)-l+1;
      ans+=l*r;
    }
  }
  cout<<ans;
}
int32_t main()
{
  // ibs;cti;
  solve()
  /*,cout<<"\n"*/;
  // cout<<"\n";
  int xx=0;
  // int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<":\n"*/;solve();/*cout<<"\n";*/}
  return 0;
}